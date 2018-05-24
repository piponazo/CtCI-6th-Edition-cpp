add_executable(10_luis
    10_main.cpp
    10.1_sorted_merge.cpp
    10.2_group_anagrams.cpp
    10.3_search_in_rotated_array.cpp
)

target_include_directories(10_luis PRIVATE ${PROJECT_SOURCE_DIR})
