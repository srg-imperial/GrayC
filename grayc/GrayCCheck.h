//===--- GrayCCheck.h - grayc --------------------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GrayCCheck_H
#define GRAYC_GrayCCheck_H

#include "GrayCDiagnosticConsumer.h"
#include "GrayCOptions.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Basic/Diagnostic.h"
#include "llvm/ADT/Optional.h"
#include "llvm/Support/Error.h"
#include <type_traits>
#include <utility>
#include <vector>

namespace clang {

class CompilerInstance;
class SourceManager;

namespace grayc {

/// This class should be specialized by any enum type that needs to be converted
/// to and from an \ref llvm::StringRef.
template <class T> struct OptionEnumMapping {
  // Specializations of this struct must implement this function.
  static ArrayRef<std::pair<T, StringRef>> getEnumMapping() = delete;
};

template <typename T> class OptionError : public llvm::ErrorInfo<T> {
  std::error_code convertToErrorCode() const override {
    return llvm::inconvertibleErrorCode();
  }

public:
  void log(raw_ostream &OS) const override { OS << this->message(); }
};

class MissingOptionError : public OptionError<MissingOptionError> {
public:
  explicit MissingOptionError(std::string OptionName)
      : OptionName(OptionName) {}

  std::string message() const override;
  static char ID;
private:
  const std::string OptionName;
};

class UnparseableEnumOptionError
    : public OptionError<UnparseableEnumOptionError> {
public:
  explicit UnparseableEnumOptionError(std::string LookupName,
                                      std::string LookupValue)
      : LookupName(LookupName), LookupValue(LookupValue) {}
  explicit UnparseableEnumOptionError(std::string LookupName,
                                      std::string LookupValue,
                                      std::string SuggestedValue)
      : LookupName(LookupName), LookupValue(LookupValue),
        SuggestedValue(SuggestedValue) {}

  std::string message() const override;
  static char ID;

private:
  const std::string LookupName;
  const std::string LookupValue;
  const llvm::Optional<std::string> SuggestedValue;
};

class UnparseableIntegerOptionError
    : public OptionError<UnparseableIntegerOptionError> {
public:
  explicit UnparseableIntegerOptionError(std::string LookupName,
                                         std::string LookupValue,
                                         bool IsBoolean = false)
      : LookupName(LookupName), LookupValue(LookupValue), IsBoolean(IsBoolean) {
  }

  std::string message() const override;
  static char ID;

private:
  const std::string LookupName;
  const std::string LookupValue;
  const bool IsBoolean;
};

/// Base class for all grayc checks.
///
/// To implement a ``GrayCCheck``, write a subclass and override some of the
/// base class's methods. E.g. to implement a check that validates namespace
/// declarations, override ``registerMatchers``:
///
/// ~~~{.cpp}
/// void registerMatchers(ast_matchers::MatchFinder *Finder) override {
///   Finder->addMatcher(namespaceDecl().bind("namespace"), this);
/// }
/// ~~~
///
/// and then override ``check(const MatchResult &Result)`` to do the actual
/// check for each match.
///
/// A new ``GrayCCheck`` instance is created per translation unit.
///
/// FIXME: Figure out whether carrying information from one TU to another is
/// useful/necessary.
class GrayCCheck : public ast_matchers::MatchFinder::MatchCallback {
public:
  /// Initializes the check with \p CheckName and \p Context.
  ///
  /// Derived classes must implement the constructor with this signature or
  /// delegate it. If a check needs to read options, it can do this in the
  /// constructor using the Options.get() methods below.
  GrayCCheck(StringRef CheckName, GrayCContext *Context);

  /// Override this to disable registering matchers and PP callbacks if an
  /// invalid language version is being used.
  ///
  /// For example if a check is examining overloaded functions then this should
  /// be overridden to return false when the CPlusPlus flag is not set in
  /// \p LangOpts.
  virtual bool isLanguageVersionSupported(const LangOptions &LangOpts) const {
    return true;
  }

