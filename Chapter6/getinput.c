#include <stdio.h>
#include "getinput.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int isvalidchar(int c);
int isinstring(int c, char* s);

static int buf[BUFSIZE];   /* buffer for ungetch */
static int bufp = 0;       /* next free position in buf */

/* Get char from either buffer or input */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

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

/* checks if c is a valid char for a word */
int isvalidchar(int c)
{
    if (isalnum(c))
    {
        return isalnum(c);
    }

    char *validletters = "\\!@#$^&*().,<>?/_";

    return isinstring(c, validletters);
}

/* checks if character c is in string s */
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

/* retrieves the next line of characters from the input and returns the length of the line */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if(c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}
