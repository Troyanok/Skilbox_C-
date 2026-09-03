cmake_minimum_required(VERSION 3.10)
project(SharedPtrUsage)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_executable(shared_ptr_usage main.cpp)
target_link_libraries(shared_ptr_usage dog_shared_lib)
