add_library(lists
    lists/Node.h
    lists/Node.cpp
    lists/utils.h
    lists/utils.cpp
)

add_executable(2_luis
    2_main_luis.cpp
    2_utils.cpp
    2-1-remove-dups_luis.cpp
    2-2-kthToLast_luis.cpp
    2-3-delete_middle_node_luis.cpp
    2-4-partition_luis.cpp
)

target_link_libraries(2_luis PRIVATE lists)
target_include_directories(2_luis PRIVATE ${PROJECT_SOURCE_DIR}) # To find the catch.hpp file

#add_executable(2.3_delete_middle_node   "2-3-delete-middle-node.cpp")
#add_executable(2.4_cpp_partition        "2-4-cpp_partitions.cpp")
#add_executable(2.5_partition            "2-4-partition.cpp")
#add_executable(2.6_add_lists            "2-5-add-lists.cpp")
#add_executable(2.7_palindrome           "2-6-palindrome.cpp")
#add_executable(2.8_intersection         "2-7-intersection.cpp")
#add_executable(2.9_loop_detection       "2-8-loop-detection.cpp")
