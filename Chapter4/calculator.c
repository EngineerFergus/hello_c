#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */
#define NAME '1'        /* signal that a named operator was found */

/* Exercises 4-3 to 4-10 */

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void swap(void);
void clear(void);
int mathfunc(char []);

double ans = 0.0; // last printed value


/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                if(!mathfunc(s))
                {
                    printf("error: unknown function provided\n");
                }
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2  = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push((long) pop() % (long) op2);
                }
                else
                {
                    printf("error: zero divisor in mod\n");
                }
                break;
            case '\n':
                ans = pop();
                printf("\t%.8g\n", ans);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

#define MAXVAL 100      /* max depth of the val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* retrieve the top value on the stack without removing */
double peek(void)
{
    double top = pop();
    push(top);
    return top;
}

/* swap the top two elements on the stack */
void swap(void)
{
    double top1, top2;
    top1 = pop();
    top2 = pop();
    push(top1);
    push(top2);
}

/* clear the stack */
void clear(void)
{
    sp = 0;
}

int mathfunc(char name[])
{
    if(!strcmp(name, "sin"))
    {
        push(sin(pop()));
    }
    else if (!strcmp(name, "exp"))
    {
        push(exp(pop()));
    }
    else if (!strcmp(name, "pow"))
    {
        double op2 = pop();
        push(pow(pop(), op2));
    }
    else if (!strcmp(name, "peek"))
    {
        printf("The top of the stack is %f\n", peek());
    }
    else if (!strcmp(name, "dup"))
    {
        double top = peek();
        push(top);
        printf("Duplicated %f on top of stack\n", top);
    }
    else if (!strcmp(name, "swap"))
    {
        swap();
        printf("Swapped top two values of stack\n");
    }
    else if (!strcmp(name, "ans"))
    {
        push(ans);
    }
    else
    {
        return 0;
    }

    return 1;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	i = 0;
	if (c == '-')                      /* check sign */
		if (!isdigit(s[++i] = c = getch())) {
			ungetch(c);                    
			c = s[0];                  /* not a sign */
		}

    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        ungetch(c);
        return strlen(s) == 1 ? s[0] : NAME;
    }        

	if (!isdigit(c) && c != '.')
		return c;                      /* not a number */

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if( c == '.')                      /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/* getch: get a possibly pushed back character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