  /// Override this to register ``PPCallbacks`` in the preprocessor.
  ///
  /// This should be used for grayc checks that analyze preprocessor-
  /// dependent properties, e.g. include directives and macro definitions.
  ///
  /// This will only be executed if the function isLanguageVersionSupported
  /// returns true.
  ///
  /// There are two Preprocessors to choose from that differ in how they handle
  /// modular #includes:
  ///  - PP is the real Preprocessor. It doesn't walk into modular #includes and
  ///    thus doesn't generate PPCallbacks for their contents.
  ///  - ModuleExpanderPP preprocesses the whole translation unit in the
  ///    non-modular mode, which allows it to generate PPCallbacks not only for
  ///    the main file and textual headers, but also for all transitively
  ///    included modular headers when the analysis runs with modules enabled.
  ///    When modules are not enabled ModuleExpanderPP just points to the real
  ///    preprocessor.
  virtual void registerPPCallbacks(const SourceManager &SM, Preprocessor *PP,
                                   Preprocessor *ModuleExpanderPP) {}

  /// Override this to register AST matchers with \p Finder.
  ///
  /// This should be used by grayc checks that analyze code properties that
  /// dependent on AST knowledge.
  ///
  /// You can register as many matchers as necessary with \p Finder. Usually,
  /// "this" will be used as callback, but you can also specify other callback
  /// classes. Thereby, different matchers can trigger different callbacks.
  ///
  /// This will only be executed if the function isLanguageVersionSupported
  /// returns true.
  ///
  /// If you need to merge information between the different matchers, you can
  /// store these as members of the derived class. However, note that all
  /// matches occur in the order of the AST traversal.
  virtual void registerMatchers(ast_matchers::MatchFinder *Finder) {}

  /// ``GrayCChecks`` that register ASTMatchers should do the actual
  /// work in here.
  virtual void check(const ast_matchers::MatchFinder::MatchResult &Result) {}

  /// Add a diagnostic with the check's name.
  DiagnosticBuilder diag(SourceLocation Loc, StringRef Description,
                         DiagnosticIDs::Level Level = DiagnosticIDs::Warning);

  /// Should store all options supported by this check with their
  /// current values or default values for options that haven't been overridden.
  ///
  /// The check should use ``Options.store()`` to store each option it supports
  /// whether it has the default value or it has been overridden.
  virtual void storeOptions(GrayCOptions::OptionMap &Options) {}

  /// Provides access to the ``GrayCCheck`` options via check-local
  /// names.
  ///
  /// Methods of this class prepend ``CheckName + "."`` to translate check-local
  /// option names to global option names.
  class OptionsView {
  public:
    /// Initializes the instance using \p CheckName + "." as a prefix.
    OptionsView(StringRef CheckName,
                const GrayCOptions::OptionMap &CheckOptions);

    /// Read a named option from the ``Context``.
    ///
    /// Reads the option with the check-local name \p LocalName from the
    /// ``CheckOptions``. If the corresponding key is not present, returns
    /// a ``MissingOptionError``.
    llvm::Expected<std::string> get(StringRef LocalName) const;

    /// Read a named option from the ``Context``.
    ///
    /// Reads the option with the check-local name \p LocalName from the
    /// ``CheckOptions``. If the corresponding key is not present, returns
    /// \p Default.
    std::string get(StringRef LocalName, StringRef Default) const {
      if (llvm::Expected<std::string> Val = get(LocalName))
        return *Val;
      else
        llvm::consumeError(Val.takeError());
      return Default.str();
    }

    /// Read a named option from the ``Context``.
    ///
    /// Reads the option with the check-local name \p LocalName from local or
    /// global ``CheckOptions``. Gets local option first. If local is not
    /// present, falls back to get global option. If global option is not
    /// present either, returns a ``MissingOptionError``.
    llvm::Expected<std::string> getLocalOrGlobal(StringRef LocalName) const;

    /// Read a named option from the ``Context``.
    ///
    /// Reads the option with the check-local name \p LocalName from local or
    /// global ``CheckOptions``. Gets local option first. If local is not
    /// present, falls back to get global option. If global option is not
    /// present either, returns \p Default.
    std::string getLocalOrGlobal(StringRef LocalName, StringRef Default) const {
      if (llvm::Expected<std::string> Val = getLocalOrGlobal(LocalName))
        return *Val;
      else
        llvm::consumeError(Val.takeError());
      return Default.str();
    }

