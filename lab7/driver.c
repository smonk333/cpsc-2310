#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#define MIN 0
#define MAX 255

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <a> <b>\n", argv[0]);
        return 1;
    }

    // making variables to hold the signed integer values of a and b
    // because if the user's CLI input is a negative number,
    // an uint8_t variable will not store it properly
    // (integer underflow). so the program can't check to see
    // if the user's input is in-range on negative numbers, because
    // they automatically roll back over to the maximum value
    int a_chk = atoi(argv[1]);
    int b_chk = atoi(argv[2]);

    // typecasting the integers from above to uint8_t variables
    // just to prove that this works.
    uint8_t a = (uint8_t)a_chk;
    uint8_t b = (uint8_t)b_chk;

    if (a_chk < MIN || a_chk > MAX || b_chk < MIN || b_chk > MAX) {
        printf("Invalid input, numbers must be between 0 and 255 inclusive\n");
        return 1;
    }

    char *a_bin = convert_to_binary(a);
    char *b_bin = convert_to_binary(b);

    printf("a in binary: %s\n", a_bin);
    printf("b in binary: %s\n", b_bin);

    inplace_swap(&a, &b);

    a_bin = convert_to_binary(a);
    b_bin = convert_to_binary(b);

    printf("a in binary (after swap): %s\n", a_bin);
    printf("b in binary (after swap): %s\n", b_bin);

    return 0;
}
