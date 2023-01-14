#include<stdio.h>
#include "getline.h"

#define LEN 256

void mystrncat(char*, char*, int);

int main()
{
    int toggle = 1;
    int c, atEnd;
    int n = 5;
    char lineA[LEN];
    char lineB[LEN];

    while ((c = getline((toggle ? lineA : lineB), LEN)) != 0)
    {
        if(toggle)
        {
            toggle = 0;
        }
        else
        {
            toggle = 1;
            mystrncat(lineA, lineB, n);
            printf("%s\n", lineA);
        }
    }

    return 0;
}

/* concatenate at most n characters of string ct to string s, terminate s with '\0' */
void mystrncat(char* s, char* t, int n)
{
    int i;

    while (*s != '\0')
    {
        s++;
    }

    for (i = 0; i < n && *t != '\0'; i++, s++, t++)
    {
        *s = *t;
    }

    *s = '\0';
}