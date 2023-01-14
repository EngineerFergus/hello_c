#include<stdio.h>
#include "getline.h"

#define LEN 256

void mystrncpy(char*, char*, int);

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
            mystrncpy(lineA, lineB, n);
            printf("%s", lineA);
        }
    }

    return 0;
}

/* copies at most n characters from t to s */
void mystrncpy(char* s, char* t, int n)
{
    int i;

    for (i = 0; i < n && *t != '\0'; i++, t++, s++)
    {
        *s = *t;
    }

    for ( ; i < n; i++, s++)
    {
        *s = '\0';
    }
}