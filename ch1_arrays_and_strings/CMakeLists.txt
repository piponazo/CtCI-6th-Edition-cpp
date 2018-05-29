add_executable(1_luis
    luis/1_main.cpp
    luis/1.1_is_unique.cpp
    luis/1.2_check_permutation.cpp
    luis/1.3_urlify.cpp
    luis/1.4_palindrome_permutation.cpp
    luis/1.5_one_way.cpp
    luis/1.7_rotate_matrix.cpp
)

target_include_directories(1_luis PRIVATE ${PROJECT_SOURCE_DIR}) # To find catch.hpp
