#include <stdio.h>
#define MAXLINE 1000 /* maximum print size */
#define LENGTHTHRESHOLD 80 /* line length to write to output */

/* write all lines greater than 80 characters to output */
void printline(char s[], int lim);
int getline(char line[], int maxline);
void copy(char to[], char from[]);
void trim(char to[], char from[], int lim);
int count(char s[], int lim);
void reverse(char s[], char rev[], int lim);

int main()
{
    int len, c; /* current line length */
    char line[MAXLINE]; /* current input line */
    char rev[MAXLINE]; /* longest line seen */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        reverse(line, rev, MAXLINE);
        printline(rev, MAXLINE);
    }

    return 0;
}

void reverse(char s[], char rev[], int lim)
{
    int eol, i, j;

    eol = 0;

    for(i = 0; i < lim - 1; i++)
    {
        if(s[i] == '\0' || s[i] == '\n')
        {
            break;
        }
    }

    i--;

    rev[i + 1] = '\0';

    for (j = 0; i >= 0; i--)
    {
        rev[j] = s[i];
        ++j;
    }
}

int count(char s[], int lim)
{
    int i, count;

    count = 0;

    for(i = 0; i < lim; i++)
    {
        if(s[i] != '\0' && s[i] != '\n')
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return count;
}

void trim(char to[], char from[], int lim)
{
    int seenNonBlank, i, n;

    seenNonBlank = 0;

    for (i = lim - 1; i >= 0; --i)
    {
        n = from[i];
        if (n != ' ' && n != '\t')
        {
            seenNonBlank = 1;
        }

        if (seenNonBlank)
        {
            to[i] = from[i];
        }
        else
        {
            to[i] = '\0';
        }
    }
}

void printline(char s[], int lim)
{
    int i;

    for(i = 0; i < lim; ++i)
    {
        if (s[i] == '\0')
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