#include <stdio.h>
#include <ctype.h>
#include "getinput.h"
#include "wordnode.h"

#define MAXWORD 100

int main()
{
    struct wordnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word);
        }
    }

    printtree(root);

    return 0;
}