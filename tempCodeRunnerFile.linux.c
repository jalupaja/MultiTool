#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <ctype.h>

void aufgabe1A( void );
void aufgabe1B( void );
void test1( void );
void aufgabe2( void );

int main ( void )
{
    aufgabe2();
    return EXIT_SUCCESS;
}

int recFib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else 
        return (recFib(n-2) + recFib(n-1));
}
void aufgabe1A( void )
{
    int eingabe;
    char input[10];
    printf("Gib eine ganze, positive Zahl ein: ");
    fgets(input, 9, stdin);
    sscanf(input, "%d", &eingabe);
    if (eingabe > 0) printf("%d\n", recFib(eingabe));
}

long nonrecFib(int n)
{
    long erg = 0;
    if (n == 0);
    else if (n == 1) erg = 1;
    else 
    {
        long twoBack = 0, oneBack = 1;
        for (int i = 2; i <= n; i++)
        {
            erg = twoBack + oneBack;
            twoBack = oneBack;
            oneBack = erg;
        }
    }
    return erg;
}
void aufgabe1B( void )
{
    int eingabe;
    long erg;
    char input[10];
    printf("Gib eine ganze, positive Zahl ein: ");
    fgets(input, 9, stdin);
    sscanf(input, "%d", &eingabe);
    printf("%d\n", nonrecFib(eingabe));    
}

void test1( void ) /*--> nicht rekursive Funktion ist sehr viel schneller, da
hier nicht immer wieder eine Funktion aufgerufen werden muss, dadurch
werden viele audfrufe und dadurch viel Zeit gespart.*/
{
    //https://stackoverflow.com/questions/1688133/how-can-i-test-the-performance-of-a-c-function
    struct timeval t0, t1;
    unsigned int i;

    for (int i = 0; i < 2; i++)
    {
        int a = recFib(i);
        int b = nonrecFib(i);
        printf("%s(%d) : %d %d\n", ((a==b) ? "OK" : "FEHLER"), i, a, b);
    }

    gettimeofday(&t0, NULL);
    for(i = 0; i < 50; i++)
        recFib(i);
    gettimeofday(&t1, NULL);
    printf("Did %u calls in %g seconds\n", i, t1.tv_sec - t0.tv_sec + 1E-6 * (t1.tv_usec - t0.tv_usec));

    gettimeofday(&t0, NULL);
    for(i = 0; i < 50; i++)
        nonrecFib(i);
    gettimeofday(&t1, NULL);
    printf("Did %u calls in %g seconds\n", i, t1.tv_sec - t0.tv_sec + 1E-6 * (t1.tv_usec - t0.tv_usec));
}

void strEingabe(char* str, int maxLen)
{
    printf("Gib eine Zeichenkette ein: ");
    fgets(str, maxLen, stdin);
}

void strSwap(char* str)
{
    int len = strlen(str);
    char tmpStr[len + 1];
    strncpy(tmpStr, str, len);
    int j = 0;
    char *ptrStr = str, *ptrStrTmp = (&tmpStr[len -1]);
    for(int i = (len - 1); i >= 0; i--)
    {
        *ptrStr = *ptrStrTmp;
        ptrStrTmp--;
        ptrStr++;
    }
}

void strLower(char* str)
{
    char *ptr = str;
    for (int i = 0; i < strlen(str); i++)
    {
        *ptr = tolower(*ptr);
        ptr++;
    }
}

int isPaly(char* str)
{
    char *ptrStart = (&str[1]), *ptrEnd = (&str[strlen(str) -1]);
    for (int i = 0; i < strlen(str) /2; i++)
    {
        if (*ptrStart != *ptrEnd) return 0;
        ptrStart++;
        ptrEnd--;
    }
    return 1;
}

void aufgabe2( void )
{
    char input[51];
    strEingabe(input, 50);
    strLower(input);
    strSwap(input);
    printf("%s ist %s Palyndrom.\n", input, (isPaly(input)) ? "ein" : "kein");
}