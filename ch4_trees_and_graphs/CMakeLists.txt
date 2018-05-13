add_library(tree
    "luis/tree.h"
    "luis/tree.cpp"
)

add_executable(4.2_minimal_tree "luis/4.2_minimal_tree.cpp")
target_link_libraries(4.2_minimal_tree tree)

add_executable(4.3_list_of_depths "luis/4.3_list_of_depths.cpp")
target_link_libraries(4.3_list_of_depths tree)
