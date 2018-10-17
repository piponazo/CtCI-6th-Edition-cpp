add_library(lists
    lists/Node.h
    lists/Node.cpp
    lists/utils.h
    lists/utils.cpp
)

target_include_directories(lists PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(2_luis
    luis/2_main.cpp
    luis/2_utils.cpp
    luis/2.1_remove_dups.cpp
    luis/2.2_kthToLast.cpp
    luis/2.3_delete_middle_node.cpp
    luis/2.4_partition.cpp
    luis/2.5_sum_lists.cpp
)

target_link_libraries(2_luis PRIVATE lists)
