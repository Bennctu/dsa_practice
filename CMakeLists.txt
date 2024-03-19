cmake_minimum_required(VERSION 3.5)
project( interview )

set(CMAKE_CXX_STANDARD 14)
set(CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("build type:" ${CMAKE_BUILD_TYPE})

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message("build type:" ${CMAKE_BUILD_TYPE})
endif()

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(CMAKE_CXX_FLAGS "-std=c++14 -g3 -Wall")
  message("flag:" ${CMAKE_CXX_FLAGS})
endif()

#eigen
# find_package( Eigen3 3.3 REQUIRED)
# message(STATUS "Eigen3 lib is found:" ${EIGEN3_INCLUDE_DIR})
# #opencv
# find_package( OpenCV REQUIRED )
# message(STATUS "Opencv lib is found:" ${OpenCV_INCLUDE_DIRS})

# if(NOT TARGET eigen)
#   add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/eigen-3.4.0)
# endif()

#link
set( LINK_INCLUDE_DIRS
  # ${EIGEN3_INCLUDE_DIR}
  # ${OpenCV_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
  
set( LINK_LIBS
  ${OpenCV_LIBS}
)

set( SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_hello.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${LINK_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
  # ${LINK_LIBS}
  # if(NOT TARGET eigen)
  #   eigen
  # endif()
)

add_subdirectory(./testing)
# add_subdirectory(./exam)
