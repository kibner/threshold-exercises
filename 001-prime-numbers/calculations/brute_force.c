#include "brute_force.h"
#include <stdbool.h>
#include <stdint.h>

#define FIRST_PRIME ((const uint32_t)(2))
#define SECOND_PRIME ((const uint32_t)(3))

void calculate_prime_numbers(const uint32_t upper_limit, prime_found_callback_type prime_found_callback) {
    if (upper_limit >= FIRST_PRIME) {
        prime_found_callback(FIRST_PRIME);

        for (uint32_t test_value = SECOND_PRIME;
             test_value <= upper_limit;
             test_value = test_value + 2
                ) {
            if (is_prime(test_value)) {
                prime_found_callback(test_value);
            }
        }
    }
}

bool is_prime(const uint32_t possible_prime) {
    if (possible_prime < FIRST_PRIME) {
        return false;
    }

    if (possible_prime == FIRST_PRIME) {
        return true;
    }

    const uint32_t upper_limit = possible_prime / 2;

    for (uint32_t test_value = SECOND_PRIME;
         test_value <= upper_limit;
         test_value = test_value + 2
            ) {
        if (possible_prime % test_value == 0) {
            return false;
        }
    }

    return true;
}