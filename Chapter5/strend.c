#include<stdio.h>
#include "getline.h"

#define LEN 256

int strend(char*, char*);

int main()
{
    int toggle = 1;
    int c, atEnd;
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
            atEnd = strend(lineA, lineB);
            printf("At end of line: %s\n", (atEnd ? "true" : "false"));
        }
    }

    return 0;
}

/* returns 1 if the string t occurs at the end of s, 0 otherwise */
int strend(char* s, char* t)
{
    char* sWork = s;
    char* tWork = t;

    while (*sWork != '\0')
    {
        sWork++;
    }

    while (*tWork != '\0')
    {
        tWork++;
    }

    for ( ; (sWork >= s) && (tWork >= t); sWork--, tWork--)
    {
        if (*sWork != *tWork)
        {
            return 0;
        }
    }

    if (tWork + 1 == t)
    {
        return 1;
    }

    return 0;
}
