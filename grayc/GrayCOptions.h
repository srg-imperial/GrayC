//===--- GrayCOptions.h - grayc ------------------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GrayCOptions_H
#define GRAYC_GrayCOptions_H

#include "Compatability.h"
#include "llvm/ADT/IntrusiveRefCntPtr.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/ErrorOr.h"
#include "llvm/Support/VirtualFileSystem.h"
#include <functional>
#include <map>
#include <string>
#include <system_error>
#include <utility>
#include <vector>

namespace clang {
namespace grayc {

/// Contains a list of line ranges in a single file.
struct FileFilter {
  /// File name.
  std::string Name;

  /// LineRange is a pair<start, end> (inclusive).
  typedef std::pair<unsigned, unsigned> LineRange;

  /// A list of line ranges in this file, for which we show warnings.
  std::vector<LineRange> LineRanges;
};

/// Global options. These options are neither stored nor read from
/// configuration files.
struct GrayCGlobalOptions {
  /// Output warnings from certain line ranges of certain files only.
  /// If empty, no warnings will be filtered.
  std::vector<FileFilter> LineFilter;
};

/// Contains options for grayc. These options may be read from
/// configuration files, and may be different for different translation units.
struct GrayCOptions {
  /// These options are used for all settings that haven't been
  /// overridden by the \c OptionsProvider.
  ///
  /// Allow no checks and no headers by default. This method initializes
  /// check-specific options by calling \c GrayCModule::getModuleOptions()
  /// of each registered \c GrayCModule.
  static GrayCOptions getDefaults();

  /// Creates a new \c GrayCOptions instance combined from all fields
  /// of this instance overridden by the fields of \p Other that have a value.
  /// \p Order specifies precedence of \p Other option.
  GrayCOptions mergeWith(const GrayCOptions &Other,
                             unsigned Order) const;

  /// Checks filter.
  OPTIONAL(std::string) Checks;

  /// WarningsAsErrors filter.
  OPTIONAL(std::string) WarningsAsErrors;

  /// Output warnings from headers matching this filter. Warnings from
  /// main files will always be displayed.
  OPTIONAL(std::string) HeaderFilterRegex;

  /// Output warnings from system headers matching \c HeaderFilterRegex.
  OPTIONAL(bool) SystemHeaders;

  /// Format code around applied fixes with clang-format using this
  /// style.
  ///
  /// Can be one of:
  ///   * 'none' - don't format code around applied fixes;
  ///   * 'llvm', 'google', 'mozilla' or other predefined clang-format style
  ///     names;
  ///   * 'file' - use the .clang-format file in the closest parent directory of
  ///     each source file;
  ///   * '{inline-formatting-style-in-yaml-format}'.
  ///
  /// See clang-format documentation for more about configuring format style.
  OPTIONAL(std::string) FormatStyle;

  /// Specifies the name or e-mail of the user running grayc.
  ///
  /// This option is used, for example, to place the correct user name in TODO()
  /// comments in the relevant check.
  OPTIONAL(std::string) User;

  // Specifies the seed to be used during mutations
  OPTIONAL(long) Seed;
  
  /// Helper structure for storing option value with priority of the value.
  struct GrayCValue {
    GrayCValue() : Value(), Priority(0) {}
    GrayCValue(const char *Value) : Value(Value), Priority(0) {}
    GrayCValue(llvm::StringRef Value, unsigned Priority = 0)
        : Value(Value), Priority(Priority) {}

    std::string Value;
    /// Priority stores relative precedence of the value loaded from config
    /// files to disambigute local vs global value from different levels.
    unsigned Priority;
  };
  typedef std::pair<std::string, std::string> StringPair;
  typedef std::map<std::string, GrayCValue> OptionMap;

  /// Key-value mapping used to store check-specific options.
  OptionMap CheckOptions;

  typedef std::vector<std::string> ArgList;

  /// Add extra compilation arguments to the end of the list.
  OPTIONAL(ArgList) ExtraArgs;

  /// Add extra compilation arguments to the start of the list.
  OPTIONAL(ArgList) ExtraArgsBefore;