    /// Read a named option from the ``Context`` and parse it as an
    /// integral type ``T``.
    ///
    /// Reads the option with the check-local name \p LocalName from the
    /// ``CheckOptions``. If the corresponding key is not present, returns
    /// a ``MissingOptionError``. If the corresponding key can't be parsed as
    /// a ``T``, return an ``UnparseableIntegerOptionError``.
    template <typename T>
    std::enable_if_t<std::is_integral<T>::value, llvm::Expected<T>>
    get(StringRef LocalName) const {
      if (llvm::Expected<std::string> Value = get(LocalName)) {
        T Result{};
        if (!StringRef(*Value).getAsInteger(10, Result))
          return Result;
        return llvm::make_error<UnparseableIntegerOptionError>(
            (NamePrefix + LocalName).str(), *Value);
      } else
        return std::move(Value.takeError());
    }

    /// Read a named option from the ``Context`` and parse it as an
    /// integral type ``T``.
    ///
    /// Reads the option with the check-local name \p LocalName from the
    /// ``CheckOptions``. If the corresponding key is not present or it can't be
    /// parsed as a ``T``, returns \p Default.
    template <typename T>
    std::enable_if_t<std::is_integral<T>::value, T> get(StringRef LocalName,
                                                        T Default) const {
      if (llvm::Expected<T> ValueOr = get<T>(LocalName))
        return *ValueOr;
      else
        logErrToStdErr(ValueOr.takeError());
      return Default;
    }

    /// Read a named option from the ``Context`` and parse it as an
    /// integral type ``T``.
    ///
    /// Reads the option with the check-local name \p LocalName from local or
    /// global ``CheckOptions``. Gets local option first. If local is not
    /// present, falls back to get global option. If global option is not
    /// present either, returns a ``MissingOptionError``. If the corresponding
    /// key can't be parsed as a ``T``, return an
    /// ``UnparseableIntegerOptionError``.
    template <typename T>
    std::enable_if_t<std::is_integral<T>::value, llvm::Expected<T>>
    getLocalOrGlobal(StringRef LocalName) const {
      llvm::Expected<std::string> ValueOr = get(LocalName);
      bool IsGlobal = false;
      if (!ValueOr) {
        IsGlobal = true;
        llvm::consumeError(ValueOr.takeError());
        ValueOr = getLocalOrGlobal(LocalName);
        if (!ValueOr)
          return std::move(ValueOr.takeError());
      }
      T Result{};
      if (!StringRef(*ValueOr).getAsInteger(10, Result))
        return Result;
      return llvm::make_error<UnparseableIntegerOptionError>(
          (IsGlobal ? LocalName.str() : (NamePrefix + LocalName).str()),
          *ValueOr);
    }

    /// Read a named option from the ``Context`` and parse it as an
    /// integral type ``T``.
    ///
    /// Reads the option with the check-local name \p LocalName from local or
    /// global ``CheckOptions``. Gets local option first. If local is not
    /// present, falls back to get global option. If global option is not
    /// present either or it can't be parsed as a ``T``, returns \p Default.
    template <typename T>
    std::enable_if_t<std::is_integral<T>::value, T>
    getLocalOrGlobal(StringRef LocalName, T Default) const {
      if (llvm::Expected<T> ValueOr = getLocalOrGlobal<T>(LocalName))
        return *ValueOr;
      else
        logErrToStdErr(ValueOr.takeError());
      return Default;
    }

    /// Read a named option from the ``Context`` and parse it as an
    /// enum type ``T``.
    ///
    /// Reads the option with the check-local name \p LocalName from the
    /// ``CheckOptions``. If the corresponding key is not present, returns a
    /// ``MissingOptionError``. If the key can't be parsed as a ``T`` returns a
    /// ``UnparseableEnumOptionError``.
    ///
    /// \ref clang::grayc::OptionEnumMapping must be specialized for ``T`` to
    /// supply the mapping required to convert between ``T`` and a string.
    template <typename T>
    std::enable_if_t<std::is_enum<T>::value, llvm::Expected<T>>
    get(StringRef LocalName, bool IgnoreCase = false) {
      if (llvm::Expected<int64_t> ValueOr =
              getEnumInt(LocalName, typeEraseMapping<T>(), false, IgnoreCase))
        return static_cast<T>(*ValueOr);
      else
        return std::move(ValueOr.takeError());
    }

