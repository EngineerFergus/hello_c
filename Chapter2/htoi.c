#include <stdio.h>
#include <ctype.h>

/* Convert a string of hexadecimel digits to its equivalent integer value. */
/* Allowable digits are 0-9, a-b, and A-F. 0x or 0X is optional */

int atoi(char s[]);
int htoi(char s[]);
int convert(char c);
int getline(char line[], int limit);

#define LIMIT 32 /* max line length */

int main()
{
    char line[LIMIT];
    int i, n;

    for (i = 0; i < LIMIT; i++)
    {
        line[i] = '\0';
    }

    while((i = getline(line, LIMIT)) != 0)
    {
        n = htoi(line);
        printf("%d\n", n);
    }

    return 0;
}

int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    {
        n = 10 * n + (s[i] - '0');
    }

    return n;
}

int htoi(char s[])
{
    // look up ctype functions that will hopefully help out!
    int i, n;

    n = 0;

    for (i = 0; s[i] != '\0'; ++i)
    {
        if (i == 0 && s[i] == '0')
        {
            continue;
        }

        if (i == 1 && (s[i] == 'x' || s[i] == 'X'))
        {
            continue;
        }

        if (isxdigit(s[i]))
        {
            n = 16 * n + convert(s[i]);
        }
    }

    return n;
}

int convert(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }

    char lower = tolower(c);
    return (lower - 'a') + 10;
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
