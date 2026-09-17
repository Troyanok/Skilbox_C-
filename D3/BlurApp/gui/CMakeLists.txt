set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

find_package(Qt5 REQUIRED COMPONENTS Widgets Concurrent)

add_library(gui_widgets STATIC
    include/mainwindow.h
    include/desc.h
    src/mainwindow.cpp
    src/desc.cpp
    ui/mainwindow.ui
)

target_include_directories(gui_widgets
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(gui_widgets
    PUBLIC
        Qt5::Widgets
        Qt5::Concurrent
)
