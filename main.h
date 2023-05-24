#ifndef _MAIN_H
#define _MAIN_H
#define MAX_COMMAND_LENGTH 1024

/* INBUILT LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

/* Declare the environ variable */
extern char **environ;

/**
 * struct parameters - struct used to hold shell variables for a simple shell.
 * @argv: An array of pointers to the command-line arguments.
 * @input: A pointer to the input buffer.
 * @arguments:array of strings containing the arguments to the current command.
 * @nextCommand: A pointer to the next command in the input buffer.
 * @argumentsNum: The number of arguments to the current command.
 * @lineCount: The line number of the current command.
 * @tokenCount: The number of tokens in the current command.
 * @status: The status of the current command.
 * @alias: list of environ variables.
 * @envn: list of aliases.
 */
typedef struct parameters
{
	char **argv;
	char *input;
	char **arguments;
	char *nextCommand;
	unsigned int argumentsNum;
	unsigned int lineCount;
	unsigned int tokenCount;
	int status;
	list_n *alias;
	list_n *envn;
} param;

/*function prototypes*/
param *initializeParameters(char **argv);
void freeParameters(param *params);
void printPrompt(void);
int parseInput(param *params);
char *searchPath(param *params);
void execute(param *params);
void builtIn(param *params);
void printError(param *params, char *out);
void intToString(int value, char *str);

/* Prototypes of our custom functions */
size_t _strlen(const char *str);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);

#endif
