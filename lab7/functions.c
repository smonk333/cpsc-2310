//
// Created by gboling on 2/25/2025.
//
#include "functions.h"
#include <stdlib.h>
#include <stdint.h>

void inplace_swap(uint8_t *x, uint8_t *y) {
    // taken from the assignment details, repeatedly XOR the two values
    // to swap them in place
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
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