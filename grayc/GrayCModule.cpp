//===--- graycGrayCModule.cpp - GrayC tool -----===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
///  \file Implements classes required to build grayc modules.
///
//===----------------------------------------------------------------------===//

#include "GrayCModule.h"
#include "GrayCCheck.h"

namespace clang {
namespace grayc {

void GrayCCheckFactories::registerCheckFactory(StringRef Name,
                                                   CheckFactory Factory) {
  Factories[std::string(Name)] = std::move(Factory);
}

std::vector<std::unique_ptr<GrayCCheck>>
GrayCCheckFactories::createChecks(GrayCContext *Context) {
  std::vector<std::unique_ptr<GrayCCheck>> Checks;
  for (const auto &Factory : Factories) {
    if (Context->isCheckEnabled(Factory.first))
      Checks.emplace_back(Factory.second(Factory.first, Context));
  }
  return Checks;
}

GrayCOptions GrayCModule::getModuleOptions() {
  return GrayCOptions();
}

} // namespace grayc
} // namespace clang
