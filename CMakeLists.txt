cmake_minimum_required(VERSION 3.12)
project(cmaketut)

set(CMAKE_CXX_STANDARD 11)

# Set version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 1)

# See the online cmake tutorial
# Configure a header file to pass CMake settings through to the applcation
configure_file(
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# Add the binary/build directory to the include path
include_directories("${PROJECT_BINARY_DIR}")

add_executable(cmaketut main.cpp Mouse.cpp Mouse.h)