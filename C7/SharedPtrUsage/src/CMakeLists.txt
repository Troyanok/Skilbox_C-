add_library(dog_shared_lib STATIC
    dog.cpp
)

target_include_directories(dog_shared_lib PUBLIC ${CMAKE_SOURCE_DIR})
