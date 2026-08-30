add_library(computer_lib STATIC
    ram.cpp
    cpu.cpp
    disk.cpp
    gpu.cpp
    kbd.cpp
)

target_include_directories(computer_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
