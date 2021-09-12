//    START
//      Step 1 → Take integer variable A
//      Step 2 → Divide the variable A with (A-1 to 2)
//      Step 3 → If A is divisible by any value (A-1 to 2) it is not prime
//      Step 4 → Else it is prime
//    STOP
#include <stdarg.h>
#include <stdio.h>

#define INPUT_FORMAT_STRING_LENGTH ((const unsigned int)(3))

void set_input_format_string(char (*format_string)[INPUT_FORMAT_STRING_LENGTH], size_t buffer_size);

void get_vscanf_input(const char *input_format_string, ...);

int main(void) {
    char input_format_string[INPUT_FORMAT_STRING_LENGTH];
    unsigned int prime_ceiling;

    set_input_format_string(&input_format_string, sizeof(input_format_string));
    printf("Enter a number to use as the ceiling when calculating prime numbers:  \n");
    get_vscanf_input(input_format_string, &prime_ceiling);

    return 0;
}

void set_input_format_string(char (*format_string)[INPUT_FORMAT_STRING_LENGTH], size_t buffer_size) {
    snprintf(*format_string, buffer_size, "%s", "%u");
}

void get_vscanf_input(const char *const input_format_string, ...) {
    va_list ap;
    va_start(ap, input_format_string);
    vscanf(input_format_string, ap);
    va_end(ap);
}