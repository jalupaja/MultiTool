#include "stringfunctions.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void outputStringLen(char *string)
{
    printf("%zd\n", strlen(string));
}

size_t stringLen(char *string)
{
    return strlen(string);
}

void outputStringUpper(char *string)
{
    while (*string != '\0') {
        printf("%c", toupper(*string++));
    }
    printf("\n");
}

void stringUpper(char *string, char **output)
{
    *output = malloc(strlen(string));
    char *ptr = *output;
    while (*string != '\0') {
        *(ptr++) = toupper(*string++);
    }
    *ptr = '\0';
}

void outputStringLower(char *string)
{
    while (*string != '\0') {
        printf("%c", tolower(*string++));
    }
    printf("\n");
}

void stringLower(char *string, char **output)
{
    *output = malloc(strlen(string));
    char *ptr = *output;
    while (*string != '\0') {
        *(ptr++) = tolower(*string++);
    }
    *ptr = '\0';
}

void outputStringReverse(char *string)
{
    for (int i = strlen(string) - 1; i >= 0; i--) {
        printf("%c", string[i]);
    }
    printf("\n");
}

void stringReverse(char *string, char **output)
{
    size_t strLen = strlen(string);
    *output = malloc(strLen);
    for (size_t i = 0; i < strLen; i++)
        (*output)[i] = string[strLen - i - 1];
    (*output)[strLen] = '\0';
}

void outputStringTimes(char *string, uint_fast32_t times)
{
    for (uint_fast32_t i = 0; i < times; i++)
        printf("%s", string);
    printf("\n");
}

void stringTimes(char *string, uint_fast32_t times, char **output)
{
    size_t strLen = strlen(string);
    *output = malloc(strLen * times + 1);
    for (uint_fast32_t i = 0; i < times; i++)
        strncpy(&((*output)[i * strLen]), string, strLen);
}

void outputStringSplitNum(char *string, uint_fast32_t num)
{
    if (num < 1) {
        printf("%s\n", string);
    } else {
        char tmp[num];
        size_t strLen = strlen(string);
        size_t i;
        for (i = 0; i < (strLen / num); i++) {
            strncpy(tmp, string + (i * num), num);
            printf("%s\n", tmp);
        }
        if (strLen / num) {
            strncpy(tmp, string + (i * num), num);
            printf("%s\n", tmp);
        }
    }
}

void outputStringSplitChar(char *string, char *characters)
{
    while (*string != '\0') {
        if (strchr(characters, *string) == NULL)
            printf("%c", *string);
        else
            printf("\n");
        string++;
    }
}

void outputStringSplitBeforeChar(char *string, char *characters)
{
    while (*string != '\0') {
        if (strchr(characters, *string) == NULL)
            printf("%c", *(string++));
        else
            printf("\n%c", *(string++));
    }
}

void outputStringSplitAfterChar(char *string, char *characters)
{
    while (*string != '\0') {
        if (strchr(characters, *string) == NULL)
            printf("%c", *(string++));
        else
            printf("%c\n", *(string++));
    }
}

void ooutputStringRemove(char *string, char *toRemove)
{
    char *nextS = strstr(string, toRemove);
    size_t remLen = strlen(toRemove);
    while (nextS != NULL) {
        *nextS = '\0';
        printf("%s", string);
        string = nextS + (remLen);
        nextS = strstr(string, toRemove);
    }
    printf("\n");
}
void outputStringRemove(char *string, char *toRemove)
{
    char *ptr = string;
    char *nextS = strstr(ptr, toRemove);
    size_t remLen = strlen(toRemove);
    while (nextS != NULL) {
        while (ptr != nextS) {
            printf("%c", *(ptr++));
        }
        ptr += remLen;
        nextS = strstr(ptr, toRemove);
    }
    while (*ptr != '\0') {
        printf("%c", *(ptr++));
    }
}

void stringRemove(char *string, char *toRemove, char **output)
{
    *output = malloc(strlen(string));
    char *ptrOut = *output;
    char *ptrIn = string;
    char *nextS = strstr(ptrIn, toRemove);
    size_t remLen = strlen(toRemove);
    while (nextS != NULL) {
        while (ptrIn != nextS) {
            *(ptrOut++) = *(ptrIn++);
        }
        ptrIn += remLen;
        nextS = strstr(ptrIn, toRemove);
    }
    while (*ptrIn != '\0') {
        *(ptrOut++) = *(ptrIn++);
    }
}

void outputLineAt(char *string, uint_fast32_t line)
{
    if (line < 1) {
        printf("\n");
        return;
    }
    char *ptr = string;
    char *nextS = strchr(ptr, '\n');
    while (1) {
        if (--line > 0) {
            ptr = nextS + 1;
            nextS = strchr(ptr , '\n'); 
        } else if (nextS != NULL) {
            break;
        } else {
            while (*ptr != '\n' && *ptr != '\0') {
                printf("%c", *(ptr++));
            }
            break;
        }
    }
    printf("\n");
}
