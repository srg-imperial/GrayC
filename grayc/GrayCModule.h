//===--- GrayCModule.h - grayc -------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GrayCModule_H
#define GRAYC_GrayCModule_H

#include "GrayCOptions.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/StringRef.h"
#include <functional>
#include <map>
#include <memory>
#include <string>

namespace clang {
namespace grayc {

class GrayCCheck;
class GrayCContext;

/// A collection of \c GrayCCheckFactory instances.
///
/// All grayc modules register their check factories with an instance of
/// this object.
class GrayCCheckFactories {
public:
  using CheckFactory = std::function<std::unique_ptr<GrayCCheck>(
      llvm::StringRef Name, GrayCContext *Context)>;

  /// Registers check \p Factory with name \p Name.
  ///
  /// For all checks that have default constructors, use \c registerCheck.
  void registerCheckFactory(llvm::StringRef Name, CheckFactory Factory);

  /// Registers the \c CheckType with the name \p Name.
  ///
  /// This method should be used for all \c GrayCChecks that don't require
  /// constructor parameters.
  ///
  /// For example, if have a grayc check like:
  /// \code
  /// class MygraycCheck : public GrayCCheck {
  ///   void registerMatchers(ast_matchers::MatchFinder *Finder) override {
  ///     ..
  ///   }
  /// };
  /// \endcode
  /// you can register it with:
  /// \code
  /// class MyModule : public GrayCModule {
  ///   void addCheckFactories(GrayCCheckFactories &Factories) override {
  ///     Factories.registerCheck<MygraycCheck>("myproject-my-check");
  ///   }
  /// };
  /// \endcode
  template <typename CheckType> void registerCheck(llvm::StringRef CheckName) {
    registerCheckFactory(CheckName,
                         [](llvm::StringRef Name, GrayCContext *Context) {
                           return std::make_unique<CheckType>(Name, Context);
                         });
  }

  /// Create instances of checks that are enabled.
  std::vector<std::unique_ptr<GrayCCheck>>
  createChecks(GrayCContext *Context);

  typedef std::map<std::string, CheckFactory> FactoryMap;
  FactoryMap::const_iterator begin() const { return Factories.begin(); }
  FactoryMap::const_iterator end() const { return Factories.end(); }
  bool empty() const { return Factories.empty(); }

private:
  FactoryMap Factories;
};

/// A grayc module groups a number of \c GrayCChecks and gives
/// them a prefixed name.
class GrayCModule {
public:
  virtual ~GrayCModule() {}

  /// Implement this function in order to register all \c CheckFactories
  /// belonging to this module.
  virtual void addCheckFactories(GrayCCheckFactories &CheckFactories) = 0;

  /// Gets default options for checks defined in this module.
  virtual GrayCOptions getModuleOptions();
};

} // end namespace grayc
} // end namespace clang

#endif // GRAYC_GrayCModule_H
