#include "random.h"
#include "converters.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t ranNum(size_t min, size_t max)
{
    /* TODO: should be a lot better, needs a different seed on startup*/
    return min + (long)(max * (rand() / (RAND_MAX + 1.0)));
}

void newSeed()
{
    /* TODO same here ^^ */
    srand((uintmax_t)time(NULL));
}

void randomPw(char **output, bool useLower, bool useUpper, bool useNum, bool useSpec, size_t maxLength)
{
    char alphabet[95];
    int alphabetLen = 0;
    if (useLower)
        for (int i = 'a'; i <= 'z'; i++)
            alphabet[alphabetLen++] = i;
    if (useUpper)
        for (int i = 'A'; i <= 'Z'; i++)
            alphabet[alphabetLen++] = i;
    if (useNum)
        for (int i = '0'; i <= '9'; i++)
            alphabet[alphabetLen++] = i;
    if (useSpec) {
        char specChars[33] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
        for (size_t i = 0; i < strlen(specChars); i++)
            alphabet[alphabetLen++] = specChars[i];
    }
    if (alphabetLen < 1) {
        *output = malloc(1);
        (*output)[0] = '\0';
    }
    alphabet[alphabetLen] = '\0';
    *output = malloc(maxLength);
    if (maxLength < 1)
        maxLength = 20;
    for (size_t i = 0; i < maxLength; i++) {
        (*output)[i] = alphabet[ranNum(0, alphabetLen - 1)];
    }
    (*output)[maxLength] = '\0';
}

void outputPw(char *options, char *lengthInput)
{
    bool useLower = false, useUpper = false, useNum = false, useSpec = false;
    int_fast64_t repeatCounter = 1, len = 20;

    if (isdigit(lengthInput[0]))
        len = string2decimal(lengthInput);
    else if (isdigit(options[0])) {
        len = string2decimal(options);
        options = lengthInput;
    }

    for (size_t i = 0; i < strlen(options); i++) {
        switch (options[i]) {
        case 'l':
        case 'L':
            useLower = true;
            break;
        case 'u':
        case 'U':
            useUpper = true;
            break;
        case 'n':
        case 'N':
            useNum = true;
            break;
        case 's':
        case 'S':
            useSpec = true;
            break;
        case 'r':
        case 'R':
            repeatCounter = string2decimal(&(options[i + 1]));
            break;
        }
    }

    if (!useLower && !useUpper && !useNum && !useSpec) {
        useLower = true;
        useUpper = true;
        useNum = true;
        useSpec = true;
    }

    char *output = NULL;
    for (int i = 0; i < repeatCounter; i++) {
        randomPw(&output, useLower, useUpper, useNum, useSpec, len);
        printf("%s\n", output);
        free(output);
    }
}
