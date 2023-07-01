//===--- GrayCProfiling.h - grayc ----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GrayCProfiling_H
#define GRAYC_GrayCProfiling_H

#include "llvm/ADT/Optional.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/Support/Chrono.h"
#include "llvm/Support/Timer.h"
#include <string>

namespace llvm {
class raw_ostream;
} // namespace llvm

namespace clang {
namespace grayc {

class GrayCProfiling {
public:
  struct StorageParams {
    llvm::sys::TimePoint<> Timestamp;
    std::string SourceFilename;
    std::string StoreFilename;

    StorageParams() = default;

    StorageParams(llvm::StringRef ProfilePrefix, llvm::StringRef SourceFile);
  };

private:
  llvm::Optional<llvm::TimerGroup> TG;

  llvm::Optional<StorageParams> Storage;

  void printUserFriendlyTable(llvm::raw_ostream &OS);
  void printAsJSON(llvm::raw_ostream &OS);

  void storeProfileData();

public:
  llvm::StringMap<llvm::TimeRecord> Records;

  GrayCProfiling() = default;

  GrayCProfiling(llvm::Optional<StorageParams> Storage);

  ~GrayCProfiling();
};

} // end namespace grayc
} // end namespace clang

#endif // GRAYC_GrayCProfiling_H
