cmake_minimum_required(VERSION 3.5)
project( exam )

set(CMAKE_CXX_STANDARD 14)
set(CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Exam_1 ${CMAKE_CURRENT_SOURCE_DIR}/exam_1.cpp)
target_link_libraries(Exam_1
  PUBLIC
  # interview ##static_lib
)