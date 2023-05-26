set(LLVM_LINK_COMPONENTS support)

add_clang_executable(constant-mutator-cons
	ConstantMutator.cpp
  )
target_link_libraries(constant-mutator-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
