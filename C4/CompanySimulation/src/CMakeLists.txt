add_library(company_lib STATIC
    manager.cpp
    team.cpp
    company.cpp
)

target_include_directories(company_lib PUBLIC ${CMAKE_SOURCE_DIR})