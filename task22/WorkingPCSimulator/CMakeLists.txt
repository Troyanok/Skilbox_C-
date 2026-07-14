cmake_minimum_required(VERSION 3.10)
project(ComputerSim)

add_subdirectory(src)

add_executable(computer_sim main.cpp)

target_link_libraries(computer_sim PRIVATE computer_lib)
