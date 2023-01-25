#include <string.h>
#include <stdlib.h>

/* Table entry */
struct nlist 
{
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

/* form hash value for string s */
unsigned hash(char *s);

/* look for s in hashtab */
struct nlist *lookup(char *s);

/* put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn);

/* undef: remove (name, def) in hash table. Takes name as argument */
void undef(char *s);
