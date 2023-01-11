#include <stdio.h>
#include <ctype.h>
#include "getch.h"

int getint(int *);
int getfloat(double *);

int main()
{
    int myInt, myChar;
    double myFloat;

    while((myChar = getfloat(&myFloat)) != EOF)
    {
        if (myChar > 0)
        {
            printf("found float %f\n", myFloat);
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

int getfloat(double *pf)
{
    double val, power;

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

    for (*pf = 0.0; isdigit(c); c = getch())
    {
        *pf = 10.0 * *pf + (c - '0');
    }

    // get the fractional portion

    if (c == '.')
    {
        c = getch();
    }

    for (power = 1.0; isdigit(c); c = getch())
    {
        *pf = 10.0 * *pf + (c - '0');
        power *= 10;
    }

    *pf = *pf * sign / power;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}
