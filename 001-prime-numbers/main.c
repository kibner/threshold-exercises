//    START
//      Step 1 → Take integer variable A
//      Step 2 → Divide the variable A with (A-1 to 2)
//      Step 3 → If A is divisible by any value (A-1 to 2) it is not prime
//      Step 4 → Else it is prime
//    STOP

#include <errno.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FORMAT_STRING_LENGTH ((const uint8_t)(11))

bool has_fgets_erred(const char *fgets_result);

unsigned long parse_ulong_string(const char *input_buffer);

bool is_valid_ulong(unsigned long prime_ceiling);

int main(void) {
    char input_buffer[INPUT_FORMAT_STRING_LENGTH];
    unsigned long prime_ceiling;
    char *fgets_result;

    printf("Enter a number to use as the ceiling when calculating prime numbers:  \n");
    fgets_result = fgets(input_buffer, INPUT_FORMAT_STRING_LENGTH, stdin);

    if (has_fgets_erred(fgets_result)) {
        printf("Error reading from console.\n");
        return EXIT_FAILURE;
    }

    prime_ceiling = parse_ulong_string(input_buffer);

    if (not is_valid_ulong(prime_ceiling)) {
        printf("Invalid input. Please restart and try again.\n");
        return EXIT_FAILURE;
    }

    printf("%lu", prime_ceiling);

    return EXIT_SUCCESS;
}

bool has_fgets_erred(const char *fgets_result) {
    return fgets_result == NULL;
}

unsigned long parse_ulong_string(const char *input_buffer) {
    unsigned long parsed_number;
    errno = 0;
    parsed_number = strtoul(input_buffer, NULL, 0);

    if (errno == ERANGE) {
        return 0;
    }

    return parsed_number;
}

bool is_valid_ulong(const unsigned long prime_ceiling) {
    return prime_ceiling > 0;
}