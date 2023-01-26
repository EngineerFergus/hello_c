#include <stdio.h>

#define MAXWIDTH 10 /* maxwidth of a line printed by this program */

int main()
{
    int c, count;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case ' ':
            case '\t':
            case '\n':
                putchar('%');
                printf("%2o", c);
                putchar('%');
                count += 3;
                break;
            default:
                putchar(c);
                break;
        }

        count++;

        if (count > MAXWIDTH)
        {
            putchar('\n');
            count = 0;
        }
    }

    return 0;
}