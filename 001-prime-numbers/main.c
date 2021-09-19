//    START
//      Step 1 → Take integer variable A
//      Step 2 → Divide the variable A with (A-1 to 2)
//      Step 3 → If A is divisible by any value (A-1 to 2) it is not prime
//      Step 4 → Else it is prime
//    STOP

#include <errno.h>
#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FORMAT_STRING_LENGTH ((const uint8_t)(11))

bool has_fgets_erred(const char *fgets_result);

uint32_t parse_ulong_string(const char *ulong_string);

bool is_valid_ulong(unsigned long ulong_value);

uint32_t get_ulong_from_stream(FILE *stream, const char *prompt_message);

int main(void) {
    uint32_t prime_ceiling = get_ulong_from_stream(
            stdin,
            "Enter a number to use as the ceiling when calculating prime numbers:");

    printf("Prime number ceiling: %"PRIu32, prime_ceiling);

    return EXIT_SUCCESS;
}

uint32_t get_ulong_from_stream(FILE *stream, const char *prompt_message) {
    if (prompt_message not_eq NULL) {
        printf("%s\n", prompt_message);
    }

    char input_buffer[INPUT_FORMAT_STRING_LENGTH];
    const char *fgets_result = fgets(input_buffer, INPUT_FORMAT_STRING_LENGTH, stream);

    if (has_fgets_erred(fgets_result)) {
        printf("Unknown error reading from console.\n");

        return get_ulong_from_stream(stream, prompt_message);
    }

    const uint32_t ulong_value = parse_ulong_string(input_buffer);

    if (not is_valid_ulong(ulong_value)) {
        printf("Error validating input. Please try again.\n");

        return get_ulong_from_stream(stream, prompt_message);
    }

    return ulong_value;
}

bool has_fgets_erred(const char *fgets_result) {
    return fgets_result == NULL;
}

uint32_t parse_ulong_string(const char *ulong_string) {
    errno = 0;
    const unsigned long parsed_number = strtoul(ulong_string, NULL, 0);

    if (errno not_eq 0) {
        if (errno == ERANGE) {
            printf("Out of range error when parsing unsigned long from string.\n");
        } else {
            printf("Unknown error when parsing unsigned long from string.\n");
        }

        return 0;
    }

    return (uint32_t) parsed_number;
}

bool is_valid_ulong(const unsigned long ulong_value) {
    return ulong_value > 0;
}