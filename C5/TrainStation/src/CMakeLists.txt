add_library(station_lib STATIC
    train.cpp
    station.cpp
)

target_include_directories(station_lib PUBLIC ${CMAKE_SOURCE_DIR})
