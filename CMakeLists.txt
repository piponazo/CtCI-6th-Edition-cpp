cmake_minimum_required(VERSION 3.0)
project(CtCI-cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Check if the conan file exist to find the dependencies
if (EXISTS ${PROJECT_BINARY_DIR}/conanbuildinfo.cmake)
    include(${PROJECT_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()

find_package(GTest REQUIRED)

add_subdirectory("Ch 1.Arrays And Strings")

