project(001-prime-numbers C)

add_executable(
        001-prime-numbers main.c
        ${CMAKE_SOURCE_DIR}/lib/stream_helpers/stream_helpers.c
        input_helpers/input_helpers.c
        calculations/brute_force.c
        output_helpers/output_helpers.c
)
