cmake_minimum_required(VERSION 3.10)
project(ShoppingCart)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(src)

add_executable(shopping_cart main.cpp)
target_link_libraries(shopping_cart PRIVATE shopping_cart_lib)
