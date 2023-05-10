set(LLVM_LINK_COMPONENTS support)

add_clang_executable(assignment-mutator
	AssignmentMutator.cpp
  )
target_link_libraries(assignment-mutator
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  random-manager
  )
