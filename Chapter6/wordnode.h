struct wordnode
{
    char *word;
    int count;
    struct wordnode *left;
    struct wordnode *right;
};

/* add a node with w at or below p */
struct wordnode *addtree(struct wordnode *p, char *w);

/* in-order print of tree p */
void printtree(struct wordnode *p);

/* make a tnode */
struct wordnode *talloc(void);
