//Project 2, my-zip
//Parityönä tehty Veeti Engblom ja Teemu Harinen
//Lähteet:
//https://stackoverflow.com/questions/22335261/read-from-a-file-using-getc-and-print-using-putc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void zipFile(FILE *fp) {
    int prevChar = -1;
    int counter = 0;
    int currentChar;

    //Read string character by character and write to zip file when the character changes
    while ((currentChar = fgetc(fp)) != -1) {
        if (currentChar == prevChar) {
            counter++;
        } else {
            if (prevChar != EOF) {
                fwrite(&counter, sizeof(int), 1, stdout);
                putchar(prevChar);
            }
            counter = 1;
            prevChar = currentChar;
        }
    }

    //Handle the last character
    if (prevChar != -1) {
        fwrite(&counter, sizeof(int), 1, stdout);
        putchar(prevChar);
    }
}


int main(int argc, char *argv[]) {


    if (argc == 1) {
        fprintf(stderr, "my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    // If one or more files given zip files
    if (argc >= 2){
        for (int i = 1; i < argc; i++) {

            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("my-zip: cannot open file '%s'\n", argv[i]);
                exit(1);
            }
            zipFile(fp);
            fclose(fp);
        }
    }

    exit(0);
}