set(LLVM_LINK_COMPONENTS support)

add_clang_executable(expression-mutator-cons
	ExpressionMutator.cpp
  )
target_link_libraries(expression-mutator-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
