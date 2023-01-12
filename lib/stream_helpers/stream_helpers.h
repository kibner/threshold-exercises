#ifndef THRESHOLD_EXERCISES_STREAM_HELPERS_H
#define THRESHOLD_EXERCISES_STREAM_HELPERS_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint32_t get_uint32_from_stream(FILE *const stream, const char *const prompt_message);

bool has_fgets_erred(const char *const fgets_result);

bool is_negative_uint32_string(const char *const uint32_string);

uint32_t parse_uint32_string(const char *const uint32_string);

#endif //THRESHOLD_EXERCISES_STREAM_HELPERS_H
