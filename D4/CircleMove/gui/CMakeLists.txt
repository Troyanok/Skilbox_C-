set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Quick Qml)

qt5_add_resources(RESOURCE_FILES resources.qrc)

add_library(gui_widgets STATIC
    ${RESOURCE_FILES}
)

target_link_libraries(gui_widgets
    PUBLIC
        Qt5::Quick
        Qt5::Qml
)