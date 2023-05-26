set(LLVM_LINK_COMPONENTS support)

add_clang_executable(jump-mutator-cons
  JumpMutator.cpp
  )
target_link_libraries(jump-mutator-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
