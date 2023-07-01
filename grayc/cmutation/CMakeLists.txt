add_library(GrayCCMutator
  CMutationModule.cpp
  UnaryOperatorCheck.cpp
)

target_link_libraries(GrayCCMutator
  PRIVATE
  clangAnalysis
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTooling
  GrayC
  )
