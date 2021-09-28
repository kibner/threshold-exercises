#include "output_helpers.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

void print_number(const uint32_t value) {
    printf("%"PRIu32"\n", value);
}