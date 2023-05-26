set(LLVM_LINK_COMPONENTS support)

add_clang_library(utils-fuzzer-cons
	GrayCCustomRandom.cpp
	GrayCUtils.cpp
  )
target_link_libraries(utils-fuzzer-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  )
