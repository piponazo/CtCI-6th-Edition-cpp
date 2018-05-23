add_library(tree
    "luis/tree.h"
    "luis/tree.cpp"
)

add_executable(4_luis
    luis/4_main.cpp
    luis/4.2_minimal_tree.cpp
    luis/4.3_list_of_depths.cpp
)

target_link_libraries(4_luis PRIVATE tree)
target_include_directories(4_luis PRIVATE ${PROJECT_SOURCE_DIR})
