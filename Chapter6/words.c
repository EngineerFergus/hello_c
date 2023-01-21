#include <stdio.h>
#include <ctype.h>
#include "getinput.h"
#include "wordnode.h"

#define MAXWORD     100
#define LISTSIZE    100 /* total number of words to order by count */

int traversetree(struct wordnode *, struct wordnode *lst[], int location, int lim);
void printlist(struct wordnode *lst[], int lim);
void printlistdescending(struct wordnode *lst[], int lim);
void qsort(struct wordnode *lst[], int left, int right);

int main()
{
    struct wordnode *root, *orderedlist[LISTSIZE];
    char word[MAXWORD];
    int p;

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word);
        }
    }

    printtree(root);

    p = traversetree(root, orderedlist, 0, LISTSIZE);
    printf("list length %d\n", p);
    qsort(orderedlist, 0, p - 1);
    printlistdescending(orderedlist, p);
    return 0;
}

int traversetree(struct wordnode *node, struct wordnode *lst[], int location, int lim)
{
    if (node == NULL || location >= lim)
    {
        return location;
    }

    lst[location] = node;
    location++;

    location = traversetree(node->left, lst, location, lim);
    location = traversetree(node->right, lst, location, lim);

    return location++;
}

void printlist(struct wordnode *lst[], int lim)
{
    int i;

    for (i = 0; i < lim; i++)
    {
        printf("%4d %s\n", lst[i]->count, lst[i]->word);
    }
}

void printlistdescending(struct wordnode *lst[], int lim)
{
    int i;

    for (i = lim - 1; i >= 0; i--)
    {
        printf("%4d %s\n", lst[i]->count, lst[i]->word);
    }
}

/* sort wordnodes by count */
void qsort(struct wordnode *lst[], int left, int right)
{
    int i, last;
    void swap(struct wordnode *lst[], int i, int j);

    if (left >= right)
    {
        return;
    }

    swap(lst, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (lst[i]->count < lst[left]->count)
        {
            swap(lst, ++last, i);
        }
    }

    swap(lst, left, last);

    qsort(lst, left, last - 1);
    qsort(lst, last + 1, right);
}

void swap(struct wordnode *lst[], int i, int j)
{
    struct wordnode *temp;

    temp = lst[i];
    lst[i] = lst[j];
    lst[j] = temp;
}
