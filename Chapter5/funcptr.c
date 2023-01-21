#include <stdio.h>
#include <string.h>
#define ADD         0
#define SUBTRACT    1

int add(int, int);
int subtract(int, int);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: funcptr {add, sub}\n");
        return 1;
    }

    int op = ADD;

    if (*argv[1] == 's')
    {
        op = SUBTRACT;
    }

    char *s = ((op == ADD) ? "Operation was ADD\n" : "Operation was SUBTRACT\n");
    printf(s);

    int A = 10;
    int B = 5;

    int (*opr)(int, int) = (op == ADD) ? add : subtract;

    int result = (*opr)(A, B);
    char c = (op == ADD) ? '+' : '-';

    printf("%d %c %d = %d\n", A, c, B, result);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}
