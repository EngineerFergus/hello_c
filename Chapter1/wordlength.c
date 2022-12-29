#include <stdio.h>

/* print histogram of word lengths */

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word*/
#define MAX_LENGTH 15 /* maximum length of word to be tracked */

int main()
{
    int i, large, c, state, length;
    int nchars[MAX_LENGTH];

    large = length = 0;
    state = IN;

    for(i = 0; i < MAX_LENGTH; i++)
    {
        nchars[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            // left word
            if (length < MAX_LENGTH)
            {
                ++nchars[length];
            }
            else
            {
                ++large;
            }
            state = OUT;
            length = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            ++length;
        }
        else
        {
            ++length;
        }
    }

    printf("Length : Count\n");

    for(i = 0; i < MAX_LENGTH; i++)
    {
        printf("%6d :%6d\n", i, nchars[i]);
    }

    printf(">=%4d :%6d", MAX_LENGTH, large);

    return 0;
}