  /// Only used in the FileOptionsProvider and ConfigOptionsProvider. If true
  /// and using a FileOptionsProvider, it will take a configuration file in the
  /// parent directory (if any exists) and apply this config file on top of the
  /// parent one. IF true and using a ConfigOptionsProvider, it will apply this
  /// config on top of any configuation file it finds in the directory using the
  /// same logic as FileOptionsProvider. If false or missing, only this
  /// configuration file will be used.
  OPTIONAL(bool) InheritParentConfig;

  /// Use colors in diagnostics. If missing, it will be auto detected.
  OPTIONAL(bool) UseColor;
};

/// Abstract interface for retrieving various GrayC options.
class GrayCOptionsProvider {
public:
  static const char OptionsSourceTypeDefaultBinary[];
  static const char OptionsSourceTypeCheckCommandLineOption[];
  static const char OptionsSourceTypeConfigCommandLineOption[];

  virtual ~GrayCOptionsProvider() {}

  /// Returns global options, which are independent of the file.
  virtual const GrayCGlobalOptions &getGlobalOptions() = 0;

  /// GrayCOptions and its source.
  //
  /// grayc has 3 types of the sources in order of increasing priority:
  ///    * grayc binary.
  ///    * '-config' commandline option or a specific configuration file. If the
  ///       commandline option is specified, grayc will ignore the
  ///       configuration file.
  ///    * '-checks' commandline option.
  typedef std::pair<GrayCOptions, std::string> OptionsSource;

  /// Returns an ordered vector of OptionsSources, in order of increasing
  /// priority.
  virtual std::vector<OptionsSource>
  getRawOptions(llvm::StringRef FileName) = 0;

  /// Returns options applying to a specific translation unit with the
  /// specified \p FileName.
  GrayCOptions getOptions(llvm::StringRef FileName);
};

/// Implementation of the \c GrayCOptionsProvider interface, which
/// returns the same options for all files.
class DefaultOptionsProvider : public GrayCOptionsProvider {
public:
  DefaultOptionsProvider(const GrayCGlobalOptions &GlobalOptions,
                         const GrayCOptions &Options)
      : GlobalOptions(GlobalOptions), DefaultOptions(Options) {}
  const GrayCGlobalOptions &getGlobalOptions() override {
    return GlobalOptions;
  }
  std::vector<OptionsSource> getRawOptions(llvm::StringRef FileName) override;

private:
  GrayCGlobalOptions GlobalOptions;
  GrayCOptions DefaultOptions;
};

class FileOptionsBaseProvider : public DefaultOptionsProvider {
public:
  // A pair of configuration file base name and a function parsing
  // configuration from text in the corresponding format.
  typedef std::pair<std::string, std::function<llvm::ErrorOr<GrayCOptions>(
                                     llvm::StringRef)>>
      ConfigFileHandler;

  /// Configuration file handlers listed in the order of priority.
  ///
  /// Custom configuration file formats can be supported by constructing the
  /// list of handlers and passing it to the appropriate \c FileOptionsProvider
  /// constructor. E.g. initialization of a \c FileOptionsProvider with support
  /// of a custom configuration file format for files named ".my-grayc-config"
  /// could look similar to this:
  /// \code
  /// FileOptionsProvider::ConfigFileHandlers ConfigHandlers;
  /// ConfigHandlers.emplace_back(".my-grayc-config", parseMyConfigFormat);
  /// ConfigHandlers.emplace_back(".grayc", parseConfiguration);
  /// return std::make_unique<FileOptionsProvider>(
  ///     GlobalOptions, DefaultOptions, OverrideOptions, ConfigHandlers);
  /// \endcode
  ///
  /// With the order of handlers shown above, the ".my-grayc-config" file would
  /// take precedence over ".grayc" if both reside in the same directory.
  typedef std::vector<ConfigFileHandler> ConfigFileHandlers;

  FileOptionsBaseProvider(
      const GrayCGlobalOptions &GlobalOptions,
      const GrayCOptions &DefaultOptions,
      const GrayCOptions &OverrideOptions,
      llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> FS = nullptr);

