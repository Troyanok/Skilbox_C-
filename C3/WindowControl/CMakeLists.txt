cmake_minimum_required(VERSION 3.10)
project(WindowControl)

add_subdirectory(src)

add_executable(window_sim main.cpp)

target_link_libraries(window_sim PRIVATE window_lib)
