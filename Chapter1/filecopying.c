#include <stdio.h>

/* Copy input to ouput */

int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        putchar(c);
    }

    return 0;
}