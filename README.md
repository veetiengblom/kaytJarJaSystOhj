# kaytJarJaSystOhj
Käyttöjärjestelmät ja systeemiohjemointi projektit

Project 1 – Warmup to C and Unix programming

How to run project:
Reverse program reverses given input (from a file or by the user) and writes it to terminal or a given file.
prompt> ./reverse [file1] [file2]


Project 2 – Unix Utilities

This project has 4 different programs.
How to run each program:

My-cat:
My-cat reads a file and prints it to terminal
prompt> ./my-cat file1 [file2] ...

My-grep:
My-grep goes through given file or user input and checks if given string is in the input.
prompt> ./my-grep string [file1] [file2] ...

My-zip:
My-zip compresses a file in a simple way. Example of the compression: "aaaabb" --> "4a2b"
prompt> ./my-zip file1 [file2] ...

My-unzip:
My-unizp decompresses a file by reversing what my-zip did. Example of the decompression: "4a2b" --> "aaaabb"
prompt> ./my-unzip file1 [file2] ...


Project 3 – Unix Shell

How to run project:
Wish is a simple Unix Shell. The program can recieve one command line argument that is a text file. If a file is given it reads the commands from there. If no file is given the program starts an interactive mode, where the user can give commands.
prompt> ./wish [file1]
