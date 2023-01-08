#include <string.h>
#include <stdio.h>

void reverse(char []);
int reverserec(char [], int);

int main()
{
    char s[] = "hello world!";
    char s2[] = "hello world!";
    char s3[] = "hello world!";
    char s4[] = "123";
    char s5[] = "1234";

    printf(s);
    putchar('\n');\

    reverse(s2);
    printf(s2);
    putchar('\n');

    reverserec(s3, 0);
    printf(s3);
    putchar('\n');

    reverserec(s4, 0);
    printf(s4);
    putchar('\n');

    reverserec(s5, 0);
    printf(s5);
    putchar('\n');
    return 0;
}

/* reverse a string */
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

/* recursive implementation of reverse */
int reverserec(char s[], int idx)
{
    if (idx < strlen(s) / 2)
    {
        int swapIdx = strlen(s) - 1 - idx;
        int temp = s[idx];
        s[idx] = s[swapIdx];
        s[swapIdx] = temp;
        reverserec(s, idx + 1);
    }
}
