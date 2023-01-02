#include <stdio.h>
#define LIMIT 256
#define FALSE 0
#define TRUE 1

int any(char s1[], char s2[]);
void squeeze(char s1[], char s2[]);
int getline(char line[], int limit);
void printline(char line[]);

int main()
{
    int length, i;
    char s1[LIMIT], s2[LIMIT];

    for(i = 0; i < LIMIT; i++)
    {
        s1[i] = '\0';
        s2[i] = '\0';
    }

    while((length = getline(s1, LIMIT)) != 0)
    {
        length = getline(s2, LIMIT);
        if(length == 0)
        {
            break;
        }

        i = any(s1, s2);
        printf("%d\n", i);
    }

    return 0;
}

int any(char s1[], char s2[])
{
    int i, j, foundMatch;
    int n = -1;

    for (i = 0; s1[i] != '\0'; i++)
    {
        foundMatch = FALSE;
        for (j = 0; s2[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])
            {
                n = i;
                foundMatch = TRUE;
                break;
            }
        }

        if (foundMatch)
        {
            break;
        }
    }

    return n;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k, isIns2;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        isIns2 = FALSE;

        for (k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i] == s2[k])
            {
                isIns2 = TRUE;
            }
        }

        if (!isIns2)
        {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';
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

void printline(char line[])
{
    int i, hadNewLine;

    hadNewLine = FALSE;
    for(i = 0; line[i] != '\0'; i++)
    {
        if(line[i] == '\n')
        {
            hadNewLine = TRUE;
        }

        putchar(line[i]);
    }

    if(!hadNewLine)
    {
        putchar('\n');
    }
}
