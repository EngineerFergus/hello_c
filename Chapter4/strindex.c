#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 // max input line length

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; // pattern to search for

// exercise 4-1

int main()
{
    char line[MAXLINE];
    int found = 0;
    int location = -1;

    while(getline(line, MAXLINE) > 0)
    {
        if ((location = strrindex(line, pattern)) >= 0)
        {
            printf("%s", line);
            printf("found at %d\n", location);
            found++;
        }
    }

    return found;
}

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if(c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            ;
        }

        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }

    return -1;
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    int patternLength = strlen(t);

    for(i = strlen(s) - 1; i >= strlen(t); i--)
    {
        for (j = i - patternLength + 1, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            ;
        }

        if (k > 0 && t[k] == '\0')
        {
            return i - patternLength + 1;
        }
    }

    return -1;
}
