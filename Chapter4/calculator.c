#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAXOP       100     /* max size of operand or operator */
#define NUMBER      '0'     /* signal that a number was found */
#define NAME        '1'     /* signal that a named operator was found */
#define VAR         '2'     /* signal that a single letter variable was found */
#define MAXVAL      100     /* max depth of the val stack */
#define BUFSIZE     100     /* max size of getch buffer */
#define MAXVAR      26      /* max number of variables */
#define MAXLINE     1000    /* maximum line size */

/* Exercises 4-3 to 4-10 */

int     getop(char []);
int     getopbyline(char []);
void    push(double);
double  pop(void);
double  peek(void);
void    swap(void);
void    clear(void);
int     mathfunc(char []);
int     getch(void);
void    ungetch(int);
void    setvar(int);
double  getvar(int);
void    ungets(char []);
int     getline(char [], int);

double  val[MAXVAL];    /* value stack */
double  vars[MAXVAR];   /* variables storage */
double  ans = 0.0;      /* stores last printed value */
int     sp = 0;         /* next free stack position */
int     bufp = 0;       /* next free position in buf */
int     buf[BUFSIZE];   /* buffer for ungetch */

/* reverse Polish calculator */
int main()
{
    int i;

    for (i = 0; i < MAXVAR; i++)
    {
        vars[i] = 0.0;
    }

    int type, variable;
    double op2;
    char s[MAXOP];

    variable = 'a';

    while ((type = getopbyline(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                if(!mathfunc(s))
                {
                    printf("error: unknown function provided %s\n", s);
                }
                break;
            case VAR:
                push(getvar(s[0]));
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
            case '=':
                setvar(variable);
                break;
            default:
                if (islower(type))
                {
                    variable = type; // remember last variable name
                }
                else
                {
                    printf("error in main: unknown command %s\n", s);
                }
                break;
        }
    }

    return 0;
}

/* push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop and return top value from stack */
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

/* performs predefined math operations */
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

/* get next operator or numeric operand */
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
        return strlen(s) == 1 ? VAR : NAME;
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

/* get next operator or numeric operand using getline instead of getch/ungetch */
int getopbyline(char s[])
{
    static int i, len;
    static char line[MAXLINE];
    int j;

    // get new line if finished reading current one
    if (i == len)
    {
        len = getline(line, MAXLINE);
        if (len == 0)
        {
            return EOF;
        }
        i = 0;
    }

    j = 0;
    while (isblank(line[i]))
    {
        i++;
    }

    // check if negative number
    if (line[i] == '-' && isdigit(line[i + 1]))
    {
        s[j++] = line[i++]; // push negative sign into buffer
    }

    if (isalpha(line[i]))
    {
        while (isalpha(line[i]))
        {
            s[j++] = line[i++];
        }

        s[j] = '\0';
        return (strlen(s) == 1) ? VAR : NAME;
    }

    if (!isdigit(line[i]) && line[i] != '.')
    {
        return line[i++];
    }

    if (isdigit(line[i]))
    {
        while (isdigit(line[i]))
        {
            s[j++] = line[i++];
        }
    }

    if (line[i] == '.')
    {
        s[j] = line[i];
        i++;
        j++;
        while (isdigit(line[i]))
        {
            s[j++] = line[i++];
        }
    }

    s[j] = '\0';
    return NUMBER;
}

/* get a possibly pushed back character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
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

/* sets variable slot var to top value of stack */
void setvar(int var)
{
    if(var >= 'a' && var <= 'z')
    {
        vars[var - 'a'] = pop();
    }
    else
    {
        printf("error: tried setting unknown variable name\n");
    }
}

/* retrieves the variable value from stored values */
double getvar(int var)
{
    if(var >= 'a' && var <= 'z')
    {
        return vars[var - 'a'];
    }
    else
    {
        printf("error: tried getting unknown variable name\n");
        return 0.0;
    }
}

/* pushes as entire string back onto the buffer */
void ungets(char s[])
{
    int i;

    for (i = strlen(s) - 1; i >= 0; i--)
    {
        ungetch(s[i]);
    }
}

/* retrieves the next line of characters from the input and returns the length of the line */
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
