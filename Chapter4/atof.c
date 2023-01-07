#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double atof(char s[]);
double atofSci(char s[]);
int getline(char line[], int max);

// Exercise 4-2

/* rudimentary calculator */
int main()
{
    double sum, atof(char []);

    char line[MAXLINE];

    sum = 0;
    while (getline(line, MAXLINE) > 0)
    {
        sum = atofSci(line);
        printf("%g\n", sum);
    }

    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for(i = 0; isspace(s[i]); i++)
        ;
    
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if(s[i] == '.')
    {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val  = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

double atofSci(char s[])
{
    double val, power;
    int i, sign, sciSign, sciPow;

    for(i = 0; isspace(s[i]); i++)
        ;
    
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if(s[i] == '.')
    {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val  = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if(s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }

    sciSign = (s[i] == '-') ? -1 : 1;

    printf("sciSign = %d\n", sciSign);

    if(s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (sciPow = 0; isdigit(s[i]); i++)
    {
        //val  = 10.0 * val + (s[i] - '0');
        sciPow = sciPow * 10 + (s[i] - '0');
    }

    printf("sciPow = %d\n", sciPow);

    double final = sign * val / power;

    for (i = 0; i < sciPow; i++)
    {
        if(sciSign > 0)
        {
            final *= 10.0;
        }
        else
        {
            final /= 10.0;
        }
    }

    return final;
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
