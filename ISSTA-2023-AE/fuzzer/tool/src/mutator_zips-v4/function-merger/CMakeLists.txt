set(LLVM_LINK_COMPONENTS support)

add_clang_executable(function-merger
	FunctionMerger.cpp
  )
target_link_libraries(function-merger
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  random-manager
  )
