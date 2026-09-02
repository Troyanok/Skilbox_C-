add_library(kitchen_lib STATIC
    order.cpp
    kitchen.cpp
    courier.cpp
)

target_include_directories(kitchen_lib PUBLIC ${CMAKE_SOURCE_DIR})
