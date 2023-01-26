#include <stdio.h>
#include <ctype.h>

typedef int (*converter)(int);

int main(int argc, char *argv[])
{
    int c, a;
    converter conv;

    if (argc < 2)
    {
        printf("usage: echocase {-u, -l}\n");
        return 1;
    }

    argv++; // move to position one

    if ((*argv)[0] == '-')
    {
        a = (*argv)[1];
        switch (a)
        {
            case 'u':
                conv = toupper;
                break;
            case 'l':
                conv = tolower;
                break;
            default:
                printf("illegal option %c\n", a);
                return 1;
        }
    }
    else
    {
        printf("illegal input found\n");
        return 1;
    }


    while ((c = getchar()) != EOF)
    {
        putchar(conv(c));
    }

    return 0;
}