cmake_minimum_required(VERSION 3.16)
project(ColorfulCircle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME}
    main.cpp
    desc.h
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
