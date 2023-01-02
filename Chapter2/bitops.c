#include <stdio.h>
#include <stdlib.h>

int getline(char line[], int limit);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    char buffer[33];
    unsigned a, b, c;
    a = 255;
    b = 67;
    c = 31;

    printf("  SETBITS TEST  \n");
    itoa(b, buffer, 2);
    printf("starting x: %s\n", buffer);
    itoa(c, buffer, 2);
    printf("starting y: %s\n", buffer);

    a = setbits(b, 4, 2, c);
    itoa(a, buffer, 2);
    printf("final     : %s\n", buffer);
    printf("\n");

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

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // position zero is far right
    unsigned r, mask;
    mask = ~(~0 << n); // set up mask
    r = y & mask; // get bits from y
    r = (r << (p + 1 - n)); // shift far right bits of y to position p
    mask = (mask << (p + 1 - n)); // shift mask from far right to position p
    r = ((r & mask) | (x & ~mask));
    return r;
}
