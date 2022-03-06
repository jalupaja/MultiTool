#include "converters.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decHexTable = "0123456789ABCDEF";

void removeBinarySuffix(char **binary)
{
    if ((*binary)[0] == '0' && ((*binary)[1] == 'b' || (*binary)[1] == 'B'))
        *binary = &((*binary)[2]);
}

void removeOctalSuffix(char **octal)
{
    if ((*octal)[0] == '0' && (*octal)[1] == '8')
        *octal = &((*octal)[2]);
}

void removeHexSuffix(char **hex)
{
    if ((*hex)[0] == '0' && ((*hex)[1] == 'x' || (*hex)[1] == 'X'))
        *hex = &((*hex)[2]);
}

int_fast64_t string2decimal(char *str)
{
    if (str[0] < '0' || str[0] > '9')
        return 0;
    int_fast64_t ret;
    sscanf(str, "%ld", &ret);
    return ret;
}

uint_fast64_t system2decimal(char *str, short system)
{
    if (system == 2)
        removeBinarySuffix(&str);
    else if (system == 8)
        removeOctalSuffix(&str);
    else if (system == 16)
        removeHexSuffix(&str);
    uint_fast64_t ret = 0;
    uint_fast32_t multi = 1;
    uint_fast32_t i = strlen(str);
    while (i > 0) {
        if (str[i - 1] >= '0' && str[i - 1] <= '9')
            ret += (str[i - 1] - 48) * multi;
        else if (str[i - 1] >= 'A' && str[i - 1] <= 'F')
            ret += (str[i - 1] - 55) * multi;
        else if (str[i - 1] >= 'a' && str[i - 1] <= 'f')
            ret += (str[i - 1] - 87) * multi;
        multi *= system;
        i--;
    }
    return ret;
}

void outputBinaryAsHex(char *binary)
{
    printf("0x%x", (unsigned)system2decimal(binary, 2));
}

void outputOctalAsHex(char *octal)
{
    printf("0x%x", (unsigned)system2decimal(octal, 8));
}

void outputDecAsHex(unsigned decimal)
{
    printf("0x%x", decimal);
}

void outputCharAsHex(char character)
{
    printf("0x%x", character);
}

void binary2octal(char *binary, char **octal)
{
    removeBinarySuffix(&binary);
    char subString[4];
    subString[3] = '\0';
    uint_fast32_t binLen = strlen(binary);
    uint_fast8_t octalLen = (binLen / 3) + 1;
    uint_fast8_t i = 0;
    short sub = (binLen % 3) ? (3 - binLen % 3) : 0;
    if (sub) {
        *octal = malloc(++octalLen);
        strncpy(subString, binary, binLen % 3);
        subString[binLen % 3] = '\0';
        (*octal)[i++] = system2decimal(subString, 2) + 48;
    } else {
        *octal = malloc(octalLen);
    }
    (*octal)[octalLen - 1] = '\0';
    while (i < octalLen - 1) {
        strncpy(subString, &(binary[(i * 3) - sub]), 3);
        (*octal)[i++] = system2decimal(subString, 2) + 48;
    }
}

uint_fast64_t binary2decimal(char *binary)
{
    return system2decimal(binary, 2);
}

void binary2hex(char *binary, char **hex)
{
    removeBinarySuffix(&binary);
    char subString[5];
    subString[4] = '\0';
    uint_fast32_t binLen = strlen(binary);
    uint_fast8_t hexLen = (binLen / 4) + 1;
    uint_fast8_t i = 0;
    short sub = (binLen % 4) ? (4 - binLen % 4) : 0;
    if (sub) {
        *hex = malloc(++hexLen);
        strncpy(subString, binary, binLen % 4);
        subString[binLen % 4] = '\0';
        (*hex)[i++] = decHexTable[system2decimal(subString, 2)];
    } else {
        *hex = malloc(hexLen);
    }
    (*hex)[hexLen - 1] = '\0';
    while (i < hexLen - 1) {
        strncpy(subString, &(binary[(i * 4) - sub]), 4);
        (*hex)[i++] = decHexTable[system2decimal(subString, 2)];
    }
}

