#include <stdio.h>
#define LEN 256

int getline(char*, int);

int main()
{
    int n;
    char l[LEN];

    while ((n = getline(l, LEN)) > 0)
    {
        printf("%s\n", l);
    }

    return 0;
}

/* retrieves a line from input, return line length */
int getline(char* line, int lim)
{
    int c, n;

    n = 0;    

    while ((c = getchar()) != EOF && (c != '\n') && n < (lim - 1))
    {
        *line = c;
        line++;
        n++;
    }

    if (c == '\n')
    {
        *line = c;
        line++;
        n++;
    }

    *line = '\0';
    return n;
}
