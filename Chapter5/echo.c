#include <stdio.h>

/* echos the command line arguments provided to the program */
int main(int argc, char *argv[])
{
    while (--argc > 0)
    {
        printf((argc > 1) ? "%s " : "%s", *++argv);
    }

    printf("\n");
    return 0;
}