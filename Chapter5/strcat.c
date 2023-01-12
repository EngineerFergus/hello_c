#include <stdio.h>
#include <string.h>
#include "getline.h"

#define LINELENGTH 256

void strcatpointer(char* s, char* t);

int main()
{
    int c;
    int isOn = 1;
    char line[LINELENGTH], s[LINELENGTH], t[LINELENGTH];


    while((c = getline(line, LINELENGTH)) > 0)
    {
        if(isOn)
        {
            strcpy(s, line);
            isOn = 0;
        }
        else
        {
            strcpy(t, line);
            isOn = 1;
            strcatpointer(s, t);
            printf("Concatenated: %s\n", s);
        }
    }

    return 0;
}

/* concatenate t to end of s; s must be big enough */
// void strcat(char s[], char t[])
// {
//     int i, j;

//     i = j = 0;

//     while (s[i] != '\0')
//     {
//         i++; // find end of s
//     }

//     while ((s[i++] = t[j++]) != '\0') // copy t
//         ;
// }

/* Do the stuff with pointers and copy t to end of s */
void strcatpointer(char* s, char* t)
{
    while (*s != '\0')
    {
        s++; // find end of s
    }

    while ((*s++ = *t++) != '\0')
        ;
}
