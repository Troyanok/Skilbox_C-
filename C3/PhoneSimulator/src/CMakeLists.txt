add_library(phone_lib STATIC
    contact.cpp
    phone.cpp
)

target_include_directories(phone_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
