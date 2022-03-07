#include "colorOutput.h"
#include <stdio.h>

void clearScreen()
{
    printf("\033c");
}

void outError(char *output)
{
    printf("%sERROR: %s%s\n", RED, DEFAULT_COLOR, output);
}

void outSuccess(char *output)
{
    printf("%sSUCCESS: %s%s\n", GREEN, DEFAULT_COLOR, output);
}
