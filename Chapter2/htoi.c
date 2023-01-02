#include <stdio.h>
#include <ctype.h>

/* Convert a string of hexadecimel digits to its equivalent integer value. */
/* Allowable digits are 0-9, a-b, and A-F. 0x or 0X is optional */

int atoi(char s[]);
int htoi(char s[]);

int main()
{


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
}
