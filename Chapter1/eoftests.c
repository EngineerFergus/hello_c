#include <stdio.h>

/* contains code written for exercises 1-6 and 1-7 */

int main()
{
    /* Verify that expression equals 0 or 1 */

    int eofA, B;

    eofA = EOF;
    B = getchar();

    printf("%d (should be zero)\n", eofA != EOF);
    printf("%d (should be one )\n", B != EOF);

    /* Print the value of EOF */

    printf("%d\n", EOF);

    return 0;
}