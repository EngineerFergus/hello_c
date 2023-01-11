#include <stdio.h>
#include <ctype.h>
#include "getch.h"

int getint(int *);
int getfloat(int *);

int main()
{
    int myInt, myChar;

    while((myChar = getint(&myInt)) != EOF)
    {
        if (myChar > 0)
        {
            printf("found integer %d\n", myInt);
        }
    }

    return 0;
}

/* getint: get next integer from the input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ; // skip white space
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0; // it's not a number
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        c = getch();

        if (c == ' ')
        {
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}

int getfloat(float *pf)
{
    // do the stuff
    return EOF;
}
