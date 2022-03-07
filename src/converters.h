#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <stdint.h>

int_fast32_t string2decimal(char *);
uint_fast32_t system2decimal(char *, short);

void outputBinaryAsHex(char *);
void outputOctalAsHex(char *);
void outputDecAsHex(unsigned);
void outputCharAsHex(char);

void binary2octal(char *, char **);
uint_fast32_t binary2decimal(char *);
void binary2hex(char *, char **);
char binary2char(char *);

void octal2binary(char *, char **);
uint_fast32_t octal2decimal(char *);
void octal2hex(char *, char **);
char octal2char(char *);

void decimal2binary(uint_fast32_t, char **);
void decimal2octal(uint_fast32_t, char **);
void decimal2hex(uint_fast32_t, char **);
char decimal2char(int);

void hex2binary(char *, char **);
void hex2octal(char *, char **);
uint_fast32_t hex2decimal(char *);
char hex2char(char *);

void char2binary(char, char **);
void char2octal(char, char **);
uint_fast32_t char2decimal(char);
void char2hex(char, char **);

void base64encode(char *, char **);
void base64decode(char *, char **);

#endif
