cmake_minimum_required(VERSION 3.20)
project(threshold-exercises C)

set(CMAKE_C_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-O2 -Werror -Wfatal-errors -Wpedantic -Wall -Wextra -Wabi -Wdouble-promotion -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat-truncation=2 -Wformat-y2k -Wnull-dereference -Winit-self -Wmissing-include-dirs -Wshift-overflow=2 -Wswitch-default -Wswitch-enum -Wsync-nand -Wunused-const-variable=2 -Wunknown-pragmas -Wstrict-overflow=5 -Wstringop-overflow=4 -Wmissing-noreturn -Walloc-zero -Walloca -Warith-conversion -Warray-bounds=2 -Wattribute-alias=2 -Wduplicated-branches -Wduplicated-cond -Wtrampolines -Wfloat-equal -Wshadow -Wunsafe-loop-optimizations -Wundef -Wunused-macros -Wcast-qual -Wcast-align=strict -Wwrite-strings -Wconversion -Wdangling-else -Wdate-time -Wjump-misses-init -Wlogical-op -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wpacked -Wpadded -Wredundant-decls -Wnested-externs -Winline -Winvalid-pch -Wvector-operation-performance -Wvla -Wdisabled-optimization -Wstack-protector -Wunsuffixed-float-constants")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(001-prime-numbers main.c ../lib/stream_helpers/stream_helpers.c ../lib/stream_helpers/stream_helpers.h input_helpers/input_helpers.c input_helpers/input_helpers.h calculations/brute_force.c calculations/brute_force.h output_helpers/output_helpers.c output_helpers/output_helpers.h)
