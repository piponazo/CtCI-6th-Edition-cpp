cmake_minimum_required(VERSION 3.10)
project(CtCI-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_subdirectory("ch1_arrays_and_strings")
add_subdirectory("ch2_linked_lists")
add_subdirectory("ch4_trees_and_graphs")
add_subdirectory("ch5_bit_manipulation")
add_subdirectory("ch7_ood")
add_subdirectory("ch10_sorting_and_searching")
add_subdirectory("ch12_cpp")
