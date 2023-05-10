set(LLVM_LINK_COMPONENTS support)

add_clang_library(utils-fuzzer
	GrayCCustomRandom.cpp
	GrayCUtils.cpp
  )
target_link_libraries(utils-fuzzer
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  )
