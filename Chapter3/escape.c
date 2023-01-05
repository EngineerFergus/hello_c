#include <stdio.h>

/* Exercidse 3-2, write a function called escape that will tabs, spaces, and newlines to visible characters. */
/* Write a second function that does the opposite. */

int getline(char line[], int limit);
void printline(char line[], int limit);
void escape(char s[], char t[], int limit);
void unescape(char s[], char t[], int limit);

#define MAXLIMIT 512

int main()
{
    char line[MAXLIMIT], copy[MAXLIMIT];
    int n;

    while((n = getline(line, MAXLIMIT)) != 0)
    {
        escape(line, copy, MAXLIMIT);
        printline(copy, MAXLIMIT);
        unescape(copy, line, MAXLIMIT);
        putchar('-');
        putchar('-');
        printline(line, MAXLIMIT);
    }

    return 0;
}

int getline(char line[], int limit)
{
    int c, i;

    for (i=0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void printline(char line[], int limit)
{
    int i;

    for(i = 0; i < limit; i++)
    {
        if(line[i] == '\0')
        {
            break;
        }

        putchar(line[i]);
    }
}

void escape(char s[], char t[], int limit)
{
    int i, j;

    for(i = 0, j = 0; i < limit && j < limit && s[i] != '\0'; i++, j++)
    {
        switch (s[i])
        {
        case '\t':
            t[j] = '\\';
            ++j;
            t[j] = 't';
            break;
        case '\n':
            t[j] = '\\';
            ++j;
            t[j] = 'n';
            break;
        default:
            t[j] = s[i];
            break;
        }
    }

    if (j < limit)
    {
        t[j] = '\0';
    }
}

void unescape(char s[], char t[], int limit)
{
    int i, j;

    for(i = 0, j = 0; i < (limit - 1) && j < limit && s[i] != '\0'; i++, j++)
    {
        switch (s[i])
        {
        case '\\':

            switch (s[i + 1])
            {
            case 't':
                t[j] = '\t';
                i++;
                break;
            case 'n':
                t[j] = '\n';
                i++;
                break;
            default:
                t[j] = s[i];
                break;
            }

            break;
        
        default:
            t[j] = s[i];
            break;
        }
    }

    if (j < limit)
    {
        t[j] = '\0';
    }
}
