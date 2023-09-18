#include <stdio.h>
#include <assert.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]); // Making sure the user put in 3 arguments on the command line before proceeding.
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");  // Opening a file pointer to read from the input file.
    FILE* outputFile = fopen(argv[2], "w"); // Opening a file pointer to write to the output file.

    assert(inputFile != NULL && "Error opening input file");
    assert(outputFile != NULL && "Error opening output file");

    numSentences(inputFile, outputFile);

    // Reset file pointer to the beginning of the file
    fseek(inputFile, 0, SEEK_SET);

    numWords(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

