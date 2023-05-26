set(LLVM_LINK_COMPONENTS support)

add_clang_executable(function-extractor-cons
	FunctionExtractor.cpp
  )
target_link_libraries(function-extractor-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
