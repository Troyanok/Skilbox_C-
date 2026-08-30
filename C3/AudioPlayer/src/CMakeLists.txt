add_library(audio_lib STATIC
    track.cpp
    audio_player.cpp
)

target_include_directories(audio_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
