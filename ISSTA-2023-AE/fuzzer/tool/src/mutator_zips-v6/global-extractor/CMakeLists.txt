set(LLVM_LINK_COMPONENTS support)

add_clang_executable(global-extractor
	GlobalExtractor.cpp
  )
target_link_libraries(global-extractor
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  )
