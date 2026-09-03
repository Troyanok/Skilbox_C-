cmake_minimum_required(VERSION 3.10)
project(SuperDog)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_executable(super_dog main.cpp)
target_link_libraries(super_dog dog_lib)
