#include <stdio.h>
#include <ctype.h>

int lower(int c);
int altlower(int c);

int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\n' || c == ' ')
        {
            putchar(c);
        }
        else
        {
            putchar(altlower(c));
        }
    }

    return 0;
}

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    else
    {
        return c;
    }
}

int altlower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
