/*************************
 *Garrett Boling
 *CPSC 2311 001
 *gboling@clemson.edu
 *************************/

#include "functions.h"
#include <ctype.h>

void numSentences(FILE* in, FILE* out) {
    int sentenceCount = 0;
    char prevChar = ' ';
    char currentChar;

    while ((currentChar = fgetc(in)) != EOF) {
        if (currentChar == '.' || currentChar == '?' || currentChar == '!') {
            sentenceCount++;
            while ((currentChar = fgetc(in)) == '.' || currentChar == '?' || currentChar == '!')
                continue;
        }
        prevChar = currentChar;
    }

    fprintf(out, "Total number of sentences: %d\n", sentenceCount);
}

void numWords(FILE* in, FILE* out) {
    int wordCount = 0;
    int inWord = 0;
    char currentChar;

    while ((currentChar = fgetc(in)) != EOF) {
        if (isspace(currentChar) || currentChar == '.' || currentChar == '?' || currentChar == '!') {
            if (inWord) {
                wordCount++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    fprintf(out, "Total number of words: %d\n", wordCount);
}