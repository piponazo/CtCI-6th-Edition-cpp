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
