set(LLVM_LINK_COMPONENTS support)

add_clang_executable(global-extractor-cons
	GlobalExtractor.cpp
  )
target_link_libraries(global-extractor-cons
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  )
