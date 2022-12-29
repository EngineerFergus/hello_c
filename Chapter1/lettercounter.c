#include <stdio.h>

/* Counts various characters in input */

#define NUM_LETTERS 256 /* number of letters being tracked */

int main()
{
    int i, c, larger;
    char v;
    int histogram[NUM_LETTERS];

    larger = 0;

    for (i = 0; i < NUM_LETTERS; ++i)
    {
        histogram[i] = 0;
    }

    while((c = getchar()) != EOF)
    {
        if (c < NUM_LETTERS)
        {
            ++histogram[c];
        }
        else
        {
            ++larger;
        }
    }

    printf("Char : Count\n");

    for (i = 0; i < NUM_LETTERS; i++)
    {
        v = i;
        printf("%4c : %5d\n", v, histogram[i]);
    }

    printf("NA   : %5d\n", larger);

    return 0;
}