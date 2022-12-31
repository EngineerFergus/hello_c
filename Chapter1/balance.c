#include <stdio.h>

/* check for balanced braces in c source file */

#define OUT 0                   /* in normal text */
#define SINGLELINECOMMENT 1     /* in a single line comment */
#define MULTILINECOMMENT 2      /* in a multi line comment */
#define SINGLEQUOTES 3          /* in a single quoted string */
#define DOUBLEQUOTES 4          /* in a double quoted string */
#define ENTERCOMMENT 5          /* entering a comment */
#define EXITCOMMENT 6           /* exiting a comment */
#define ENTERQUOTES 7           /* entering a quoted string */
#define EXITQUOTES 8            /* exiting a quoted string */

int determineState(int prevC, int currC, int nextC, int prevState);
int determineEntryState(int prevC, int currC, int nextC);
int determineCommentState(int currC);
int determineQuoteState(int prevC);
int determineExitState(int prevC, int currC, int nextC, int prevState);

int main()
{
    int c0, c1, c2, state, prevState;
    int lSq, rSq, lCurl, rCurl, lParan, rParan;
    int startQuote, stopQuote, startComment, stopComment;

    lSq = rSq = lCurl = rCurl = lParan = rParan = startQuote = stopQuote = 0;
    startComment = stopComment = 0;

    prevState = OUT;
    c0 = '\0';
    c1 = getchar();

    while(c1 != EOF)
    {
        c2 = getchar();
        state = determineState(c0, c1, c2, prevState);

        if (state == OUT)
        {
            switch (c1)
            {
                case '[': ++lSq; break;
                case ']': ++rSq; break;
                case '(': ++lParan; break;
                case ')': ++rParan; break;
                case '{': ++lCurl; break;
                case '}': ++rCurl; break;
                default:
                    break;
            }
        }
        else if (state == ENTERQUOTES)
        {
            ++startQuote;
        }
        else if (state == EXITQUOTES)
        {
            ++stopQuote;
        }
        else if (prevState == ENTERCOMMENT && state == MULTILINECOMMENT)
        {
            ++startComment;
        }
        else if (state == EXITCOMMENT)
        {
            ++stopComment;
        }

        if (c1 == '\n')
        {
            putchar('\n'); // this is only used for console compatibility
        }
        
        prevState = state;
        c0 = c1;
        c1 = c2;
    }

    printf("Parantheses:   %d, %d\n", lParan, rParan);
    printf("Square Braces: %d, %d\n", lSq, rSq);
    printf("Curly Braces:  %d, %d\n", lCurl, rCurl);
    printf("Quotes:        %d, %d\n", startQuote, stopQuote);
    printf("Comments:      %d, %d\n", startComment, stopComment);

    return 0;
}

int determineState(int prevC, int currC, int nextC, int prevState)
{
    if (prevState == OUT)
    {
        return determineEntryState(prevC, currC, nextC);
    }

    if (prevState == ENTERCOMMENT)
    {
        return determineCommentState(currC);
    }

    if (prevState == ENTERQUOTES)
    {
        return determineQuoteState(prevC);
    }

    return determineExitState(prevC, currC, nextC, prevState);
}

// assuming OUT state, determine what state will be entered
int determineEntryState(int prevC, int currC, int nextC)
{
    if (currC == '/' && nextC == '*')
    {
        return ENTERCOMMENT;
    }
    else if (currC == '/' && nextC == '/')
    {
        return ENTERCOMMENT;
    }
    else if (currC == '\'')
    {
        return ENTERQUOTES;
    }
    else if (currC == '\"')
    {
        return ENTERQUOTES;
    }

    return OUT;
}

int determineCommentState(int currC)
{
    if(currC == '/')
    {
        return SINGLELINECOMMENT;
    }

    return MULTILINECOMMENT;
}

int determineQuoteState(int prevC)
{
    if (prevC == '\'')
    {
        return SINGLEQUOTES;
    }

    return DOUBLEQUOTES;
}

int determineExitState(int prevC, int currC, int nextC, int prevState)
{
    if (prevC == '*' && currC == '/' && prevState == MULTILINECOMMENT)
    {
        return EXITCOMMENT;
    }
    else if (currC == '\n' && prevState == SINGLELINECOMMENT)
    {
        return OUT;
    }
    else if (prevC != '\\' && currC == '\'' && prevState == SINGLEQUOTES)
    {
        return EXITQUOTES;
    }
    else if (prevC != '\\' && currC == '\"' && prevState == DOUBLEQUOTES)
    {
        return EXITQUOTES;
    }
    else if (prevState == EXITCOMMENT || prevState == EXITQUOTES)
    {
        return OUT;
    }

    return prevState;
}
