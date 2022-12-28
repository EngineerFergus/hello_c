#include <stdio.h>

/* Copies input to output, but replaces one and more spaces with single space */

int main()
{
    int c, lastc;

    lastc = EOF;

    while((c = getchar()) != EOF)
    {
        if (c != ' ' || lastc != ' ')
        {
            putchar(c);
        }
        lastc = c;
    }

    return 0;
}