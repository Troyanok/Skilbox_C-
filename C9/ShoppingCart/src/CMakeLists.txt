add_library(shopping_cart_lib STATIC shopping_cart.cpp)
target_include_directories(shopping_cart_lib PUBLIC ${CMAKE_SOURCE_DIR})
