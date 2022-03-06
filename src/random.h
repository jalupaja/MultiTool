#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>
#include <stdbool.h>

size_t ranNum(size_t, size_t);

void newSeed();

void randomPw(char **, bool, bool, bool, bool, size_t);

void outputPw(char *, char *);

#endif
