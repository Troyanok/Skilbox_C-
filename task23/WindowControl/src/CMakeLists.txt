add_library(window_lib STATIC
    window.cpp
    screen.cpp
)

target_include_directories(window_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
