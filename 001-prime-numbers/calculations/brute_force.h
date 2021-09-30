#ifndef THRESHOLD_EXERCISES_BRUTE_FORCE_H
#define THRESHOLD_EXERCISES_BRUTE_FORCE_H

#include <stdbool.h>
#include <stdint.h>

typedef void (*const prime_found_callback_type)(const uint32_t);

void calculate_prime_numbers(const uint32_t upper_limit, prime_found_callback_type prime_found_callback);

bool is_prime(const uint32_t possible_prime);

#endif //THRESHOLD_EXERCISES_BRUTE_FORCE_H
