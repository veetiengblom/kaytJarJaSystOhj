//Project 2, my-cat
//Parityönä tehty Veeti Engblom ja Teemu Harinen
//Lähteet:
//https://riptutorial.com/c/example/29223/read-lines-from-a-file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc == 1) {
        fprintf(stdout, "No files specified, ending program\n");
        exit(0);
    }

    if (argc >= 2){
        for (int i = 1; i < argc; i++) {
            char *lineBuffer = NULL;
            size_t lenBuffer = 0;
            ssize_t read;

            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("my-cat: cannot open file '%s'\n", argv[i]);
                exit(1);
            }
            fprintf(stdout, "Printing out the contents of the file '%s'\n\n", argv[i]);
            while ((read = getline(&lineBuffer, &lenBuffer, fp) != -1)) {
                printf("%s", lineBuffer);
            }
            fclose(fp);
            fprintf(stdout, "\n ---EOF for file '%s'---\n\n", argv[i]);
        }
    }
    return 0;
}