// todo:
// - Several of the functions listed look like helpers (e.g., has_fgets_erred); I'd declare+define those as statics so
// they don't pollute the global namespace and aren't exported as part of an API
// - If you're inspecting errno and handling unknown cases, it's nice to print out the unexpected value and to use
// strerror()
// - Using #define results in text replacement, so by using it you'll wind up with two copies of the out-of-range error
// message in the binary.  This is pretty minor, but I'd probably declare it as a file-level static const char *
// - That being said, the while(true) and error printing logic feels a little out of place to me.  I don't like infinite
// loops in code, especially in library functions, and doubly-so when there's no way to escape them. I'd expect to see
// the result of your parsing written into an output parameter and the API function return an error code of some kind.
// The user can then decide to loop if they want. You could also do things like return a code on ^C as an indicator to
// bail from the loop.

#include "stream_helpers.h"
#include <errno.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        if (is_negative_uint32_string(input_buffer)) {
            fprintf(stderr, OUT_OF_RANGE_ERROR_MESSAGE);
            result = 0;
        } else {
            result = parse_uint32_string(input_buffer);
        }

        if (errno == 0) {
            return result;
        }
    }
}

bool has_fgets_erred(const char *const fgets_result) {
    return fgets_result == NULL;
}

bool is_negative_uint32_string(const char *const uint32_string) {
    return strchr(uint32_string, '-') not_eq NULL;
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
