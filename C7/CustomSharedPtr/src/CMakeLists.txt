add_library(custom_shared_ptr_lib STATIC
    toy.cpp
    shared_ptr_toy.cpp
)

target_include_directories(custom_shared_ptr_lib PUBLIC ${CMAKE_SOURCE_DIR})
