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


if (LLVM_VERSION_MAJOR LESS 12)
  message(WARNING "Found LLVM ${LLVM_VERSION_MAJOR}, but LLVM 12 or newer is required.")
  add_definitions(-DGRAYC_OLD_LLVM_API)

elseif (LLVM_VERSION_MAJOR GREATER 17)
  message(WARNING "Found LLVM ${LLVM_VERSION_MAJOR}, but this project targets LLVM 17. Proceeding may cause issues.")

elseif (NOT LLVM_VERSION_MAJOR EQUAL 12 AND NOT LLVM_VERSION_MAJOR EQUAL 17)
  message(WARNING "Found LLVM ${LLVM_VERSION_MAJOR}, but this project officially supports LLVM 12 and LLVM 17 only. Proceeding may cause issues.")
endif()


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

# LLVM/Clang is normally built without RTTI. Be consistent with that.
if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

# -fvisibility-inlines-hidden is set when building LLVM and on Darwin warnings
# are triggered if GrayC is built without this flag (though otherwise it
# builds fine). For consistency, add it here too.
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


# add_subdirectory(Utils)

add_subdirectory(clang-diff)
add_subdirectory(grayc)
