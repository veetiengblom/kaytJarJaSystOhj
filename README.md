# Käyttöjärjestelmät ja systeemiohjemointi
Projects 1, 2 and 3
<br />
<br />
Project 1 – Warmup to C and Unix programming
<br />
How to run project:
<br />
`prompt> ./reverse [file1] [file2]`
<br />
Reverse program reverses given input (from a file or by the user) and writes it to terminal or a given file.
<br />
<br />
<br />
Project 2 – Unix Utilities
<br />
This project has 4 different programs.
<br />
How to run each program:
<br />
<br />
My-cat:
<br />
`prompt> ./my-cat file1 [file2] ...`
<br />
My-cat reads a file and prints it to terminal
<br />
<br />
My-grep:
<br />
`prompt> ./my-grep string [file1] [file2] ...`
<br />
My-grep goes through given file or user input and checks if given string is in the input.
<br />
<br />
My-zip:
<br />
`prompt> ./my-zip file1 [file2] ...`
<br />
My-zip compresses a file in a simple way. Example of the compression: "aaaabb" --> "4a2b"
<br />
<br />
My-unzip:
<br />
`prompt> ./my-unzip file1 [file2] ...`
<br />
My-unizp decompresses a file by reversing what my-zip did. Example of the decompression: "4a2b" --> "aaaabb"
<br />
<br />
<br />
Project 3 – Unix Shell
<br />
How to run project:
<br />
`prompt> ./wish [file1]`
<br />
Wish is a simple Unix Shell. The program can recieve one command line argument that is a text file. If a file is given it reads the commands from there. If no file is given the program starts an interactive mode, where the user can give commands.
