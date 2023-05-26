set(LLVM_LINK_COMPONENTS support)

add_clang_executable(duplicate-mutator-cons
  DuplicateMutator.cpp
  )
target_link_libraries(duplicate-mutator-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
