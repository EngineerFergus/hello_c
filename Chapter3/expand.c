#include <stdio.h>
#include <ctype.h>

/* Write a function expand(s1, s2) that expands shorthand notation (a-z to abc...xyz or 0-9 to 0123456789) */
/* edge cases a-b-c, a-z0-9, and -a-z */

void expand(char s1[], char s2[], int limit);
void printline(char line[], int limit);
int getline(char line[], int limit);
int aredigits(char a, char b);
int arealpha(char a, char b);

#define MAXLIMIT 1024

int main()
{
    char s1[MAXLIMIT];
    char s2[MAXLIMIT];
    int n;

    for(n=0; n<MAXLIMIT;++n)
    {
        s1[n] = s2[n] = '\0';
    }

    while((n = getline(s1, MAXLIMIT)) != 0)
    {
        printline(s1, MAXLIMIT);
        expand(s1, s2, MAXLIMIT);
        printline(s2, MAXLIMIT);
        putchar('\n');
    }

    return 0;
}

void expand(char s1[], char s2[], int limit)
{
    int i, j;

    if (s1[0] == '\0')
    {
        s2[0] = '\0';
        return;
    }

    s2[0] = s1[0];

    for(i = 1, j = 1; s1[i] != '\0' && i < (limit - 1); i++, j++)
    {
        if(s1[i] == '-')
        {
            char dPrev = s1[i - 1];
            char dNext = s1[i + 1];

            if (aredigits(dPrev, dNext) || arealpha(dPrev, dNext))
            {
                char temp = dPrev + 1;
                
                if (temp == dNext)
                {
                    s2[j] = dNext;
                    i++;
                    continue;
                }

                while (temp < dNext)
                {
                    s2[j] = temp;
                    temp++;
                    if (temp != dNext)
                    {
                        j++;
                    }
                }
            }
            else
            {
                s2[j] = s1[i];
            }
        }
        else
        {
            s2[j] = s1[i];
        }
    }

    s2[j] = '\0';
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

int aredigits(char a, char b)
{
    return isdigit(a) && isdigit(b);
}

int arealpha(char a, char b)
{
    return isalpha(a) && isalpha(b);
}
