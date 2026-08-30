add_library(shapes_lib STATIC
    circle.cpp
    square.cpp
    triangle.cpp
    rectangle.cpp
)

target_include_directories(shapes_lib PUBLIC ${CMAKE_SOURCE_DIR})
