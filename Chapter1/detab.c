#include <stdio.h>

/* replace tabs in input with specific amount of spaces in output */

void detab(int numSpaces);

int main()
{
    detab(4);
    return 0;
}

void detab(int numSpaces)
{
    int c, i;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (i = 0; i < numSpaces; i++)
            {
                putchar(' ');
            }
        }
        else
        {
            putchar(c);
        }
    }
}