#include <stdio.h>

/* fold long lines into two or more lines */

void fold(int maxLength);

int main()
{
    fold(20);
    return 0;
}

void fold(int maxLength)
{
    int c, counter;

    counter = 0;

    while ((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            counter = 0;
        }
        else 
        {
            counter++;
        }

        if(counter > maxLength)
        {
            putchar('\n');
            counter = 0;
        }

        putchar(c);
    }
}