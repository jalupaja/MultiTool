#ifndef RANDOM_H
#define RANDOM_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int_fast32_t ranNum(int_fast32_t, int_fast32_t);

void newSeed();

void randomPw(char **, bool, bool, bool, bool, uint_fast32_t);

void outputPw(char *, char *);

#endif
