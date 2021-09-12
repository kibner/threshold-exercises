//    START
//      Step 1 → Take integer variable A
//      Step 2 → Divide the variable A with (A-1 to 2)
//      Step 3 → If A is divisible by any value (A-1 to 2) it is not prime
//      Step 4 → Else it is prime
//    STOP
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

unsigned int get_max_input_length(void);

char *allocate_memory_for_string(unsigned int max_string_length);

const char *get_input_format_string(unsigned int max_input_string_length);

void get_vscanf_input(const char *input_format_string, ...);

int main(void) {
    const unsigned int max_input_length = get_max_input_length();
    const char *const input_format_string = get_input_format_string(max_input_length);
    unsigned int prime_ceiling;
    printf("Enter a number to use as the ceiling when calculating prime numbers:  \n");
    get_vscanf_input(input_format_string, &prime_ceiling);

    return 0;
}

unsigned int get_max_input_length(void) {
    return (unsigned int) log10(UINT_MAX) + 1;
}

char *allocate_memory_for_string(const unsigned int max_string_length) {
    unsigned int actual_length;

    if (max_string_length == UINT_MAX) {
        actual_length = max_string_length;
    } else {
        actual_length = max_string_length + 1;
    }

    return (char *) malloc(sizeof(char) * actual_length);
}

const char *get_input_format_string(const unsigned int max_input_string_length) {
    char *const input_format_string = allocate_memory_for_string(max_input_string_length);

    if (input_format_string == NULL) {
        printf("Memory not allocated.\n");

        return NULL;
    } else {
        snprintf(input_format_string, sizeof(char) * (max_input_string_length + 1), "%s%u%s", "%",
                 max_input_string_length, "u");

        return input_format_string;
    }
}

void get_vscanf_input(const char *const input_format_string, ...) {
    va_list ap;
    va_start(ap, input_format_string);
    vscanf(input_format_string, ap);
    va_end(ap);
}