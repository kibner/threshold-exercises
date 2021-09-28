#ifndef THRESHOLD_EXERCISES_BRUTE_FORCE_H
#define THRESHOLD_EXERCISES_BRUTE_FORCE_H

#include <stdint.h>

void calculate_prime_numbers(const uint32_t upper_limit, void (*const prime_found_callback)(const uint32_t));

#endif //THRESHOLD_EXERCISES_BRUTE_FORCE_H
