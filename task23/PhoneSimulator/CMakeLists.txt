cmake_minimum_required(VERSION 3.10)
project(PhoneSimulator)

add_subdirectory(src)

add_executable(phone_sim main.cpp)

target_link_libraries(phone_sim PRIVATE phone_lib)
