#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getline.h"

#define ALLOCSIZE   100000
#define MAXLENGTH   1000
#define MAXLINES    5000

char *alloc(int);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

static char *lines[MAXLINES];   /* pointers for lines */
static char buf[ALLOCSIZE];     /* storage for alloc */
static char *allocp = buf;      /* pointer to alloc location */

char *alloc(int n)
{
    if (buf + ALLOCSIZE - allocp < n)
		return 0; /* not enough room */
	allocp += n;
	return allocp - n; /* old p */
}

int readlines(char *lineptr[], int maxlines)
{
    int len, numlines;

    char *p, line[MAXLENGTH];

    numlines = 0;

    while ((len = getline(line, MAXLENGTH)) > 0)
    {
        if (numlines > maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }

        line[len - 1] = '\0'; // remove newline
        strcpy(p, line);
        lineptr[numlines++] = p;
    }

    return numlines;
}

void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
    {
        printf("%s\n", *lineptr++);
    }
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left <= right)
    {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
    {
        return -1;
    }
    else if (v1 > v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
    {
        numeric = 1;
    }

    if ((nlines = readlines(lines, MAXLINES)) >= 0)
    {
        qsort((void **) lines, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lines, nlines);
        return 0;
    }
    else
    {
        printf("Error reading input, likely too large.\n");
        return 1;
    }
}
