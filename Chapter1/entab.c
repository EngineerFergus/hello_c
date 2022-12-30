#include <stdio.h>

/* replaces consecutive spaces with tabs */

void entab(int numSpacesToTabs);

int main()
{
    entab(3);

    return 0;
}

void entab(int numSpacesToTabs)
{
    int i, c, count, prevChar;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && prevChar != ' ')
        {
            count = 1;
        }
        else if (c == ' ' && prevChar == ' ')
        {
            ++count;
        }
        else if (count > 0 && c != ' ')
        {
            int numTabs, remainder;

            numTabs = count / numSpacesToTabs;
            remainder = count - (numTabs * numSpacesToTabs);

            for (i = 0; i < numTabs; i++)
            {
                putchar('\t');
            }

            for (i = 0; i < remainder; i++)
            {
                putchar(' ');
            }

            count = 0;
            putchar(c);
        }
        else
        {
            putchar(c);
        }

        prevChar = c;
    }
}