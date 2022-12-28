#include <stdio.h>

/* prints multi line input with one word per line */

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word*/

int main()
{
    int c, state;

    state = IN;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            putchar('\n');
        }

        putchar(c);
    }

    return 0;
}