#include "input_helpers.h"
#include "../../lib/stream_helpers/stream_helpers.h"

uint32_t get_valid_upper_limit(void) {
    uint32_t result;

    while (true) {
        result = get_uint32_from_stream(
                stdin,
                "Enter a number to use as the upper limit when calculating prime numbers:");

        if (is_valid_upper_limit(result)) {
            return result;
        }

        fprintf(stderr, "Not a valid number for the upper limit. Please try again.\n");
    }
}

bool is_valid_upper_limit(const uint32_t value) {
    return value >= 2;
}