cmake_minimum_required(VERSION 3.4.3)
project(grayc-st)

#===============================================================================
# 1. LOAD LLVM CONFIGURATION
#===============================================================================
# Set this to a valid LLVM installation dir
set(CT_Clang_INSTALL_DIR "" CACHE PATH "LLVM installation directory")

# Add the location of ClangConfig.cmake to CMake search paths (so that
# find_package can locate it)
list(APPEND CMAKE_PREFIX_PATH "${CT_Clang_INSTALL_DIR}/lib/cmake/clang/")

find_package(Clang REQUIRED CONFIG)

# HelloWorld includes headers from LLVM and Clang - update the include paths
# accordingly
include_directories(SYSTEM "${LLVM_INCLUDE_DIRS};${CLANG_INCLUDE_DIRS}")

#===============================================================================
# 2. GrayC BUILD CONFIGURATION
#===============================================================================
# Use the same C++ standard as LLVM does
set(CMAKE_CXX_STANDARD 17 CACHE STRING "")

# LLVM is normally built without RTTI. Be consistent with that.
if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

#===============================================================================
# 3. ADD THE TARGET
#===============================================================================

add_library(GrayCMain
  GrayCMain.cpp
)

target_link_libraries(GrayCMain
  PRIVATE
  clangAST
  clangASTMatchers
  clangBasic
  clangTooling
  clangToolingCore
  GrayC
  GrayCCMutator
  GrayCCXXMutator
)

add_executable(grayc GrayCToolMain.cpp)

target_link_libraries(grayc
  PRIVATE
  GrayC
  GrayCMain
  GrayCCMutator
  GrayCCXXMutator
)
target_link_libraries(grayc
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  clangAST
  clangBasic
  clangToolingCore
)


