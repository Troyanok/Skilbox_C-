add_library(branch_lib STATIC
    branch.cpp
)

target_include_directories(branch_lib PUBLIC ${CMAKE_SOURCE_DIR})