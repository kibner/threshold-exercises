#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "input_helpers/input_helpers.h"
#include "output_helpers/output_helpers.h"
#include "calculations/brute_force.h"

int main(void) {
    const uint32_t prime_ceiling = get_valid_prime_ceiling();

    printf("Printing all prime numbers until %"PRIu32":\n", prime_ceiling);
    calculate_prime_numbers(prime_ceiling, print_number);

    return EXIT_SUCCESS;
}
