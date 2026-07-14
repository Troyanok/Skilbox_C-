cmake_minimum_required(VERSION 3.10)
project(ComputerSim)

add_subdirectory(src)

add_executable(audio_sim main.cpp)

target_link_libraries(audio_sim PRIVATE audio_lib)
