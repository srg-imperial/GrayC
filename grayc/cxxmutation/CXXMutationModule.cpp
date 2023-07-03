//===--- CXXMutationModule.cpp - GrayC ---------------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../GrayC.h"
#include "../GrayCModule.h"
#include "../GrayCModuleRegistry.h"
#include "CXXUnaryOperatorCheck.h"


namespace clang {
namespace grayc {
namespace cxxmutation {

class CXXMutationModule : public GrayCModule {
public:
  void addCheckFactories(GrayCCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<CXXUnaryOperatorCheck>(
        "cxxmutaion-unary");
  }
};

// Register the CXXMutationModule using this statically initialized variable.
static GrayCModuleRegistry::Add<CXXMutationModule>
    X("cxxmutator-module", "CXX program mutations.");

} // namespace readability

// This anchor is used to force the linker to link in the generated object file
// and thus register the CXXMutationModule.
volatile int CXXMutatorModuleAnchorSource = 0;

} // namespace grayc
} // namespace clang
