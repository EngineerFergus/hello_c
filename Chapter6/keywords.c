#include "getch.h"
#include "getword.h"
#include "stdio.h"

#define MAXWORD 100

struct key 
{
    char *word;
    int count;
};

int main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
    {
        printf("%s\n", word);
    }

    return 0;
}