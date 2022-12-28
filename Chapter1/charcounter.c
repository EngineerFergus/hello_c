#include <stdio.h>

/* Counts blanks, tabs, and newlines in input */

int main()
{
    int c, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            ++tabs;
        }
        else if (c == '\n')
        {
            ++newlines;
        }
        else if (c == ' ')
        {
            ++blanks;
        }
    }

    printf("newlines = %d, blanks = %d, tabs = %d\n", newlines, blanks, tabs);

    return 0;
}