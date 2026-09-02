cmake_minimum_required(VERSION 3.10)
project(RestaurantKitchen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_executable(restaurant_kitchen main.cpp)
target_link_libraries(restaurant_kitchen kitchen_lib)
