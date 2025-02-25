#include <stdio.h>

#include "functions.h"

int main(int argc, char **argv[]) {
    if (argc != 3) {
        printf("Usage: %s <a> <b>\n", *argv[0]);
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