cmake_minimum_required(VERSION 3.10)
project(Shapes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(shapes_app main.cpp)

target_include_directories(shapes_app PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(shapes_app shapes_lib)