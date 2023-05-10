set(LLVM_LINK_COMPONENTS support)

add_clang_executable(constant-mutator
	ConstantMutator.cpp
  )
target_link_libraries(constant-mutator
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  random-manager
  )
