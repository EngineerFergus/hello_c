#include <stdio.h>

/* removes comments from C source files */

#define OUT 0
#define SINGLELINECOMMENT 1
#define MULTILINECOMMENT 2
#define SINGLEQUOTES 3
#define DOUBLEQUOTES 4

int currentChar;
int nextChar;

int init();
int peek();
int advance();
int determineState(int prevC, int c, int nextC, int prevState);
int determineEntryState(int c, int nextC);
int determineExitState(int prevC, int c, int prevState);
void print(int c, int prevState, int state);

int main()
{
    init();

    int prevC, c, nextC, prevState, state;

    prevC = EOF;
    prevState = OUT;
    state = OUT;

    while ((c = advance()) != EOF)
    {
        nextC = peek();

        prevState = state;
        state = determineState(prevC, c, nextC, prevState);
        print(c, prevState, state);

        prevC = c;
    }
}

int init()
{
    int state;
    extern int currentChar;
    extern int nextChar;

    currentChar = getchar();
    if (currentChar == EOF)
    {
        nextChar = EOF;
    }
    else
    {
        nextChar = getchar();
    }
    
    state = determineState(' ', currentChar, nextChar, OUT);
    print(currentChar, OUT, state);

    return state;
}

int peek()
{
    extern int nextChar;
    return nextChar;
}

int advance()
{
    int temp;

    extern int currentChar;
    extern int nextChar;

    temp = getchar();

    if (temp == EOF)
    {
        currentChar = EOF;
        nextChar = EOF;
        return EOF;
    }
    else
    {
        currentChar = nextChar;
        nextChar = temp;
        return currentChar;
    }
}

int determineState(int prevC, int c, int nextC, int prevState)
{
    if(prevState == OUT)
    {
        return determineEntryState(c, nextC);
    }
    else
    {
        return determineExitState(prevC, c, prevState);
    }
}

int determineEntryState(int c, int nextC)
{
    if (c == '/' && nextC == '*')
    {
        return MULTILINECOMMENT;
    }
    else if (c == '/' && nextC == '/')
    {
        return SINGLELINECOMMENT;
    }
    else if (c == '\'')
    {
        return SINGLEQUOTES;
    }
    else if (c == '\"')
    {
        return DOUBLEQUOTES;
    }

    return OUT;
}

int determineExitState(int prevC, int c, int prevState)
{
    if (prevC == '*' && c == '/' && prevState == MULTILINECOMMENT)
    {
        return OUT;
    }
    else if (c == '\n' && prevState == SINGLELINECOMMENT)
    {
        return OUT;
    }
    else if (c == '\'' && prevState == SINGLEQUOTES)
    {
        return OUT;
    }
    else if (c == '\"' && prevState == DOUBLEQUOTES)
    {
        return OUT;
    }

    return prevState;
}

void print(int c, int prevState, int state)
{
    if (c == '\n')
    {
        putchar(c);
        return;
    }

    if (state == OUT && prevState == MULTILINECOMMENT)
    {
        return;
    }

    if (state == OUT)
    {
        putchar(c);
        return;
    }

    if (state  == DOUBLEQUOTES || state == SINGLEQUOTES)
    {
        putchar(c);
        return;
    }

    return;
}
