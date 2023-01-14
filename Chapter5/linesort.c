#include <stdio.h>
#include <string.h>
#include "getline.h"

#define MAXLINES 5000 /* maximum number of lines to be sorted */
#define MAXLEN 1000 /* maxlength of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char mem[]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
    char mem[200000]; // all of memory

    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES, mem)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char mem[])
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    p = mem;

    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return; /* do nothing if array contains fewer than 2 elements */

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left+1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
