#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "input_helpers/input_helpers.h"
#include "output_helpers/output_helpers.h"
#include "calculations/brute_force.h"

int main(void) {
    const uint32_t upper_limit = get_valid_upper_limit();
    printf("Printing all prime numbers until %"PRIu32":\n", upper_limit);
    calculate_prime_numbers(upper_limit, print_number);

    return EXIT_SUCCESS;
}
