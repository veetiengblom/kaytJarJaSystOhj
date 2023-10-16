//Project 2, my-unzip
//Parityönä tehty Veeti Engblom ja Teemu Harinen
//Lähteet:
//https://www.geeksforgeeks.org/fgetc-fputc-c/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Unzip the file and print to standart output
void unzipFile(FILE *fp) {
    int count;
    int currentChar;

    //Count the characters and print them
    while (fread(&count, sizeof(int), 1, fp) == 1) {
        currentChar = fgetc(fp);
        for (int i = 0; i < count; i++) {
            putchar(currentChar);
        }
    }
}


int main(int argc, char *argv[]) {


    if (argc == 1) {
        fprintf(stderr, "my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    // If one or more files given unzip files
    if (argc >= 2){
        for (int i = 1; i < argc; i++) {

            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("my-unzip: cannot open file '%s'\n", argv[i]);
                exit(1);
            }
            unzipFile(fp);
            fclose(fp);
        }
    }

    exit(0);
}