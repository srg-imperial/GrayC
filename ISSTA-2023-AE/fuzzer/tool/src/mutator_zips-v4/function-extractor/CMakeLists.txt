set(LLVM_LINK_COMPONENTS support)

add_clang_executable(function-extractor
	FunctionExtractor.cpp
  )
target_link_libraries(function-extractor
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  random-manager
  )
