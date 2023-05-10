set(LLVM_LINK_COMPONENTS support)

add_clang_executable(duplicate-mutator
  DuplicateMutator.cpp
  )
target_link_libraries(duplicate-mutator
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer
  )
