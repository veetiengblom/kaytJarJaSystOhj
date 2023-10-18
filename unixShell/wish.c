#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

#define PATH_MAX 64

char* search_path[PATH_MAX];
char* original_path[PATH_MAX];


// Function to print a simple error message to the standard error (stderr).
void print_error() {
    char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message));
}

// Function to tokenize input into arguments
void parse_input(char *input, char *args[]) {
    char *token = strtok(input, " \t\n");  // Tokenize the input using space, tab, and newline characters
    int i = 0;
    while (token != NULL) {
        args[i++] = token;  // Store each token as an argument
        token = strtok(NULL, " \t\n");  // Move to the next token
    }
    args[i] = NULL;  // Set the last element to NULL to mark the end of arguments
}

// Execute an external command
void execute_command(char *args[]) {
    pid_t pid = fork();  // Create a new process (child)

    if (pid == 0) {
        // Child process
        execvp(args[0], args);  // Replace the child process with the specified command
        // If execvp() fails, it returns here
        print_error();
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        wait(&status);  // Wait for the child process to complete
    } else {
        print_error();
    }
}

// Function to set the search path for external commands
void set_path(char *args[]) {
    int i = 1;
    while (args[i] != NULL) {
        search_path[i - 1] = args[i];
        i++;
    }
    search_path[i - 1] = NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 1 && argc != 2) {
        fprintf(stderr, "Usage: %s [batch_file]\n", argv[0]);
        exit(1);
    }

    int interactive = (argc == 1);  // Check if the program is in interactive mode

    FILE *input_file = stdin;
    if (!interactive) {
        input_file = fopen(argv[1], "r");  
        if (input_file == NULL) {
            print_error();  
            exit(1);  
        }
    }

    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];
    int checkPathError = 0;

    search_path[0] = "/bin"; // Default search path
    // Copy the default search path to the original_path array
    for (int i = 0; search_path[i] != NULL; i++) {
        original_path[i] = strdup(search_path[i]);
    }
    original_path[PATH_MAX - 1] = NULL;


    while (1) {
        if (interactive) {
            printf("wish> ");
        }

        if (fgets(input, sizeof(input), input_file) == NULL) {
            if (!interactive) {
                fclose(input_file);
            }
            exit(0);  
        }

        parse_input(input, args);  // Tokenize the input into arguments

        if (args[0] == NULL) {
            continue;  // Ignore empty input
        }

        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                print_error(); 
            } else if (chdir(args[1]) != 0) {
                print_error();  
            }
        }else if (strcmp(args[0], "path") == 0) {
            set_path(args);
        } else {
            // Check each directory in the search path
            int i = 0;
            while (search_path[i] != NULL) {
                char command_path[PATH_MAX];
                snprintf(command_path, PATH_MAX, "%s/%s", search_path[i], args[0]);
                if (access(command_path, X_OK) == 0) {
                    // Command found in the current directory in the search path
                    execute_command(args);
                    checkPathError = 1;
                    break;
                }
                i++;
            }
            if (checkPathError == 0) {
                print_error();
            }
            checkPathError = 0;
            // Restore the original search path
            for (int j = 0; original_path[j] != NULL; j++) {
                search_path[j] = strdup(original_path[j]);
            }
            search_path[PATH_MAX - 1] = NULL;
        }

    }
    return 0;

}
