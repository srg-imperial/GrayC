//===--- GlobList.h ---------------------------------------------*- C++ -*-===//
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef GRAYC_GLOBLIST_H
#define GRAYC_GLOBLIST_H

#include "clang/Basic/LLVM.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Regex.h"
#include <vector>

namespace clang {
namespace grayc {

/// Read-only set of strings represented as a list of positive and negative
/// globs.
///
/// Positive globs add all matched strings to the set, negative globs remove
/// them in the order of appearance in the list.
class GlobList {
public:
  /// \p Globs is a comma-separated list of globs (only the '*' metacharacter is
  /// supported) with an optional '-' prefix to denote exclusion.
  ///
  /// An empty \p Globs string is interpreted as one glob that matches an empty
  /// string.
  GlobList(StringRef Globs);

  /// Returns \c true if the pattern matches \p S. The result is the last
  /// matching glob's Positive flag.
  bool contains(StringRef S);

private:

  struct GlobListItem {
    bool IsPositive;
    mutable llvm::Regex Regex;
  };
  std::vector<GlobListItem> Items;
};

} // end namespace grayc
} // end namespace clang

#endif // GRAYC_GLOBLIST_H
