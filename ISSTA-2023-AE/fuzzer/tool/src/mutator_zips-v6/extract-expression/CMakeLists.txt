set(LLVM_LINK_COMPONENTS support)

add_clang_executable(extract-expression
	ExtractExpression.cpp
  )
target_link_libraries(extract-expression
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer
  )
