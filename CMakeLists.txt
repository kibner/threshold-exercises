cmake_minimum_required(VERSION 3.20)

project(threshold-exercises C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CC_COVERAGE_COMPILE_FLAGS "-O2 -Werror -Weverything -Wno-declaration-after-statement")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CC_COVERAGE_COMPILE_FLAGS}")

option(BUILD_SHARED_LIBS ON)

# Executables
add_subdirectory(${PROJECT_SOURCE_DIR}/001_prime_numbers ${PROJECT_SOURCE_DIR}/001_prime_numbers/bin)

# Libraries
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/stream_helpers ${PROJECT_SOURCE_DIR}/lib/stream_helpers/bin)
