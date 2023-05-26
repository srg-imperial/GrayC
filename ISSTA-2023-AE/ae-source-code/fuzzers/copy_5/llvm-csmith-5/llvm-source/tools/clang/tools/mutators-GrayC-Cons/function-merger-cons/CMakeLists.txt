set(LLVM_LINK_COMPONENTS support)

add_clang_executable(function-merger-cons
	FunctionMerger.cpp
  )
target_link_libraries(function-merger-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
