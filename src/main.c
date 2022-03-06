#include "converters.h"
#include "random.h"
#include "names.h"
#include "stringfunctions.h"
#include <stdbool.h> 
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void helpOutput()
{
    printf("Known functions:\n");
    printf("help\t\tShow this output\n");
    printf("Pw\t\tShow a random password\n");
    printf("Num\t\tShow a pseudorandom number\n");
    printf("Name\t\tShow a random username\n");
    printf("d2h\t\tConvert decimal to hex\n");
    printf("d2b\t\tConvert decimal to binary\n");
    printf("d2c\t\tConvert decimal to character\n");
    printf("h2d\t\tConvert hex to decimal\n");
    printf("h2b\t\tConvert hex to binary\n");
    printf("h2s\t\tConvert hex to string\n");
    printf("b2d\t\tConvert binary to decimal\n");
    printf("b2h\t\tConvert binary to hex\n");
    printf("b2c\t\tConvert binary to character\n");
    printf("s2d\t\tConvert characters to decimal\n");
    printf("s2h\t\tConvert string to hex\n");
    printf("s2b\t\tConvert string to binary\n");
    printf("base64Enc\tEncode a base64 string\n");
    printf("base64Dec\tDecode a base64 string\n");
    printf("sLen\t\tGet string length\n");
    printf("sUpper\t\tConvert string to only uppercase\n");
    printf("sLower\t\tConvert string to only lowercase\n");
    printf("sRev\t\tReverse string\n");
    printf("sTimes\t\tOutput string multiple times\n");
    printf("sSplitNum\tSplit string after maximum length\n");
    printf("sSplitChar\tSplit string at specific character(s)\n");
    printf("sRem\t\tRemove specific characters of string\n");
    printf("lineAt\t\tGet only specific line\n");

    printf("\nMore settings on: https://github.com/jalupaja/MultiTool\n");
}

