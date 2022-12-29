#include <stdio.h>
#define MAXLINE 1000 /* maximum print size */
#define LENGTHTHRESHOLD 80 /* line length to write to output */

/* write all lines greater than 80 characters to output */
void printline(char s[], int lim);
int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line seen */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len >= LENGTHTHRESHOLD)
        {
            printline(line, MAXLINE);
        }
    }

    return 0;
}

void printline(char s[], int lim)
{
    int i;

    for(i = 0; i < lim; ++i)
    {
        if (s[i] == '\0' || s[i] == '\n')
        {
            break;
        }
        
        putchar(s[i]);
    }

    putchar('\n');
}

int getline(char s[], int lim)
{
    int c, i, linelength;

    i = linelength = 0;

    while((c = getchar()) != EOF && c != '\n')
    {
        if (i < lim - 1)
        {
            s[i] = c;
            i++;
        }

        ++linelength;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return linelength;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}