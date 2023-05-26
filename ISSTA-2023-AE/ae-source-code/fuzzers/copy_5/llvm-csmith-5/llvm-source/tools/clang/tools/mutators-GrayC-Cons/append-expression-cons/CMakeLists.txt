set(LLVM_LINK_COMPONENTS support)

add_clang_executable(append-expression-cons
	AppendExpression.cpp
  )
target_link_libraries(append-expression-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
