set(LLVM_LINK_COMPONENTS support)

add_clang_executable(rename-transform
	RenameTransform.cpp
  )
target_link_libraries(rename-transform
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  utils-fuzzer
  )
