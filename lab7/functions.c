//
// Created by gboling on 2/25/2025.
//
#include "functions.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void inplace_swap(uint8_t *x, uint8_t *y) {
    // taken from the assignment details, repeatedly XOR the two values
    // to swap them in place
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void print_table(uint8_t a, uint8_t b) {
    char *headers[] = {"Variable Name", "Decimal", "Hexadecimal", "Binary"};
    const int num_cols = sizeof(headers) / sizeof(headers[0]);

    // convert a and b to string with space for EOL (decimal)
    char a_dec[4], b_dec[4];
    snprintf(a_dec, sizeof(a_dec), "%u", a);
    snprintf(b_dec, sizeof(b_dec), "%u", b);

    // convert a and b to string with space for EOL (hexadecimal)
    char a_hex[5], b_hex[5];
    snprintf(a_hex, sizeof(a_hex), "0x%02X", a);
    snprintf(b_hex, sizeof(b_hex), "0x%02X", b);

    // convert a and b to string with space for EOL (binary)
    char *a_bin = convert_to_binary(a);
    char *b_bin = convert_to_binary(b);

    char *var1_name = "a";
    char *var2_name = "b";

    // organize data into rows
    char *rows[][4] = {
        {var1_name, a_dec, a_hex, a_bin},
        {var2_name, b_dec, b_hex, b_bin}
    };

    // calculate max column widths
    int col_widths[num_cols];
    for (int col = 0; col < num_cols; col++) {
        col_widths[col] = (int)strlen(headers[col]);
        for (int row = 0; row < 2; row++) {
            int current_len = strlen(rows[row][col]);
            if (current_len > col_widths[col]) {
                col_widths[col] = current_len;
            }
        }
    }

    // print headers
    for (int i = 0; i < num_cols; i++) {
        printf("%-*s|", col_widths[i], headers[i]);
    }
    printf("\n");

    // print horizontal line
    for (int i = 0; i < num_cols; i++) {
        for (int j = 0; j < col_widths[i]; j++) {
            printf("-");
        }
        printf("|");
    }
    printf("\n");

    // print rows for a and b
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < num_cols; col++) {
            printf("%-*s|", col_widths[col], rows[row][col]);
        }
        printf("\n");

    }
    printf("\n");

    // free memory allocated for binary strings to avoid memory leaks
    free(a_bin);
    free(b_bin);
}

char* convert_to_binary(uint8_t x) {
  // Allocate memory for a string that will hold the binary representation of x
  // plus space for the null terminator
  char *bin_str = malloc(9 * sizeof(char));
  if (!bin_str)
      return NULL;

  // build a binary string using bitwise operators from MSB to LSB
  for (int i = 7; i >= 0; i--) {
    bin_str[7 - i] = (x & (1 << i)) ? '1' : '0';
  }

  // append null terminator to the end of the string and return the string
  bin_str[8] = '\0';
  return bin_str;
}
