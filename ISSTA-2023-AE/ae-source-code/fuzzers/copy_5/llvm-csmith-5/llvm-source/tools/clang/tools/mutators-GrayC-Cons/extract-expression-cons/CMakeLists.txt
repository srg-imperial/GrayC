set(LLVM_LINK_COMPONENTS support)

add_clang_executable(extract-expression-cons
	ExtractExpression.cpp
  )
target_link_libraries(extract-expression-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
