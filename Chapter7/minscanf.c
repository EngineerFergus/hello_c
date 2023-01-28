#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "getinput.h"

void minscanf(char *fmt, ...);
int scanint();
double scanfloat();

int main(int argc, char **argv)
{
    int d;
    double f;
    char str[100];
    char *fmt = "%d,%f,%s";

    minscanf(fmt, &d, &f, str);

    printf("int: %d\n", d);
    printf("float: %f\n", f);
    printf("string: %s\n", str);

    return 0;
}

/* minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval, *sptr;
    int ival, c, *iptr;
    double dval, *dptr;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p; p++)
    {
        while ((c = getch()) != EOF)
        {
            if (!isblank(c))
            {
                ungetch(c);
                break;
            }
        }

        if (*p != '%')
        {
            // check that format and input match
            c = getch();
            if (*p != c)
            {
                return; // bail out, format did not match input
            }

            continue;
        }

        switch (*++p)
        {
            case 'd':
                iptr = va_arg(ap, int*);
                *iptr = scanint();
                break;
            case 'f':
                dptr = va_arg(ap, double*);
                *dptr = scanfloat();
                break;
            case 's':
                sptr = va_arg(ap, char*);
                while ((c = getch()) != EOF && !isblank(c))
                {
                    *sptr = c;
                    sptr++;
                }

                *sptr = '\0';

                break;
            default:
                return; // bail out for unknown types
        }
    }

    va_end(ap);
}

int scanint()
{
    int c;
    char str[100];
    char *p = str;

    c = getch();

    if (c == '-')
    {
        *p = c;
        p++;
    }
    else
    {
        ungetch(c);
    }

    while (isdigit((c = getch())))
    {
        *p = c;
        p++;
    }

    ungetch(c);

    p++;
    *p = '\0';

    return atoi(str);
}

double scanfloat()
{
    int c;
    char str[100];
    char *p = str;

    c =  getch();

    if (c == '-')
    {
        *p = c;
        p++;
    }
    else
    {
        ungetch(c);
    }

    while (isdigit((c = getch())))
    {
        *p = c;
        p++;
    }

    if (c == '.')
    {
        *p = c;
        p++;
    }

    while (isdigit((c = getch())))
    {
        *p = c;
        p++;
    }

    ungetch(c);

    p++;
    *p = '\0';

    return atof(str);
}
