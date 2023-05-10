set(LLVM_LINK_COMPONENTS support)

add_clang_executable(append-expression
	AppendExpression.cpp
  )
target_link_libraries(append-expression
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer
  )
