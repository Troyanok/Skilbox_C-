add_library(swimmer_lib STATIC
    swimmer.cpp
)

target_include_directories(swimmer_lib PUBLIC ${CMAKE_SOURCE_DIR})