char binary2char(char *binary)
{
    return (char)system2decimal(binary, 2);
}

void singleOctalchar2binary(char octal, char **binary)
{
    octal -= 48;
    (*binary)[3] = '\0';
    for (short i = 2; i >= 0; i--) {
        (*binary)[i] = octal % 2 ? '1' : '0';
        octal /= 2;
    }
}

void octal2binary(char *octal, char **binary)
{
    removeOctalSuffix(&octal);
    uint_fast32_t octalLen = strlen(octal);
    *binary = malloc(octalLen * 3 + 1);
    (*binary)[octalLen * 3] = '\0';
    char *addBinary = malloc(4);
    char *addFirstBinary = malloc(4);
    addBinary[3] = '\0';
    short sub = 2;
    singleOctalchar2binary(octal[0], &addBinary);
    for (short i = 0; i < 3; i++) {
        if (addBinary[i] == '1') {
            sub = i;
            break;
        }
    }
    strncpy(addFirstBinary, &(addBinary[sub]), 3 - sub);
    addFirstBinary[3 - sub] = '\0';
    strncpy(*binary, addFirstBinary, 3 - sub);
    free(addFirstBinary);
    for (uint_fast32_t i = 1; i < octalLen; i++) {
        singleOctalchar2binary(octal[i], &addBinary);
        strncpy(&((*binary)[(i * 3) - sub]), addBinary, 3);
    }
    free(addBinary);
}

uint_fast64_t octal2decimal(char *octal)
{
    return system2decimal(octal, 8);
}

void octal2hex(char *octal, char **hex)
{
    decimal2hex(system2decimal(octal, 8), hex);
}

char octal2char(char *octal)
{
    return (char)octal2decimal(octal);
}

void decimal2binary(uint64_t decimal, char **binary)
{
    if (!decimal) {
        *binary = malloc(2);
        *binary = "0";
        return;
    }
    short i = 19;
    short j;
    while (!(decimal >> i))
        i--;
    *binary = malloc(i + 1);
    for (j = 0; i >= 0; j++) {
        (*binary)[j] = (decimal >> i & 1) ? '1' : '0';
        i--;
    }
    (*binary)[j] = '\0';
}

void decimal2octal(uint64_t decimal, char **octal)
{
    char *binary = NULL;
    decimal2binary(decimal, &binary);
    binary2octal(binary, &(*octal));
    /* !!!TODO!!!: free(binary);*/
}

void decimal2hex(uint64_t decimal, char **hex)
{
    char *binary = NULL;
    decimal2binary(decimal, &binary);
    binary2hex(binary, &(*hex));
    /* !!!TODO!!!: free (binary);*/
}

char decimal2char(int decimal)
{
    return (char)decimal;
}

void singleHexchar2binary(char hex, char **binary)
{
    if (hex <= '9') {
        hex -= 48;
    } else if (hex <= 'F') {
        hex -= 55;
    } else if (hex <= 'f') {
        hex -= 87;
    }
    (*binary)[4] = '\0';
    for (short i = 3; i >= 0; i--) {
        (*binary)[i] = hex % 2 ? '1' : '0';
        hex /= 2;
    }
}

