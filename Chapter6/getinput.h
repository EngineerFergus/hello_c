#define BUFSIZE 100     /* max size of getch buffer */

/* Get char from either buffer or input */
int getch(void);

/* push character back on input */
void ungetch(int);

/* get next word or character from input */
int getword(char *word, int lim);

/* retrieves the next line of characters from the input and returns the length of the line */
int getline(char [], int);