    /// Read a named option from the ``Context`` and parse it as an
    /// enum type ``T``.
    ///
    /// Reads the option with the check-local name \p LocalName from the
    /// ``CheckOptions``. If the corresponding key is not present or it can't be
    /// parsed as a ``T``, returns \p Default.
    ///
    /// \ref clang::grayc::OptionEnumMapping must be specialized for ``T`` to
    /// supply the mapping required to convert between ``T`` and a string.
    template <typename T>
    std::enable_if_t<std::is_enum<T>::value, T>
    get(StringRef LocalName, T Default, bool IgnoreCase = false) {
      if (auto ValueOr = get<T>(LocalName, IgnoreCase))
        return *ValueOr;
      else
        logErrToStdErr(ValueOr.takeError());
      return Default;
    }

    /// Read a named option from the ``Context`` and parse it as an
    /// enum type ``T``.
    ///
    /// Reads the option with the check-local name \p LocalName from local or
    /// global ``CheckOptions``. Gets local option first. If local is not
    /// present, falls back to get global option. If global option is not
    /// present either, returns a ``MissingOptionError``. If the key can't be
    /// parsed as a ``T`` returns a ``UnparseableEnumOptionError``.
    ///
    /// \ref clang::grayc::OptionEnumMapping must be specialized for ``T`` to
    /// supply the mapping required to convert between ``T`` and a string.
    template <typename T>
    std::enable_if_t<std::is_enum<T>::value, llvm::Expected<T>>
    getLocalOrGlobal(StringRef LocalName,
                     bool IgnoreCase = false) {
      if (llvm::Expected<int64_t> ValueOr =
              getEnumInt(LocalName, typeEraseMapping<T>(), true, IgnoreCase))
        return static_cast<T>(*ValueOr);
      else
        return std::move(ValueOr.takeError());
    }

    /// Read a named option from the ``Context`` and parse it as an
    /// enum type ``T``.
    ///
    /// Reads the option with the check-local name \p LocalName from local or
    /// global ``CheckOptions``. Gets local option first. If local is not
    /// present, falls back to get global option. If global option is not
    /// present either or it can't be parsed as a ``T``, returns \p Default.
    ///
    /// \ref clang::grayc::OptionEnumMapping must be specialized for ``T`` to
    /// supply the mapping required to convert between ``T`` and a string.
    template <typename T>
    std::enable_if_t<std::is_enum<T>::value, T>
    getLocalOrGlobal(StringRef LocalName, T Default, bool IgnoreCase = false) {
      if (auto ValueOr = getLocalOrGlobal<T>(LocalName, IgnoreCase))
        return *ValueOr;
      else
        logErrToStdErr(ValueOr.takeError());
      return Default;
    }

    /// Stores an option with the check-local name \p LocalName with
    /// string value \p Value to \p Options.
    void store(GrayCOptions::OptionMap &Options, StringRef LocalName,
               StringRef Value) const;

    /// Stores an option with the check-local name \p LocalName with
    /// integer value \p Value to \p Options.
    template <typename T>
    std::enable_if_t<std::is_integral<T>::value>
    store(GrayCOptions::OptionMap &Options, StringRef LocalName,
          T Value) const {
      storeInt(Options, LocalName, Value);
    }

    /// Stores an option with the check-local name \p LocalName as the string
    /// representation of the Enum \p Value to \p Options.
    ///
    /// \ref clang::grayc::OptionEnumMapping must be specialized for ``T`` to
    /// supply the mapping required to convert between ``T`` and a string.
    template <typename T>
    std::enable_if_t<std::is_enum<T>::value>
    store(GrayCOptions::OptionMap &Options, StringRef LocalName, T Value) {
      ArrayRef<std::pair<T, StringRef>> Mapping =
          OptionEnumMapping<T>::getEnumMapping();
      auto Iter = llvm::find_if(
          Mapping, [&](const std::pair<T, StringRef> &NameAndEnum) {
            return NameAndEnum.first == Value;
          });
      assert(Iter != Mapping.end() && "Unknown Case Value");
      store(Options, LocalName, Iter->second);
    }

