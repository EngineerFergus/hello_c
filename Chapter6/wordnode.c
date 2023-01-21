#include "wordnode.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* add a node with w at or below p */
struct wordnode *addtree(struct wordnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w);
    }
    else
    {
        p->right = addtree(p->right, w);
    }

    return p;
}

/* in-order print of tree p */
void printtree(struct wordnode *p)
{
    if (p != NULL)
    {
        printtree(p->left);
        printf("%4d %s\n", p->count, p->word);
        printtree(p->right);
    }
}

/* make a tnode */
struct wordnode *talloc(void)
{
    return (struct wordnode *) malloc(sizeof(struct wordnode));
}
