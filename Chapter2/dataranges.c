#include <float.h>
#include <limits.h>
#include <stdio.h>

/* determines the ranges of char, short, int, and long data types */

int main()
{
    printf("data type >> (min, max)\n");
    printf("     char >> (%d, %d)\n", CHAR_MIN, CHAR_MAX);
    printf("    short >> (%d, %d)\n", SHRT_MIN, SHRT_MAX);
    printf("      int >> (%d, %d)\n", INT_MIN, INT_MAX);
    printf("     long >> (%d, %d)\n", LONG_MIN, LONG_MAX);
    printf("    uchar >> (%d, %d)\n", 0, UCHAR_MAX);
    printf("   ushort >> (%d, %d)\n", 0, USHRT_MAX);
    printf("     uint >> (%d, %d)\n", 0, UINT_MAX);
    printf("    ulong >> (%d, %d)\n", 0, ULONG_MAX);
    printf("    float >> (%f, %f)\n", -1 * FLT_MAX, FLT_MAX);
    printf("   double >> (%f, %f)\n", -1 * DBL_MAX, DBL_MAX);

    return 0;
}