#include "brute_force.h"
#include <stdint.h>

void calculate_prime_numbers(const uint32_t prime_ceiling, void (*const output_callback)(const uint32_t)) {
    for (uint32_t i = 2; i <= prime_ceiling; i++) {
        output_callback(i);
    }
}
