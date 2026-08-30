cmake_minimum_required(VERSION 3.10)
project(ElfVillage)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_executable(elf_village main.cpp)
target_link_libraries(elf_village branch_lib)