//Project 1, Reverse
//Parityönä tehty Veeti Engblom ja Teemu Harinen
//Tiedostojen lukeminen ja kirjoittaminen on tehty käyttäen apuna
//https://www.geeksforgeeks.org/c-program-to-reverse-the-content-of-the-file-and-print-it/
//https://stackoverflow.com/questions/3501338/c-read-file-line-by-line



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Reverse input file, write in reverse to output file or print in terminal

void reverseFile(FILE *input, FILE *output) {
    char **lines = NULL;
    size_t len = 0;
    char *line = NULL;
    ssize_t read;
    int counter = 0;
    
    // Read lines into an array of strings
    while ((read = getline(&line, &len, input)) != -1) {
        lines = (char **)realloc(lines, (len + 1) * sizeof(char *));
        if (lines == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
        lines[counter] = strdup(line);
        len++;
        counter++;
    }
    
    free(line);

    // Print lines in reverse order
    for (ssize_t i = counter - 1; i >= 0; i--) {
        fprintf(output, "%s", lines[i]);
        free(lines[i]);
    }

    free(lines);
    return;
}

//Reverse given user input

void reverseUserInput() {
    char *line = NULL;
    size_t len;
    char lines[128][128];
    int counter = 0;
    
    fprintf(stdout, "Provide inputs and enter 'END' to terminate: \n\n");
    //Read lines into array from user input
    while(getline(&line, &len, stdin) != -1)
    {
        if (strcmp(line, "END\n") == 0)	{
            break;
        }

        if (strcmp(line, "\n") == 0) {
            fprintf(stdout, "ERROR: Please enter words as input!\n\n");
            exit(1);
        }
        
        strcpy(lines[counter], line);
        counter++;					
        
    }
    free(line);
    
    fprintf(stdout, "\n");
    
    fprintf(stdout, "Inputs in reverse order: \n\n");

    //Print array in reverse order

    for (int i = counter - 1; i >= 0; i--) {
        fprintf(stdout, "%s", lines[i]);
    }
    fprintf(stdout, "\n");
    return;
}


int main(int argc, char *argv[]) {
    FILE *input = stdin;
    FILE *output = stdout;

    // Handle command-line arguments
    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    } else if (argc >= 2) {
        input = fopen(argv[1], "r");
        if (input == NULL) {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }

        if (argc == 3) {
            if (strcmp(argv[1], argv[2]) == 0) {
                fprintf(stderr, "Input and output file must differ");
                fclose(input);
                exit(1);
            }
            output = fopen(argv[2], "w");
            if (output == NULL) {
                fclose(input);
                fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
                exit(1);
            }
        }
    }

    //Handle reversing based on command line arguments
    if(argc == 1) {
        reverseUserInput();
    } else {
        reverseFile(input, output);
    }

    // Close files if not stdin or stdout
    if (input != stdin) {
        fclose(input);
    }
    if (output != stdout) {
        fclose(output);
    }

    return 0;
}