void hex2binary(char *hex, char **binary)
{
    removeHexSuffix(&hex);
    uint_fast32_t hexLen = strlen(hex);
    *binary = malloc(hexLen * 4 + 1);
    (*binary)[hexLen * 4] = '\0';
    char *addBinary = malloc(5);
    char *addFirstBinary = malloc(5);
    addBinary[4] = '\0';
    short sub = 3;
    singleHexchar2binary(hex[0], &addBinary);
    for (short i = 0; i < 4; i++) {
        if (addBinary[i] == '1') {
            sub = i;
            break;
        }
    }
    strncpy(addFirstBinary, &(addBinary[sub]), 4 - sub);
    addFirstBinary[4 - sub] = '\0';
    strncpy(*binary, addFirstBinary, 4 - sub);
    free(addFirstBinary);
    for (uint_fast32_t i = 1; i < hexLen; i++) {
        singleHexchar2binary(hex[i], &addBinary);
        strncpy(&((*binary)[(i * 4) - sub]), addBinary, 4);
    }
    free(addBinary);
}

void hex2octal(char *hex, char **octal)
{
    decimal2octal(system2decimal(hex, 16), octal);
}

uint_fast64_t hex2decimal(char *hex)
{
    return system2decimal(hex, 16);
}

char hex2char(char *hex)
{
    return (char)hex2decimal(hex);
}

void char2binary(char character, char **binary)
{
    decimal2binary((uint64_t)character, binary);
}

void char2octal(char character, char **octal)
{
    char *binary = NULL;
    decimal2binary((uint64_t)character, &binary);
    binary2octal(binary, &(*octal));

    /*!!!TODO!!! free(binary);*/
}

uint_fast64_t char2decimal(char character)
{
    return (uint_fast64_t)character;
}

void char2hex(char character, char **hex)
{
    decimal2hex(character, hex);
}

void base64encode(char *str, char **base64)
{ // based on: https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
    const char *B64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    size_t len = strlen(str);
    *base64 = malloc((len + 2) / 3 * 4);
    unsigned char *p = (unsigned char *)str;
    char *str2 = base64[0];
    size_t j = 0, pad = len % 3;
    const size_t last = len - pad;

    for (size_t i = 0; i < last; i += 3) {
        int n = (int)p[i] << 16 | (int)p[i + 1] << 8 | p[i + 2];
        str2[j++] = B64chars[n >> 18];
        str2[j++] = B64chars[n >> 12 & 0x3F];
        str2[j++] = B64chars[n >> 6 & 0x3F];
        str2[j++] = B64chars[n & 0x3F];
    }
    if (pad) /// Set padding
    {
        int n = --pad ? (int)p[last] << 8 | p[last + 1] : p[last];
        str2[j++] = B64chars[pad ? n >> 10 & 0x3F : n >> 2];
        str2[j++] = B64chars[pad ? n >> 4 & 0x03F : n << 4 & 0x3F];
        str2[j++] = pad ? B64chars[n << 2 & 0x3F] : '=';
    }
}

void base64decode(char *base64, char **str)
{ // based on: https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
    const int B64index[256] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63, 62, 62, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 63,
        0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
    };
    size_t len = strlen(base64);
    if (len == 0) {
        *str = malloc(1);
        (*str)[0] = '\0';
        return;
    }

    unsigned char *p = (unsigned char *)base64;
    size_t j = 0,
           pad1 = len % 4 || p[len - 1] == '=',
           pad2 = pad1 && (len % 4 > 2 || p[len - 2] != '=');
    const size_t last = (len - pad1) / 4 << 2;
    *str = malloc(last / 4 * 3 + pad1 + pad2);
    unsigned char *str2 = (unsigned char *)str[0];

    for (size_t i = 0; i < last; i += 4) {
        int n = B64index[p[i]] << 18 | B64index[p[i + 1]] << 12 | B64index[p[i + 2]] << 6 | B64index[p[i + 3]];
        str2[j++] = n >> 16;
        str2[j++] = n >> 8 & 0xFF;
        str2[j++] = n & 0xFF;
    }
    if (pad1) {
        int n = B64index[p[last]] << 18 | B64index[p[last + 1]] << 12;
        str2[j++] = n >> 16;
        if (pad2) {
            n |= B64index[p[last + 2]] << 6;
            str2[j++] = n >> 8 & 0xFF;
        }
    }
}
