//===--- CMutationModule.cpp - GrayC ---------------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../GrayC.h"
#include "../GrayCModule.h"
#include "../GrayCModuleRegistry.h"
#include "AssignmentExpressionMutator.h"
#include "ConditionalExpressionMutator.h"
#include "DuplicateStatementMutator.h"
#include "JumpMutator.h"
#include "UnaryOperatorCheck.h"


namespace clang {
namespace grayc {
namespace cmutation {

class CMutationModule : public GrayCModule {
public:
  void addCheckFactories(GrayCCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<AssignmentExpressionMutator>(
        "cmutation-assignment-expression-mutator");
    CheckFactories.registerCheck<ConditionalExpressionMutator>(
        "cmutation-conditional-expression-mutator");
    CheckFactories.registerCheck<DuplicateStatementMutator>(
        "cmutation-duplicate-statement-mutator");
    CheckFactories.registerCheck<JumpMutator>(
        "cmutation-jump-mutator");
    CheckFactories.registerCheck<UnaryOperatorCheck>(
        "cmutation-unary");
  }
};

// Register the CMutationModule using this statically initialized variable.
static GrayCModuleRegistry::Add<CMutationModule>
    X("cmutator-module", "C program mutations.");

} // namespace cmutation

// This anchor is used to force the linker to link in the generated object file
// and thus register the CMutationModule.
volatile int CMutatorModuleAnchorSource = 0;

} // namespace grayc
} // namespace clang
