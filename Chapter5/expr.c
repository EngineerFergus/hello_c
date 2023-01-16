#include <stdio.h>
#include <stdlib.h>
#include "getch.h"
#include "stack.h"
#include "getop.h"
#define MAXOP 100

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    int i = 1;

    while (--argc > 0 && (type = getopfrominput(s, argv[i])) != EOF)
    {
        i++;
        printf("%s\n", s);
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


