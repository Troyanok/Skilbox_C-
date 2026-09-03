add_library(dog_lib STATIC
    dog.cpp
)

target_include_directories(dog_lib PUBLIC ${CMAKE_SOURCE_DIR})
