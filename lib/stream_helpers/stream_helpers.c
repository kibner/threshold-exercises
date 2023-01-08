#include "stream_helpers.h"
#include <errno.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FORMAT_STRING_LENGTH ((const uint8_t)(11))
#define OUT_OF_RANGE_ERROR_MESSAGE "Out of range error when parsing unsigned long from string.\n"

uint32_t get_uint32_from_stream(FILE *const stream, const char *const prompt_message) {
    uint32_t result;
    char input_buffer[INPUT_FORMAT_STRING_LENGTH];
    const char *fgets_result;

    while (true) {
        if (prompt_message not_eq NULL) {
            printf("%s\n", prompt_message);
        }

        fgets_result = fgets(input_buffer, INPUT_FORMAT_STRING_LENGTH, stream);

        if (has_fgets_erred(fgets_result)) {
            fprintf(stderr, "Unknown error reading from stream.\n");

            continue;
        }

        result = parse_uint32_string(input_buffer);

        if (errno == 0) {
            return result;
        }
    }
}

bool has_fgets_erred(const char *const fgets_result) {
    return fgets_result == NULL;
}

uint32_t parse_uint32_string(const char *const uint32_string) {
    errno = 0;
    unsigned long parsed_number = strtoul(uint32_string, NULL, 0);

    switch (errno) {
        case 0:
            // successfully parsed
            break;
        case ERANGE:
            fprintf(stderr, OUT_OF_RANGE_ERROR_MESSAGE);
            parsed_number = 0;
            break;
        default:
            fprintf(stderr, "Unknown error when parsing unsigned long from string.\n");
            parsed_number = 0;
            break;
    }

    return (uint32_t) parsed_number;
}
