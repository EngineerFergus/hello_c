#include <stdio.h>
#include <string.h>

#define MAXSTR 32

void itoa(int, char []);
int  itoarec(int, char [], int);
void reverse(char []);
void printd(int);

int main()
{
    int n = 123, i;
    char s[MAXSTR];

    for (i = 0; i < MAXSTR; i++)
    {
        s[i] = '\0';
    }

    itoarec(123456789, s, 0);
    printf("integer: %s\n", s);

    itoarec(-123, s, 0);
    printf("integer: %s\n", s);

    return 0;
}

/* original implementation of converting an integer to a string */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
    {
        n = -n;
    }

    i = 0;

    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    reverse(s);
}

/* recursive implementation of itoa */
int itoarec(int n, char s[], int idx)
{
    if (n < 0)
    {
        s[0] = '-';
        idx += 1;
        n = -n;
    }

    if (n / 10)
    {
        idx = itoarec(n / 10, s, idx);
    }

    s[idx] = n % 10 + '0';
    s[idx + 1] = '\0';
    return idx + 1;
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* reference for recursion */
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
    {
        printd(n / 10);
    }

    putchar(n % 10 + '0');
}
