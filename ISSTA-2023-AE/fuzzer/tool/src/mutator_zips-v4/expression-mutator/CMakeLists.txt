set(LLVM_LINK_COMPONENTS support)

    add_clang_executable(expression - mutator ExpressionMutator.cpp)
        target_link_libraries(expression -
                              mutator PRIVATE clangTooling clangBasic
                                  clangASTMatchers random -
                              manager)
