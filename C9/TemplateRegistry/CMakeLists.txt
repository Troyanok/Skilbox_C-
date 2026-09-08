cmake_minimum_required(VERSION 3.10)
project(TemplateRegistry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(registry_app main.cpp)