  FileOptionsBaseProvider(const GrayCGlobalOptions &GlobalOptions,
                          const GrayCOptions &DefaultOptions,
                          const GrayCOptions &OverrideOptions,
                          const ConfigFileHandlers &ConfigHandlers);

protected:
  void addRawFileOptions(llvm::StringRef AbsolutePath,
                         std::vector<OptionsSource> &CurOptions);

  /// Try to read configuration files from \p Directory using registered
  /// \c ConfigHandlers.
  OPTIONAL(OptionsSource) tryReadConfigFile(llvm::StringRef Directory);

  llvm::StringMap<OptionsSource> CachedOptions;
  GrayCOptions OverrideOptions;
  ConfigFileHandlers ConfigHandlers;
  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> FS;
};

/// Implementation of GrayCOptions interface, which is used for
/// '-config' command-line option.
class ConfigOptionsProvider : public FileOptionsBaseProvider {
public:
  ConfigOptionsProvider(
      const GrayCGlobalOptions &GlobalOptions,
      const GrayCOptions &DefaultOptions,
      const GrayCOptions &ConfigOptions,
      const GrayCOptions &OverrideOptions,
      llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> FS = nullptr);
  std::vector<OptionsSource> getRawOptions(llvm::StringRef FileName) override;

private:
  GrayCOptions ConfigOptions;
};

/// Implementation of the \c GrayCOptionsProvider interface, which
/// tries to find a configuration file in the closest parent directory of each
/// source file.
///
/// By default, files named ".grayc" will be considered, and the
/// \c clang::grayc::parseConfiguration function will be used for parsing, but a
/// custom set of configuration file names and parsing functions can be
/// specified using the appropriate constructor.
class FileOptionsProvider : public FileOptionsBaseProvider {
public:
  /// Initializes the \c FileOptionsProvider instance.
  ///
  /// \param GlobalOptions are just stored and returned to the caller of
  /// \c getGlobalOptions.
  ///
  /// \param DefaultOptions are used for all settings not specified in a
  /// configuration file.
  ///
  /// If any of the \param OverrideOptions fields are set, they will override
  /// whatever options are read from the configuration file.
  FileOptionsProvider(
      const GrayCGlobalOptions &GlobalOptions,
      const GrayCOptions &DefaultOptions,
      const GrayCOptions &OverrideOptions,
      llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> FS = nullptr);

  /// Initializes the \c FileOptionsProvider instance with a custom set
  /// of configuration file handlers.
  ///
  /// \param GlobalOptions are just stored and returned to the caller of
  /// \c getGlobalOptions.
  ///
  /// \param DefaultOptions are used for all settings not specified in a
  /// configuration file.
  ///
  /// If any of the \param OverrideOptions fields are set, they will override
  /// whatever options are read from the configuration file.
  ///
  /// \param ConfigHandlers specifies a custom set of configuration file
  /// handlers. Each handler is a pair of configuration file name and a function
  /// that can parse configuration from this file type. The configuration files
  /// in each directory are searched for in the order of appearance in
  /// \p ConfigHandlers.
  FileOptionsProvider(const GrayCGlobalOptions &GlobalOptions,
                      const GrayCOptions &DefaultOptions,
                      const GrayCOptions &OverrideOptions,
                      const ConfigFileHandlers &ConfigHandlers);

  std::vector<OptionsSource> getRawOptions(llvm::StringRef FileName) override;
};

/// Parses LineFilter from JSON and stores it to the \p Options.
std::error_code parseLineFilter(llvm::StringRef LineFilter,
                                GrayCGlobalOptions &Options);

/// Parses configuration from JSON and returns \c GrayCOptions or an
/// error.
llvm::ErrorOr<GrayCOptions> parseConfiguration(llvm::StringRef Config);

/// Serializes configuration to a YAML-encoded string.
std::string configurationAsText(const GrayCOptions &Options);

} // end namespace grayc
} // end namespace clang

#endif // GRAYC_GrayCOptions_H
