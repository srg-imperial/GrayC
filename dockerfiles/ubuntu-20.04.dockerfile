cmake_minimum_required(VERSION 3.13.4)
project(GrayC)

#===============================================================================
# 0. GET CLANG INSTALLATION DIR
#===============================================================================
# In GrayC, `CT_Clang_INSTALL_DIR` is the key CMake variable - it points
# to a Clang installation directory. We, however, use `LLVM_CONFIG_BINARY` as
# our primary source of truth.


set(LLVM_CONFIG_BINARY "llvm-config" CACHE STRING
  "The path to a llvm-config binary which is used to find llvm tooling to duplicate libraries"
)
execute_process(
  COMMAND ${LLVM_CONFIG_BINARY} --prefix
  OUTPUT_VARIABLE LLVM_DIR
)
string(REGEX REPLACE "\n+$" "" LLVM_DIR "${LLVM_DIR}")
mark_as_advanced(LLVM_DIR)

set(CT_Clang_INSTALL_DIR "${LLVM_DIR}" CACHE PATH
  "Clang installation directory"
)

#===============================================================================
# 1. VERIFY CLANG INSTALLATION DIR
#===============================================================================
set(CT_LLVM_INCLUDE_DIR "${CT_Clang_INSTALL_DIR}/include/llvm")
if(NOT EXISTS "${CT_LLVM_INCLUDE_DIR}")
message(FATAL_ERROR
  " CT_Clang_INSTALL_DIR (${CT_LLVM_INCLUDE_DIR}) is invalid.")
endif()

set(CT_LLVM_CMAKE_FILE
  "${CT_Clang_INSTALL_DIR}/lib/cmake/clang/ClangConfig.cmake")
if(NOT EXISTS "${CT_LLVM_CMAKE_FILE}")
message(FATAL_ERROR
  " CT_LLVM_CMAKE_FILE (${CT_LLVM_CMAKE_FILE}) is invalid.")
endif()



#===============================================================================
# 2. LOAD CLANG CONFIGURATION
#    Extracted from:
#    http://llvm.org/docs/CMake.html#embedding-llvm-in-your-project
#===============================================================================
list(APPEND CMAKE_PREFIX_PATH "${CT_Clang_INSTALL_DIR}/lib/cmake/clang/")

find_package(Clang REQUIRED CONFIG)

# Sanity check. As Clang does not expose e.g. `CLANG_VERSION_MAJOR` through
# AddClang.cmake, we have to use LLVM_VERSION_MAJOR instead.
# TODO: Revisit when next version is released.
if(NOT "12" VERSION_EQUAL "${LLVM_VERSION_MAJOR}")
  message(FATAL_ERROR "Found LLVM ${LLVM_VERSION_MAJOR}, but need LLVM 12")
endif()

message(STATUS "Found Clang ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using ClangConfig.cmake in: ${CT_Clang_INSTALL_DIR}")

message("CLANG STATUS:
  Includes (clang)    ${CLANG_INCLUDE_DIRS}
  Includes (llvm)     ${LLVM_INCLUDE_DIRS}"
)


# Set the LLVM and Clang header and library paths
include_directories(SYSTEM "${LLVM_INCLUDE_DIRS};${CLANG_INCLUDE_DIRS}")

#===============================================================================
# 3. GrayC BUILD CONFIGURATION
#===============================================================================
# Use the same C++ standard as LLVM does
set(CMAKE_CXX_STANDARD 17 CACHE STRING "")

# Build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE
      STRING "Build type (default Debug):" FORCE)
endif()

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -DDEBUG \
    -fdiagnostics-color=always")

if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

include(CheckCXXCompilerFlag)
link_libraries(stdc++fs)
# Set the build directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")


#===============================================================================
# 4. ADD SUB-TARGETS
# Doing this at the end so that all definitions and link/include paths are
# available for the sub-projects.
#===============================================================================
# add_subdirectory(vendor/fmtlib)
# find_package(fmt)

add_subdirectory(Utils)
add_subdirectory(transformation)

# add_subdirectory(test/cbseq)

# add_test(NAME add-stmt-patch-func-call-test
#         COMMAND lit ${CMAKE_CURRENT_BINARY_DIR}/test/add-stmt-patch-func-call
#         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
