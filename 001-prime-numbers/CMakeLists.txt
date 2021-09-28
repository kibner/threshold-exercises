cmake_minimum_required(VERSION 3.20)
project(threshold-exercises C)

add_executable(001-prime-numbers main.c ../lib/stream_helpers/stream_helpers.c ../lib/stream_helpers/stream_helpers.h input_helpers/input_helpers.c input_helpers/input_helpers.h calculations/brute_force.c calculations/brute_force.h output_helpers/output_helpers.c output_helpers/output_helpers.h)
