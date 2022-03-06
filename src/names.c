#include "names.h"
#include "colorOutput.h"
#include "converters.h"
#include "random.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t getFileSize(FILE *file)
{
    if (file != NULL) {
        size_t fSize = 0;
        char ch;
        do {
            ch = fgetc(file);
            if (ch == '\n')
                fSize++;
        } while (ch != EOF);
        return fSize;
    } else {
        return -1;
    }
}

void getRandomLine(char *line, size_t maxLen, FILE *file, size_t fSize)
{
    line[0] = '\0';
    rewind(file);
    if (file != NULL) {
        size_t fIndex = ranNum(1, fSize);
        for (size_t i = 0; i < fIndex; i++) {
            fgets(line, maxLen, file);
        }
        line[strlen(line) - 1] = '\0';
    }
}

void outputRandomName(char *options, char *path)
{
    char pFile1[260];
    char pFile2[260];
    if (path[0] == '\0') {
        strncpy(pFile1, DEFAULTPATH, sizeof pFile1);
        strncpy(pFile2, DEFAULTPATH, sizeof pFile2);
    } else {
        strncpy(pFile1, path, sizeof pFile1);
        strncpy(pFile2, path, sizeof pFile2);
    }

    strcat(pFile1, "/firstList.txt");
    strcat(pFile2, "/secondList.txt");
    FILE *file1 = fopen(pFile1, "r");
    FILE *file2 = fopen(pFile2, "r");

    if (file1 == NULL || file2 == NULL) {
        outError("File(s) missing!");
        return;
    }

    /* OPTIONS */
    size_t optLen = strlen(options);
    size_t repeatCounter = 1, minLength = 3, maxLength = 20;
    char wordCase = 'n';

    for (size_t i = 0; i < optLen; i++) {
        switch (options[i]) {
        case 'l':
        case 'L':
            wordCase = 'l';
            break;
        case 'u':
        case 'U':
            wordCase = 'u';
            break;
        case 'n':
        case 'N':
            wordCase = 'n';
            break;
        case 'r':
        case 'R':
            repeatCounter = string2decimal(&(options[i + 1]));
            break;
        case 'm':
        case 'M':
            minLength = string2decimal(&(options[i + 1]));
            break;
        case 'x':
        case 'X':
            maxLength = string2decimal(&(options[i + 1]));
            break;
        }
    }

    char one[60];
    char two[60];
    size_t fSize1 = getFileSize(file1);
    size_t fSize2 = getFileSize(file2);

    size_t currentSize;

    for (size_t i = 0; i < repeatCounter; i++) {
        do {
            getRandomLine(one, sizeof one, file1, fSize1);
            currentSize = strlen(one);
            if (currentSize < minLength || currentSize > maxLength)
                continue;
            getRandomLine(two, sizeof two, file2, fSize2);
            currentSize = strlen(one) + strlen(two);
        } while (currentSize < minLength || currentSize > maxLength);

        /* change case option */
        switch (wordCase) {
        case 'n': // first Letters to upper Chars
            one[0] = toupper(one[0]);
            two[0] = toupper(two[0]);
            break;
        case 'l': // lower
            one[0] = tolower(one[0]);
            two[0] = tolower(two[0]);
            break;
        case 'u': // complete upper Chars
            size_t oneLen = strlen(one);
            for (size_t i = 0; i < oneLen; i++)
                one[i] = toupper(one[i]);
            size_t twoLen = strlen(two);
            for (size_t i = 0; i < twoLen; i++)
                two[i] = toupper(two[i]);
            break;
        }

        printf("%s%s\n", one, two);
    }
    fclose(file1);
    fclose(file2);
}

void randomName(char *options, char *path, char **output)
{
    /* TODO nothing done yet */
}