int main(int argc, char *argv[])
{
    /* TODO accept pipe input (stdin) */
    /* lastArg = input from pipe || argv[args - 1] */
    char lastArg[BUFSIZ];
    int args = argc;
    if (isatty(STDIN_FILENO)) {
        strncpy(lastArg, argv[args - 1], BUFSIZ);
    } else {
        scanf("%s", lastArg);
        args++;
    }

    if (args == 1) {
        helpOutput();
        return 0;
    } else if (!strcmp(argv[1], "Pw") || !strcmp(argv[1], "pw") || !strcmp(argv[1], "p")) {
        newSeed();
        if (args > 3) {
            outputPw(argv[2], lastArg);
        } else if (args > 2) {
            outputPw(lastArg, "");
        } else {
            outputPw("", "20");
        }
    } else if (!strcmp(argv[1], "Num") || !strcmp(argv[1], "num")) {
        newSeed();
        if (args > 3) {
            printf("%zd\n", ranNum(string2decimal(argv[2]), string2decimal(lastArg)));
        } else if (args > 2) {
            printf("%zd\n", ranNum(1, string2decimal(lastArg)));
        } else {
            printf("%zd\n", ranNum(1, 10));
        }
    } else if (!strcmp(argv[1], "Name") || !strcmp(argv[1], "name") || !strcmp(argv[1], "n")) {
        newSeed();
        if (args > 3) {
            outputRandomName(argv[2], lastArg);
        } else if (args > 2) {
            outputRandomName(lastArg, "");
        } else {
            outputRandomName("", "");
        }
    } else if (!strcmp(argv[1], "b2o") || !strcmp(argv[1], "bo")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *octal = NULL;
                binary2octal(argv[i], &octal);
                printf("08%s ", octal);
                free(octal);
            }
            char *octal = NULL;
            binary2octal(lastArg, &octal);
            printf("08%s\n", octal);
            free(octal);
        }
    } else if (!strcmp(argv[1], "b2d") || !strcmp(argv[1], "bd")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                printf("%lu ", binary2decimal(argv[i]));
            }
            printf("%lu\n", binary2decimal(lastArg));
        }
    } else if (!strcmp(argv[1], "b2h") || !strcmp(argv[1], "bh")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                outputBinaryAsHex(argv[i]);
                printf(" ");
            }
            outputBinaryAsHex(lastArg);
            printf("\n");
        }
    } else if (!strcmp(argv[1], "b2c") || !strcmp(argv[1], "b2s") || !strcmp(argv[1], "bc") || !strcmp(argv[1], "bs")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                printf("%c", binary2char(argv[i]));
            }
            printf("%c", binary2char(lastArg));
            printf("\n");
        }
    } else if (!strcmp(argv[1], "o2b") || !strcmp(argv[1], "ob")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *binary = NULL;
                octal2binary(argv[i], &binary);
                printf("08%s ", binary);
                free(binary);
            }
            char *binary = NULL;
            octal2binary(lastArg, &binary);
            printf("08%s\n", binary);
            free(binary);
        }
    } else if (!strcmp(argv[1], "o2d") || !strcmp(argv[1], "od")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                printf("%lu ", octal2decimal(argv[i]));
            }
            printf("%lu\n", octal2decimal(lastArg));
        }
    } else if (!strcmp(argv[1], "o2h") || !strcmp(argv[1], "oh")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                outputOctalAsHex(argv[i]);
                printf(" ");
            }
            outputOctalAsHex(lastArg);
            printf("\n");
        }
    } else if (!strcmp(argv[1], "o2c") || !strcmp(argv[1], "o2s") || !strcmp(argv[1], "oc") || !strcmp(argv[1], "os")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                printf("%c", octal2char(argv[i]));
            }
            printf("%c", octal2char(lastArg));
            printf("\n");
        }
    } else if (!strcmp(argv[1], "d2b") || !strcmp(argv[1], "db")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *binary = NULL;
                decimal2binary(string2decimal(argv[i]), &binary);
                printf("0b%s ", binary);
                free(binary);
            }
            char *binary = NULL;
            decimal2binary(string2decimal(lastArg), &binary);
            printf("0b%s\n", binary);
            free(binary);
        }
    } else if (!strcmp(argv[1], "d2o") || !strcmp(argv[1], "do")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *octal = NULL;
                decimal2octal(string2decimal(argv[i]), &octal);
                printf("08%s ", octal);
                free(octal);
            }
            char *octal = NULL;
            decimal2octal(string2decimal(lastArg), &octal);
            printf("08%s\n", octal);
            free(octal);
        }
    } else if (!strcmp(argv[1], "d2h") || !strcmp(argv[1], "dh")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                outputDecAsHex(string2decimal(argv[i]));
                printf(" ");
            }
            outputDecAsHex(string2decimal(lastArg));
            printf("\n");
        }
    } else if (!strcmp(argv[1], "d2c") || !strcmp(argv[1], "d2s") || !strcmp(argv[1], "dc") || !strcmp(argv[1], "ds")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                printf("%c ", decimal2char(string2decimal(argv[i])));
            }
            printf("%c ", decimal2char(string2decimal(lastArg)));
            printf("\n");
        }
    } else if (!strcmp(argv[1], "h2b") || !strcmp(argv[1], "hb")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *binary = NULL;
                hex2binary(argv[i], &binary);
                printf("0b%s ", binary);
                free(binary);
            }
            char *binary = NULL;
            hex2binary(lastArg, &binary);
            printf("0b%s\n", binary);
            free(binary);
        }
    } else if (!strcmp(argv[1], "h2o") || !strcmp(argv[1], "ho")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *octal = NULL;
                hex2octal(argv[i], &octal);
                printf("08%s ", octal);
                free(octal);
            }
            char *octal = NULL;
            hex2octal(lastArg, &octal);
            printf("08%s\n", octal);
            free(octal);
        }
    } else if (!strcmp(argv[1], "h2d") || !strcmp(argv[1], "hd")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                printf("%lu ", hex2decimal(argv[i]));
            }
            printf("%lu\n", hex2decimal(lastArg));
        }
    } else if (!strcmp(argv[1], "h2c") || !strcmp(argv[1], "h2s") || !strcmp(argv[1], "hc") || !strcmp(argv[1], "hs")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                printf("%c", hex2char(argv[i]));
            }
            printf("%c\n", hex2char(lastArg));
        }
    } else if (!strcmp(argv[1], "s2b") || !strcmp(argv[1], "sb") || !strcmp(argv[1], "c2b") || !strcmp(argv[1], "cb")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *binary = NULL;
                size_t argLen = strlen(argv[i]);
                for (size_t j = 0; j < argLen; j++) {
                    char2binary(argv[i][j], &binary);
                    printf("%s ", binary);
                }
                printf("\n");
                free(binary);
            }
            char *binary = NULL;
            size_t argLen = strlen(lastArg);
            for (size_t j = 0; j < argLen; j++) {
                char2binary(lastArg[j], &binary);
                printf("%s ", binary);
            }
            printf("\n");
            free(binary);
        }
    } else if (!strcmp(argv[1], "s2o") || !strcmp(argv[1], "so") || !strcmp(argv[1], "c2o") || !strcmp(argv[1], "co")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *octal = NULL;
                size_t argLen = strlen(argv[i]);
                for (size_t j = 0; j < argLen; j++) {
                    char2octal(argv[i][j], &octal);
                    printf("%s ", octal);
                }
                printf("\n");
                free(octal);
            }
            char *octal = NULL;
            size_t argLen = strlen(lastArg);
            for (size_t j = 0; j < argLen; j++) {
                char2octal(lastArg[j], &octal);
                printf("%s ", octal);
            }
            printf("\n");
            free(octal);
        }
    } else if (!strcmp(argv[1], "s2d") || !strcmp(argv[1], "sd") || !strcmp(argv[1], "c2d") || !strcmp(argv[1], "cd")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                size_t argLen = strlen(argv[i]);
                for (size_t j = 0; j < argLen; j++) {
                    printf("%lu ", char2decimal(argv[i][j]));
                }
            }
            size_t argLen = strlen(lastArg);
            for (size_t j = 0; j < argLen; j++) {
                printf("%lu\n", char2decimal(lastArg[j]));
            }
        }
    } else if (!strcmp(argv[1], "s2h") || !strcmp(argv[1], "sh") || !strcmp(argv[1], "c2h") || !strcmp(argv[1], "ch")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *hex = NULL;
                size_t argLen = strlen(argv[i]);
                for (size_t j = 0; j < argLen; j++) {
                    char2hex(argv[i][j], &hex);
                    printf("%s ", hex);
                }
                printf("\n");
                free(hex);
            }
            char *hex = NULL;
            size_t argLen = strlen(lastArg);
            for (size_t j = 0; j < argLen; j++) {
                char2hex(lastArg[j], &hex);
                printf("%s ", hex);
            }
            printf("\n");
            free(hex);
        }
    } else if (!strcmp(argv[1], "base64Enc") || !strcmp(argv[1], "base64enc") || !strcmp(argv[1], "b64e")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *b64 = NULL;
                base64encode(argv[i], &b64);
                printf("%s\n", b64);
                free(b64);
            }
            char *b64 = NULL;
            base64encode(lastArg, &b64);
            printf("%s\n", b64);
            free(b64);
        }
    } else if (!strcmp(argv[1], "base64Dec") || !strcmp(argv[1], "base64dec") || !strcmp(argv[1], "b64d")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                char *plain = NULL;
                base64decode(argv[i], &plain);
                printf("%s\n", plain);
                free(plain);
            }
            char *plain = NULL;
            base64decode(lastArg, &plain);
            printf("%s\n", plain);
            free(plain);
        }
    } else if (!strcmp(argv[1], "sLen") || !strcmp(argv[1], "slen")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                printf("%zu ", stringLen(argv[i]));
            }
            printf("%zu\n", stringLen(lastArg));
        } else
            printf("0\n");
    } else if (!strcmp(argv[1], "sUpper") || !strcmp(argv[1], "supper") || !strcmp(argv[1], "su")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                outputStringUpper(argv[i]);
                printf(" ");
            }
            outputStringUpper(lastArg);
            printf("\n");
        }
    } else if (!strcmp(argv[1], "sLower") || !strcmp(argv[1], "slower") || !strcmp(argv[1], "sl")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                outputStringLower(argv[i]);
                printf(" ");
            }
            outputStringLower(lastArg);
            printf("\n");
        }
    } else if (!strcmp(argv[1], "sRev") || !strcmp(argv[1], "srev")) {
        if (args > 2) {
            for (int i = 2; i < args - 1; i++) {
                outputStringReverse(argv[i]);
                printf(" ");
            }
            outputStringReverse(lastArg);
            printf("\n");
        }
    } else if (!strcmp(argv[1], "sTimes") || !strcmp(argv[1], "stimes") || !strcmp(argv[1], "st")) {
        if (args > 3) {
            if (lastArg[0] >= '0' && lastArg[0] <= '9') {
                outputStringTimes(argv[2], string2decimal(lastArg));
            } else {
                outputStringTimes(lastArg, string2decimal(argv[2]));
            }
        } else if (args > 2) {
            outputStringTimes(lastArg, 2);
        }
        printf("\n");
    } else if (!strcmp(argv[1], "sSplitNum") || !strcmp(argv[1], "ssplitnum") || !strcmp(argv[1], "ssn")) {
        if (args > 3) {
            if (strlen(lastArg) > strlen(argv[2]))
                outputStringSplitNum(lastArg, string2decimal(argv[2]));
            else
                outputStringSplitNum(argv[2], string2decimal(lastArg));
        } else if (args > 2) {
            outputStringSplitNum(lastArg, (strlen(lastArg) / 4));
        }
    } else if (!strcmp(argv[1], "sSplitChar") || !strcmp(argv[1], "ssplitchar") || !strcmp(argv[1], "ssc")) {
        if (args > 3) {
            if (argv[2][0] == '-') {
                if (argv[2][1] == '=')
                    outputStringSplitBeforeChar(lastArg, &(argv[2][2]));
                else if (argv[2][strlen(argv[2]) - 1] == '=')
                    outputStringSplitAfterChar(lastArg, &(argv[2][1]));
                else
                    outputStringSplitChar(lastArg, &(argv[2][1]));
            } else if (lastArg[0] == '-') {
                if (lastArg[1] == '=')
                    outputStringSplitChar(argv[2], &(lastArg[2]));
                else if (lastArg[strlen(lastArg) - 1] == '=')
                    outputStringSplitChar(argv[2], &(lastArg[1]));
                else
                    outputStringSplitChar(argv[2], &(lastArg[1]));
            } else {
                if (lastArg[0] == '=')
                    outputStringSplitBeforeChar(argv[2], &(lastArg[1]));
                else if (lastArg[strlen(lastArg) - 1] == '=')
                    outputStringSplitAfterChar(argv[2], lastArg);
                else
                    outputStringSplitChar(argv[2], lastArg);
            }
        } else if (args > 2) {
            outputStringSplitChar(lastArg, " ");
        }
        printf("\n");
    } else if (!strcmp(argv[1], "sRem") || !strcmp(argv[1], "srem") || !strcmp(argv[1], "sr")) {
        if (args > 3) {
            if (argv[2][0] == '-')
                outputStringRemove(lastArg, &(argv[2][1]));
            else if (lastArg[0] == '-')
                outputStringRemove(argv[2], &(lastArg[1]));
            else
                outputStringRemove(argv[2], lastArg);
            printf("\n");
        }
    } else {
        helpOutput();
        return 1;
    }

    return 0;
}
