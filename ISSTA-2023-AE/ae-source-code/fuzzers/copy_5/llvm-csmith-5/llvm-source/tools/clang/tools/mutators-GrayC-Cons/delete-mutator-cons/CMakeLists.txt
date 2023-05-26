set(LLVM_LINK_COMPONENTS support)

add_clang_executable(delete-mutator-cons
  DeleteMutator.cpp
  )
target_link_libraries(delete-mutator-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
