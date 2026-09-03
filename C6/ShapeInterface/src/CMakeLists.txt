add_library(shape_lib STATIC
    circle.cpp
    rectangle.cpp
    triangle.cpp
)

target_include_directories(shape_lib PUBLIC ${CMAKE_SOURCE_DIR})
