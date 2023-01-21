#include "getword.h"
#include "getch.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int isvalidchar(int c);
int isinstring(int c, char* s);

/* get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
    {
        ;
    }

    if (c != EOF)
    {
        *w++ = c;
    }

    if (!isvalidchar(c))
    {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
    {
        if (!isvalidchar(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

int isvalidchar(int c)
{
    if (isalnum(c))
    {
        return isalnum(c);
    }

    char *validletters = "\\!@#$^&*().,<>?/_";

    return isinstring(c, validletters);
}

int isinstring(int c, char* s)
{
    do
    {
        if (*s == c)
        {
            return 1;
        }
    }
    while (*(s++) != '\0');

    return 0;
}
