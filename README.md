# SIMPLE SHELL

## Description

This is our implementation of a simple command-line interpreter written in C. This project, known as a "simple shell", emulates basic functionalities of the Unix shell. It can handle command lines with arguments, manage the PATH, implement built-in commands, and execute external programs. The shell supports features such as environment variable manipulation, error handling, and memory management. It's designed to run on Ubuntu 20.04 LTS and is compiled using gcc with specific flags to ensure code quality and adherence to the C89 standard. This project demonstrates fundamental concepts of operating systems, process creation and management, and low-level I/O operations in C programming.

## Usage

- Platform `Ubuntu 20.04`
- Compiler `gcc`
- Compilation `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- Testing `./hsh`

| Project Name | Description |
| ------------ | ----------- |
|  `main.h` | Our main header file                          |
|  `main.c` | Our shell entry point                         |
|  `parameters.c` | Initialize parameters struct and allocated required memory |
|  `inputs.c`   | Process the input strings into tokens     |
|  `lists.c`   | Handle Linked lists                        |
|  `env.c`     | Get, set, unset, & print environment variables |
|  `execute.c`   | Execute commands                         |
|  `builtins.c` | Handle built-in commands                  |
|  `printError.c` | Print error message to standard output  |
|  `searchPath` | Searches for executable from PATH         |
|  `mystrcat.c` | Concatenate two strings                   |
|  `mystrcmp.c` | Compare two strings                       |
|  `mystrcpy.c` | Copy a string from source to destination  |
|  `mystrdup.c` | Duplicate a string                        |
|  `mystrlen.c` | Calculate the length of a string          |
|  `mystrchr.c` | Searches for string character from provided string  |
|  `mystrtok.c` | Tokenizes strings                         |

## List of allowed functions and system calls

-   `access` (man 2 access)
-   `chdir` (man 2 chdir)
-   `close` (man 2 close)
-   `closedir` (man 3 closedir)
-   `execve` (man 2 execve)
-   `exit` (man 3 exit)
-   `_exit` (man 2 _exit)
-   `fflush` (man 3 fflush)
-   `fork` (man 2 fork)
-   `free` (man 3 free)
-   `getcwd` (man 3 getcwd)
-   `getline` (man 3 getline)
-   `getpid` (man 2 getpid)
-   `isatty` (man 3 isatty)
-   `kill` (man 2 kill)
-   `malloc` (man 3 malloc)
-   `open` (man 2 open)
-   `opendir` (man 3 opendir)
-   `perror` (man 3 perror)
-   `read` (man 2 read)
-   `readdir` (man 3 readdir)
-   `signal` (man 2 signal)
-   `stat` (__xstat) (man 2 stat)
-   `lstat` (__lxstat) (man 2 lstat)
-   `fstat` (__fxstat) (man 2 fstat)
-   `strtok` (man 3 strtok)
-   `wait` (man 2 wait)
-   `waitpid` (man 2 waitpid)
-   `wait3` (man 2 wait3)
-   `wait4` (man 2 wait4)
-   `write` (man 2 write)

## Disclaimer

This is a learning project and contains many limitations and bugs. It is not intended for production use.

---
## LAST UPDATE
25TH MAY 2023
