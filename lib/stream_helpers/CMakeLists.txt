project(stream_helpers)

add_library(stream_helpers stream_helpers.c)

target_include_directories(
        stream_helpers
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
