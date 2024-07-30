cmake_minimum_required(VERSION 3.5)
project( testing )

set(CMAKE_CXX_STANDARD 14)
set(CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Linkedlist ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist_test.cpp)
target_link_libraries(Linkedlist
  PUBLIC
  # interview ##static_lib
)

add_executable(MazeTest ${CMAKE_CURRENT_SOURCE_DIR}/maze_test.cpp)
add_executable(BET ${CMAKE_CURRENT_SOURCE_DIR}/binarytree_test.cpp)
add_executable(SingleList ${CMAKE_CURRENT_SOURCE_DIR}/singlelist_test.cpp)
add_executable(DoubleList ${CMAKE_CURRENT_SOURCE_DIR}/doublelist_test.cpp)