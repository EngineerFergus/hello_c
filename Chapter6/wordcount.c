#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getword.h"
#include "getch.h"
#include <stdlib.h>

#define MAXWORD 100

struct tnode                /* tree node */
{
    char *word;             /* pointer to the text */
    int count;              /* number of occurrences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *strdup_kr(char *);

int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word);
        }
    }

    treeprint(root);
    return 0;
}

/* make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p  = talloc();
        p->word = strdup_kr(w);
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

/* in-order print of tree */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* make a duplicate of s */
char *strdup_kr(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
    {
        strcpy(p, s);
    }

    return p;
}
