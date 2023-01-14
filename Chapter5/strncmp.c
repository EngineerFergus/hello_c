#include<stdio.h>
#include "getline.h"

#define LEN 256

int mystrncmp(char*, char*, int);

int main()
{
    int toggle = 1;
    int c, cmp;
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
            cmp = mystrncmp(lineA, lineB, n);
            printf("%d\n", cmp);
        }
    }

    return 0;
}

/* compare at most n characters of string s to t. return <0 is s<t, 0 if equal, >0 if s>t */
int mystrncmp(char* s, char* t, int n)
{
    int i = 0;
    for ( ; i < n && *s != '\0' && *t != '\0'; i++, s++, t++)
    {
        if (*s != *t)
        {
            return *s < *t ? -1 : 1;
        }
    }

    if (*s == '\0' && *t == '\0')
    {
        return 0;
    }
    else if (*s != '\0' && *t == '\0')
    {
        return 1;
    }
    else if (*t != '\0' && *s == '\0')
    {
        return -1;
    }

    return 0;
}
