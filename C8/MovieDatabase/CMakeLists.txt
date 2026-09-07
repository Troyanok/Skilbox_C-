cmake_minimum_required(VERSION 3.14)
project(MovieDatabase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(src)

add_executable(movie_db_app main.cpp)
target_link_libraries(movie_db_app PRIVATE movie_database_lib)
