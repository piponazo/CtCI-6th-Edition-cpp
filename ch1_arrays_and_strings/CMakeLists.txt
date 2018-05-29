add_executable(1_luis
    luis/1_main.cpp
    luis/1.1_is_unique.cpp
    luis/1.2_check_permutation.cpp
    luis/1.3_urlify.cpp
    luis/1.4_palindrome_permutation.cpp
    luis/one_way.cpp
    luis/rotate_image.cpp
)

target_include_directories(1_luis PRIVATE ${PROJECT_SOURCE_DIR}) # To find catch.hpp

#add_executable(1.4a_palindrome_permutation  "4_palindrome_permutation/solution_a.cpp")
#add_executable(1.4b_palindrome_permutaion   "4_palindrome_permutation/solution_b.cpp")
#add_executable(1.1_is_unique                "1_is_unique/is_unique.cpp")
#add_executable(1.2_check_permutation        "2_check_permutation/check_permutation.cpp")
#add_executable(1.3_urlify                   "3_urlify/URLify.cpp")
#add_executable(1.5a_one_way                 "5_one_way/solution_a.cpp")
#add_executable(1.5b_one_way                 "5_one_way/solution_b.cpp")
#add_executable(1.6_string_compression       "6_string_compression/string_compression.cpp")
#add_executable(1.7_rotate_matrix            "7_rotate_matrix/rotate_matrix.cpp")
#add_executable(1.8_zero_matrix              "8_zero_matrix/zero_matrix.cpp")
#add_executable(1.9_string_rotation          "9_string_rotation/string_rotation.cpp")
