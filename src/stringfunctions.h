#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

#include <stdlib.h>

void outputStringLen(char *);
size_t stringLen(char *);

void outputStringUpper(char *);
void stringUpper(char *, char **);

void outputStringLower(char *);
void stringLower(char *, char **);

void outputStringReverse(char *);
void stringReverse(char *, char **);

void outputStringTimes(char *, size_t);
void stringTimes(char *, size_t, char **);

void outputStringSplitNum(char *, size_t);

void outputStringSplitChar(char *, char *);

void outputStringSplitBeforeChar(char *, char *);

void outputStringSplitAfterChar(char *, char *);

void outputStringRemove(char *, char *);
void stringRemove(char *, char *, char **);

void outputLineAt(char *, size_t);

#endif
