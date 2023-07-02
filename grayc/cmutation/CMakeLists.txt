add_library(GrayCCMutator
  AssignmentExpressionMutator.cpp
  CMutationModule.cpp
  ConditionalExpressionMutator.cpp
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
