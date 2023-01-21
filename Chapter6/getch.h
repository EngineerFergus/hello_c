#define BUFSIZE 100     /* max size of getch buffer */

/* Get char from either buffer or input */
int getch(void);

/* push character back on input */
void ungetch(int);
