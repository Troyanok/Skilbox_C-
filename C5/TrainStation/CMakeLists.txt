cmake_minimum_required(VERSION 3.10)
project(TrainStation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_executable(train_station main.cpp)
target_link_libraries(train_station station_lib)
