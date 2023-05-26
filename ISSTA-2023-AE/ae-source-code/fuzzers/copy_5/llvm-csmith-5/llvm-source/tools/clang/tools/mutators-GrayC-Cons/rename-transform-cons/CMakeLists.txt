set(LLVM_LINK_COMPONENTS support)

add_clang_executable(rename-transform-cons
	RenameTransform.cpp
  )
target_link_libraries(rename-transform-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer-cons
  )
