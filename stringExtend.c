#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

char* delCharInString(char* str, char argc)
{
    int i = 0, n = 0;

    for (i = 0; i<=strlen(str); i++)
    {
        if(str[i] != argc)
        {
            str[n] = str[i];
            n++;
        }

    }

    return str;
}


char* delNonAlphaNum(char* str)
{
    int i, n = 0;

    for(i = 0; i<strlen(str); i++)
    {
        if((str[i] >= '0' && str[i] <= '9')||(str[i] >= 'A' && str[i] <= 'Z')||(str[i] >= 'a' && str[i] <= 'z'))
        {
            str[n] = str[i];
            n++;
        }
    }

    str[n] = '\0';

    return str;
}

char* delDouble(char* str, char c)
{
    int i, n = 1;

    for (i = 1; i<strlen(str); i++)
    {
        if((str[i] != str[i-1])||(str[i] != c))
        {
            str[n] = str[i];
            n++;
        }
    }

    return str;
}

int letterCountInString(const char *string, char argc)
{
    int count = 0, i = 0;

    for (i = 0; i<strlen(string); i++)
    {
        if (string[i] == argc)

            count ++;
    }

    return count;
}

int wordCount(const char* str)
{
    int i = 0, count = (strlen(str) > 0) ? 1 : 0;
    char strCopy[strlen(str)*2];

    strcpy(strCopy, str);
    delDouble(strCopy, ' ');

    for(i = 0; i<strlen(str); i++)
    {
        count += (strCopy[i] == ' ') ? 1 : 0;
    }

    return count;
}

char* invertString(char* str)
{
    int i = 0;
    char buffer;

    for(i = 0; i<strlen(str)/2; i++)
    {
        buffer = str[i];
        str[i] = str[strlen(str) - (i + 1)];
        str[strlen(str) - (i + 1)] = buffer;
    }

    return str;
}

char* getAnagramm(char* anagramm, const char* str)
{
    srand(time(NULL));
    char buffer;
    int i;
    strcpy(anagramm, str);

    for(i = 0; i<strlen(str); i++)
    {
        int strlength = strlen(str) - 1;
        int randGen = (sqrt(2.0) * pow( 10.0, rand()));
        int rdm = randGen % strlength;
        buffer = anagramm[rdm];
        anagramm[rdm] = anagramm[i];
        anagramm[i] = buffer;
    }

    return anagramm;
}

int isPalindrome(const char* str)
{
    char strCopy[strlen(str)];
    strcpy(strCopy, str);
    int i;

    for(i = 0; i<strlen(str)/2; i++)
    {
        if(str[i] != str[strlen(str - (i + 1))])
           return 0;
    }

    return 1;
}

int binToDec(const char* bin)
{
    int dec = 0;

    int i;

    for (i = 0; i < strlen(bin); i++)
    {
        switch (bin[i])
        {
            case '1' :

                dec += pow(2.0, strlen(bin) - 1 - i);
                break;

            case '0' :
                break;

            default :

                printf("Error - NotABinary");
                return 0;
        }
    }

    return dec;
}
