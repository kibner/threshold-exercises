#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "input_helpers/input_helpers.h"

int main(void) {
    const uint32_t prime_ceiling = get_valid_prime_ceiling();

    printf("Prime number ceiling: %"PRIu32"\n", prime_ceiling);

    return EXIT_SUCCESS;
}
