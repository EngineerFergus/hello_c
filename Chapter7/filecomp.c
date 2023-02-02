#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELENGTH 1024

/* checks that FILE is not NULL and exits with error state if it is */
void ensureNotNull(FILE *fp, char *programName, char *fileName);

int main(int argc, char **argv)
{
    char *prog = argv[0];
    char lineA[LINELENGTH], lineB[LINELENGTH];
    char *tempA, *tempB;

    if (argc < 3)
    {
        fprintf(stderr, "%s: expected 2 filenames for input", *prog);
        exit(1);
    }

    char *fileAPath = argv[1];
    char *fileBPath = argv[2];

    FILE *fileA = fopen(fileAPath, "r");
    FILE *fileB = fopen(fileBPath, "r");
    ensureNotNull(fileA, prog, fileAPath);
    ensureNotNull(fileB, prog, fileBPath);

    while ((tempA = fgets(lineA, LINELENGTH, fileA)) != NULL 
        && (tempB = fgets(lineB, LINELENGTH, fileB)) != NULL)
    {
        if (strcmp(tempA, tempB) != 0)
        {
            fprintf(stdout, "%s", tempA);
            fprintf(stdout, "%s", tempB);
            break;
        }
    }

    fclose(fileA);
    fclose(fileB);

    return 0;
}

void ensureNotNull(FILE *fp, char *programName, char *fileName)
{
    if (fp == NULL)
    {
        fprintf(stderr, "%s: could not open file at %s", programName, fileName);
        exit(2);
    }
}
