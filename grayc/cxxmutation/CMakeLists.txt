add_library(GrayCCXXMutator
  CXXMutationModule.cpp
  CXXUnaryOperatorCheck.cpp
)

target_link_libraries(GrayCCXXMutator
  PRIVATE
  clangAnalysis
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTooling
  GrayC
  )
