#include <stdio.h>

/* Rewrite the loop without using the && or || operators */
/*

for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
{
    s[i] = c;
}

*/

int getline(char line[], int limit); // original getline
int altgetline(char line[], int limit); // rewrite of getline
void printline(char line[], int limit);

#define LIMIT 256

int main()
{
    int i, length;
    int limit = LIMIT;
    char line[LIMIT];

    for(i = 0; i < LIMIT; ++i)
    {
        line[i] = 0;
    }

    while((length = altgetline(line, limit)) != 0)
    {
        printline(line, limit);
    }

    return 0;
}

int getline(char line[], int limit)
{
    int c, i;

    for (i=0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

int altgetline(char line[], int limit)
{
    int c, i;

    for (i=0; i < limit - 1; ++i)
    {
        c = getchar();

        if (c == EOF)
        {
            break;
        }

        if (c == '\n')
        {
            break;
        }

        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void printline(char line[], int limit)
{
    int i;

    for (i = 0; i < limit; ++i)
    {
        if (line[i] == '\0')
        {
            break;
        }

        putchar(line[i]);
    }
}
