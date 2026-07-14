cmake_minimum_required(VERSION 3.10)
project(SurgerySimulator)

add_executable(surgery_sim ${CMAKE_SOURCE_DIR}/main.cpp src/surgery_tools.cpp)
target_include_directories(surgery_sim PRIVATE ${CMAKE_SOURCE_DIR})
