// Compatability layer for different LLVM versions (12 vs 17)

#pragma once

#ifdef GRAYC_OLD_LLVM_API
// Optional
#include "llvm/ADT/Optional.h"
#define OPTIONAL( T ) llvm::Optional<T>
#define HAS_VALUE( opt ) ( opt.hasValue() )
#define OPTIONAL_NONE llvm::None
#define GET_VALUE( opt ) ( opt.getValue() )
#define GET_VALUE_OR( opt, default ) ( opt.getValueOr( default ) )

// StringRef
#define EQUALS_INSENSITIVE( str1, str2 ) ( str1.equals_lower( str2 ) )

#else
// Optional
#include <optional>
#define OPTIONAL( T ) std::optional<T>
#define HAS_VALUE( opt ) ( opt.has_value() )
#define OPTIONAL_NONE std::nullopt
#define GET_VALUE( opt ) ( *opt )
#define GET_VALUE_OR( opt, default ) ( opt.value_or( default ) )
#include "llvm/Support/WithColor.h"

// StringRef
#define EQUALS_INSENSITIVE( str1, str2 ) ( str1.equals_insensitive( str2 ) )
#endif