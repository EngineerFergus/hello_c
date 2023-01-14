#include <stdio.h>

static char daytab[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

int main()
{
    return 0;
}

/* set day of year from year, month, and day. Returns -1 if not a valid day of year */
int day_of_year(int year, int month, int day)
{
    if(month > 12)
    {
        return -1;
    }

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (day > daytab[leap][month])
    {
        return -1;
    }

    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}

/* set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    int maxdays = leap ? 366 : 365;

    if (yearday > maxdays)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}
