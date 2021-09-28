#include "brute_force.h"
#include <stdbool.h>
#include <stdint.h>

void calculate_prime_numbers(const uint32_t upper_limit, void (*const prime_found_callback)(const uint32_t)) {
    const uint32_t first_prime = 2;
    const uint32_t second_prime = 3;

    if (upper_limit >= first_prime) {
        prime_found_callback(first_prime);

        for (uint32_t test_value = second_prime; test_value <= upper_limit; test_value = test_value + 2) {
            bool is_prime = true; // todo: test if test_value is a prime or not

            if (is_prime) {
                prime_found_callback(test_value);
            }
        }
    }
}
