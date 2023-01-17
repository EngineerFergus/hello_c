#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "getch.h"
#include "stack.h"
#include "getop.h"
#define MAXOP 100

int getopnew(char s[], char* pinput);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    int i = 1;

    while (--argc > 0 && (type = getopnew(s, argv[i])) != EOF)
    {
        i++;
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
            case 'm': // for command line compatibility
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero division\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    
    printf("\t%.8g\n", pop());

    return 0;
}

int getopnew(char s[], char* pinput)
{
    int i, c;

    s[0] = '\0';
    s[1] = '\0';

    while (*pinput == ' ' || *pinput == '\t')
    {
        pinput++; // skip white space
    }

    if (!isdigit(*pinput) && *pinput != '.')
    {
        s[0] = *pinput;
        return *pinput;
    }

    i = 0;
    if (isdigit(*pinput))
    {
        while(isdigit(*pinput))
        {
            s[i] = *pinput;
            i++;
            pinput++;
        }
    }

    if (*pinput == '.')
    {
        s[i] = *pinput;
        i++;
        pinput++;
        while (isdigit(*pinput))
        {
            s[i] = *pinput;
            i++;
            pinput++;
        }
    }

    s[i] = '\0';
    return NUMBER;
}
