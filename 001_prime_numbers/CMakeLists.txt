project(001-prime-numbers C)

add_executable(
        001_prime_numbers
        main.c
        input_helpers/input_helpers.c
        calculations/brute_force.c
        output_helpers/output_helpers.c
)

target_link_libraries(001_prime_numbers stream_helpers)

target_include_directories(
        001_prime_numbers PUBLIC
        ${PROJECT_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/lib/stream_helpers
)
