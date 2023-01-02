#include <stdio.h>
#include <stdlib.h>

/* Exercises 2-6, 2-7, and 2-8 */

int getline(char line[], int limit);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
int rightrot(int x, int n);
void testrightrot(int x, int n);

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

    printf("  INVERT TEST \n");
    itoa(b, buffer, 2);
    printf("starting x: %s\n", buffer);
    a = invert(b, 3, 4);
    itoa(a, buffer, 2);
    printf("inverted  : %s\n", buffer);
    itoa(1287, buffer, 2);
    printf("starting x: %s\n", buffer);
    a = invert(1287, 6, 4);
    itoa(a, buffer, 2);
    printf("inverted  : %s\n", buffer);

    testrightrot(123123123, 1);
    testrightrot(052614, 5);

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

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask;
    mask = ~(~0 << n); // set up mask
    mask = (mask << (p + 1 - n));
    return (mask & ~x) | (~mask & x);
}

int rightrot(int x, int n)
{
    int sz = sizeof(x) * 8;
    int r = x >> n;
    int rLeft = x << (sz - n);
    return r | rLeft;
}

void testrightrot(int x, int n)
{
    char buffer[33];
    printf("RIGHTROT TEST\n");
    itoa(x, buffer, 2);
    printf("Start: %s\n", buffer);
    int temp = rightrot(x, n);
    itoa(temp, buffer, 2);
    printf("Rot  : %s\n", buffer);
}
