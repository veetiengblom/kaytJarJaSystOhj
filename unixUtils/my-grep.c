//Project 2, my-grep
//Parityönä tehty Veeti Engblom ja Teemu Harinen
//Lähteet:
//https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void findMatches(FILE *fp, const char *searchTerm) {
    char *lineBuffer = NULL;
    size_t lenBuffer = 0;
    ssize_t read;

    //Check if string contains search term and if so print it out
    while ((read = getline(&lineBuffer, &lenBuffer, fp) != -1)) {
        if (strstr(lineBuffer, searchTerm) != NULL) {
            printf("%s", lineBuffer);
        }
    }

    free(lineBuffer);
}

void stdinFindMatches(FILE *fp, const char *searchTerm) {
    char *lineBuffer = NULL;
    size_t lenBuffer = 0;
    ssize_t read;

    //Check if string contains search term and if so print it out
    while ((read = getline(&lineBuffer, &lenBuffer, fp) != -1)) {
        if (strstr(lineBuffer, searchTerm) != NULL) {
            printf("%s", lineBuffer);
        }
        if (strcmp(lineBuffer, "END\n") == 0)	{
            break;
        }
    }

    free(lineBuffer);
}


int main(int argc, char *argv[]) {

    const char *searchTerm = argv[1];

    if (argc == 1) {
        fprintf(stderr, "my-grep: searchterm [file ...]\n");
        exit(1);
    }
    // If no file given, read from stdin
    if (argc == 2) {
        printf("Enter text to search from, write 'END' to terminate: \n");
        stdinFindMatches(stdin, searchTerm);
        exit(0);
    }

    // If one or more files given read from file
    if (argc > 2){
        for (int i = 2; i < argc; i++) {

            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("my-grep: cannot open file '%s'\n", argv[i]);
                exit(1);
            }
            findMatches(fp, searchTerm);
            fclose(fp);
        }
    }

    exit(0);
}