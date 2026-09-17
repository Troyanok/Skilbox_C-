set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

find_package(Qt5 REQUIRED COMPONENTS Widgets Multimedia)

qt5_add_resources(RESOURCE_FILES sounds.qrc)

add_library(gui_widgets STATIC
    include/mainwindow.h
    src/mainwindow.cpp
    ui/mainwindow.ui
    ${RESOURCE_FILES}
)

target_include_directories(gui_widgets
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(gui_widgets
    PUBLIC
        Qt5::Widgets
        Qt5::Multimedia
)
