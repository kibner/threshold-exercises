#include <errno.h>
#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FORMAT_STRING_LENGTH ((const uint8_t)(11))

uint32_t get_valid_prime_ceiling(void);

bool is_valid_prime_ceiling(unsigned long ulong_value);

uint32_t get_uint32_from_stream(FILE *stream, const char *prompt_message);

bool has_fgets_erred(const char *fgets_result);

uint32_t parse_uint32_string(const char *ulong_string);

int main(void) {
    const uint32_t prime_ceiling = get_valid_prime_ceiling();

    printf("Prime number ceiling: %"PRIu32, prime_ceiling);

    return EXIT_SUCCESS;
}

uint32_t get_valid_prime_ceiling(void) {
    uint32_t result;

    while (true) {
        result = get_uint32_from_stream(
                stdin,
                "Enter a number to use as the ceiling when calculating prime numbers:");

        if (is_valid_prime_ceiling(result)) {
            return result;
        }

        fprintf(stderr, "Not a valid number for the prime ceiling. Please try again.\n");
    }
}

bool is_valid_prime_ceiling(const unsigned long ulong_value) {
    return ulong_value >= 2;
}

uint32_t get_uint32_from_stream(FILE *const stream, const char *const prompt_message) {
    uint32_t result;
    char input_buffer[INPUT_FORMAT_STRING_LENGTH];
    const char *fgets_result;

    while (true) {
        if (prompt_message not_eq NULL) {
            printf("%s\n", prompt_message);
        }

        fgets_result = fgets(input_buffer, INPUT_FORMAT_STRING_LENGTH, stream);

        if (has_fgets_erred(fgets_result)) {
            fprintf(stderr, "Unknown error reading from stream.\n");

            continue;
        }

        result = parse_uint32_string(input_buffer);

        if (errno == 0) {
            return result;
        }
    }
}

bool has_fgets_erred(const char *const fgets_result) {
    return fgets_result == NULL;
}

uint32_t parse_uint32_string(const char *const ulong_string) {
    errno = 0;
    unsigned long parsed_number = strtoul(ulong_string, NULL, 0);

    switch (errno) {
        case 0:
            // successfully parsed
            break;
        case ERANGE:
            fprintf(stderr, "Out of range error when parsing unsigned long from string.\n");
            parsed_number = 0;
            break;
        default:
            fprintf(stderr, "Unknown error when parsing unsigned long from string.\n");
            parsed_number = 0;
            break;
    }

    return (uint32_t) parsed_number;
}