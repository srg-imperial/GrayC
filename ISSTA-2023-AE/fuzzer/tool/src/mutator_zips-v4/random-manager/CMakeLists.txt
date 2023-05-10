set(LLVM_LINK_COMPONENTS support)

add_clang_library(random-manager
	ClangFuzzerCustomRandom.cpp
  )
target_link_libraries(random-manager
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  )
