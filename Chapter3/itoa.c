#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Exercises 3-4 to 3-6 */

void itoa(int n, char s[]); // converts integer n to string in s
void itoaAlt(int n, char s[]); // itoa equivalent but handles largest negative number
void reverse(char s[]);
void itob(int n, char s[], int b); // converts integers to base b representation in string s
void itoaPad(int n, char s[], int p); // converts integer n to string in s with minimum field width p

int main()
{
    int a = 1234;
    int b = -1234;

    char line[32];

    for(int i = 0; i < 32; i++)
    {
        line[i] = '\0';
    }

    itoaPad(a, line, 16);

    printf(line);
    putchar('\n');

    itoaPad(b, line, 16);
    printf(line);
    putchar('\n');

    return 0;
}

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

/* 
    The original itoa function could not handle the largest negative value of a two's complement number 
    because negative values can go one further away from 0 than their positive counterparts. Thus, the
    first step of inverting the sign of n in the original function would cause an overflow error.
*/
void itoaAlt(int n, char s[])
{
    int i, sign;

    sign = 1;

    if (n < 0)
    {
        sign = -1;
    }

    i = 0;

    do
    {
        s[i++] = ((n % 10) * sign) + '0';
    } while (((n /= 10) * sign) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    reverse(s);
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

void itob(int n, char s[], int b)
{
    int i, sign;

    sign = 1;

    if (n < 0)
    {
        sign = -1;
    }

    i = 0;

    do
    {
        int idx = (n % b) * sign;
        s[i++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[idx];
    } while (((n /= b) * sign) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    reverse(s);
}

void itoaPad(int n, char s[], int p)
{
    int i, sign;

    sign = 1;

    if (n < 0)
    {
        sign = -1;
    }

    i = 0;

    do
    {
        s[i++] = ((n % 10) * sign) + '0';
    } while (((n /= 10) * sign) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    while(i < p)
    {
        s[i++] = ' ';
    }

    reverse(s);
}
