#include <stdio.h>
#include <time.h>
#define MAXELEMENT 200000 /* Max size of data array */
#define TESTNUM 100000

int binsearch(int x, int v[], int n);
int altbinsearch(int x, int v[], int n);

/* Example 3-1 Rewrite original binsearch with a single test */

int main()
{
    int testData[MAXELEMENT];
    int i, index, x;
    clock_t timeTaken;

    for(i = 0; i < MAXELEMENT; i++)
    {
        testData[i] = i;
    }

    x = 593;

    printf("Actual value: %d\n", x);
    printf("Original    : %d\n", binsearch(x, testData, MAXELEMENT));
    printf("Alternate   : %d\n", altbinsearch(x, testData, MAXELEMENT));

    x = -1;

    for (i = 0, timeTaken = clock(); i < TESTNUM; i++)
    {
        index = binsearch(x, testData, MAXELEMENT);
    }

    timeTaken = clock() - timeTaken;

    printf("%d\n", index);
    printf("binsearch() took %lu clocks (%lu seconds)\n",
           (unsigned long) timeTaken,
           (unsigned long) timeTaken / CLOCKS_PER_SEC);
    
    for (i = 0, timeTaken = clock(); i < TESTNUM; i++)
    {
        index = altbinsearch(x, testData, MAXELEMENT);
    }

    timeTaken = clock() - timeTaken;

    printf("%d\n", index);
    printf("altbinsearch() took %lu clocks (%lu seconds)\n",
        (unsigned long) timeTaken,
        (unsigned long) timeTaken / CLOCKS_PER_SEC);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low+high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int altbinsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = -1;
    high = n;

    while (low + 1 < high)
    {
        mid = (low + high) / 2;
        if(v[mid] < x)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    if (high == n || v[high] != x)
    {
        return -1;
    }
    else
    {
        return high;
    }
}
