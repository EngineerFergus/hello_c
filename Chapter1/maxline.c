#include <stdio.h>
#define MAXLINE 1000 /* maximum print size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line seen */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("longest line length: %d\n", max);
        printf("%s", longest);
    }

    return 0;
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

    //for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
    //{
    //    s[i] = c;
    //}

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