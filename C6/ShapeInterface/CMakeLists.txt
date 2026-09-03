cmake_minimum_required(VERSION 3.10)
project(ShapeInterface)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_executable(shape_app main.cpp)
target_link_libraries(shape_app shape_lib)