  private:
    using NameAndValue = std::pair<int64_t, StringRef>;

    llvm::Expected<int64_t> getEnumInt(StringRef LocalName,
                                       ArrayRef<NameAndValue> Mapping,
                                       bool CheckGlobal, bool IgnoreCase);

    template <typename T>
    std::enable_if_t<std::is_enum<T>::value, std::vector<NameAndValue>>
    typeEraseMapping() {
      ArrayRef<std::pair<T, StringRef>> Mapping =
          OptionEnumMapping<T>::getEnumMapping();
      std::vector<NameAndValue> Result;
      Result.reserve(Mapping.size());
      for (auto &MappedItem : Mapping) {
        Result.emplace_back(static_cast<int64_t>(MappedItem.first),
                            MappedItem.second);
      }
      return Result;
    }

    void storeInt(GrayCOptions::OptionMap &Options, StringRef LocalName,
                  int64_t Value) const;

    static void logErrToStdErr(llvm::Error &&Err);

    std::string NamePrefix;
    const GrayCOptions::OptionMap &CheckOptions;
  };

private:
  void run(const ast_matchers::MatchFinder::MatchResult &Result) override;
  StringRef getID() const override { return CheckName; }
  std::string CheckName;
  GrayCContext *Context;

protected:
  OptionsView Options;
  /// Returns the main file name of the current translation unit.
  StringRef getCurrentMainFile() const { return Context->getCurrentFile(); }
  /// Returns the language options from the context.
  const LangOptions &getLangOpts() const { return Context->getLangOpts(); }
};

/// Read a named option from the ``Context`` and parse it as a bool.
///
/// Reads the option with the check-local name \p LocalName from the
/// ``CheckOptions``. If the corresponding key is not present, returns
/// a ``MissingOptionError``. If the corresponding key can't be parsed as
/// a bool, return an ``UnparseableIntegerOptionError``.
template <>
llvm::Expected<bool>
GrayCCheck::OptionsView::get<bool>(StringRef LocalName) const;

/// Read a named option from the ``Context`` and parse it as a bool.
///
/// Reads the option with the check-local name \p LocalName from the
/// ``CheckOptions``. If the corresponding key is not present or it can't be
/// parsed as a bool, returns \p Default.
template <>
bool GrayCCheck::OptionsView::get<bool>(StringRef LocalName,
                                            bool Default) const;

/// Read a named option from the ``Context`` and parse it as a bool.
///
/// Reads the option with the check-local name \p LocalName from local or
/// global ``CheckOptions``. Gets local option first. If local is not
/// present, falls back to get global option. If global option is not
/// present either, returns a ``MissingOptionError``. If the corresponding
/// key can't be parsed as a bool, return an
/// ``UnparseableIntegerOptionError``.
template <>
llvm::Expected<bool>
GrayCCheck::OptionsView::getLocalOrGlobal<bool>(StringRef LocalName) const;

/// Read a named option from the ``Context`` and parse it as a bool.
///
/// Reads the option with the check-local name \p LocalName from local or
/// global ``CheckOptions``. Gets local option first. If local is not
/// present, falls back to get global option. If global option is not
/// present either or it can't be parsed as a bool, returns \p Default.
template <>
bool GrayCCheck::OptionsView::getLocalOrGlobal<bool>(StringRef LocalName,
                                                         bool Default) const;

/// Stores an option with the check-local name \p LocalName with
/// bool value \p Value to \p Options.
template <>
void GrayCCheck::OptionsView::store<bool>(
    GrayCOptions::OptionMap &Options, StringRef LocalName,
    bool Value) const;

} // namespace grayc
} // namespace clang

#endif // GRAYC_GrayCCheck_H
