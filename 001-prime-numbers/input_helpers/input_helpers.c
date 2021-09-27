#include "input_helpers.h"
#include "../../lib/stream_helpers/stream_helpers.h"

uint32_t get_valid_prime_ceiling(void) {
    uint32_t result;

    while (true) {
        result = get_uint32_from_stream(
                stdin,
                "Enter a number to use as the ceiling when calculating prime numbers:");

        if (is_valid_prime_ceiling(result)) {
            return result;
        }

        fprintf(stderr, "Not a valid number for the prime ceiling. Please try again.\n");
    }
}

bool is_valid_prime_ceiling(const uint32_t value) {
    return value >= 2;
}