//===- GrayCForceLinker.h - grayc --------------------------------===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GRAYCFORCELINKER_H
#define GRAYC_GRAYCFORCELINKER_H

#include "clang/Config/config.h"
#include "llvm/Support/Compiler.h"

namespace clang {
namespace grayc {

// This anchor is used to force the linker to link the CMutatorModule.
extern volatile int CMutatorModuleAnchorSource;
static int LLVM_ATTRIBUTE_UNUSED CMutatorModuleAnchorDestination =
    CMutatorModuleAnchorSource;

// This anchor is used to force the linker to link the CXXMutatorModule.
extern volatile int CXXMutatorModuleAnchorSource;
static int LLVM_ATTRIBUTE_UNUSED CXXMutatorModuleAnchorDestination =
    CXXMutatorModuleAnchorSource;

} // namespace grayc
} // namespace clang

#endif
