#include <stdio.h>

/* Exercise 4-14 define a macro swap(t, x, y) that interchanges two arguments of type t. */

#define swap(t, x, y)\
if(sizeof(t) == sizeof(x) && sizeof(t) == sizeof(y)) \
{\
    t tmp = x;\
    x = y;\
    y = tmp;\
}\

int main()
{
    int x, y;
    x = 1;
    y = 2;

    printf("original: %d, %d\n", x, y);
    swap(int, x, y);
    printf("swapped : %d, %d\n", x, y);

    return 0;
}
