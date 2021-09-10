//    START
//      Step 1 → Take integer variable A
//      Step 2 → Divide the variable A with (A-1 to 2)
//      Step 3 → If A is divisible by any value (A-1 to 2) it is not prime
//      Step 4 → Else it is prime
//    STOP
#include <stdio.h>
#include <limits.h>
#include <math.h>

int get_max_input_length(void);

int main(void) {
    const int MAX_INPUT_LENGTH = get_max_input_length();
    printf("Enter a number to use as the ceiling when calculating prime numbers:  \n");

    return 0;
}

int get_max_input_length(void) {
    return (int) log10(INT_MAX) + 1;
}