cmake_minimum_required(VERSION 3.10)
project(AverageArray)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(average_array main.cpp)
target_include_directories(average_array PRIVATE ${CMAKE_SOURCE_DIR})
