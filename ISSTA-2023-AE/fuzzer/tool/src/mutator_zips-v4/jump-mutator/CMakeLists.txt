set(LLVM_LINK_COMPONENTS support)

    add_clang_executable(jump - mutator JumpMutator.cpp) target_link_libraries(
        jump - mutator PRIVATE clangTooling clangBasic clangASTMatchers random -
        manager)
