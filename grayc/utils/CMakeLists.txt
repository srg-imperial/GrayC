

add_library(GrayCUtils
  FixItHintUtils.cpp
  LexerUtils.cpp
  GrayCRandomManager.cpp
)

target_link_libraries(GrayCUtils
  PRIVATE
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangSema
  clangTransformer
  GrayC
  )
