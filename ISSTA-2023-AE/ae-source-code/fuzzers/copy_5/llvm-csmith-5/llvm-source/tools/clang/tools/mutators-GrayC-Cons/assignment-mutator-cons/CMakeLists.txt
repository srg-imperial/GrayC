set(LLVM_LINK_COMPONENTS support)

add_clang_executable(assignment-mutator-cons
	AssignmentMutator.cpp
  )
target_link_libraries(assignment-mutator-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
