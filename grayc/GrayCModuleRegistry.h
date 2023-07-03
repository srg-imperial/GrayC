//===--- GrayCModuleRegistry.h - grayc -----------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GrayCModuleRegistry_H
#define GRAYC_GrayCModuleRegistry_H

#include "GrayCModule.h"
#include "llvm/Support/Registry.h"

namespace clang {
namespace grayc {

typedef llvm::Registry<GrayCModule> GrayCModuleRegistry;

} // end namespace grayc
} // end namespace clang

#endif // GRAYC_GrayCModuleRegistry_H
