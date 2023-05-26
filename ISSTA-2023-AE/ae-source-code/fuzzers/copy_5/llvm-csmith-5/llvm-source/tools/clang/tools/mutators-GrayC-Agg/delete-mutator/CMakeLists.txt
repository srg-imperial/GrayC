set(LLVM_LINK_COMPONENTS support)

add_clang_executable(delete-mutator
  DeleteMutator.cpp
  )
target_link_libraries(delete-mutator
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  random-manager
  )
