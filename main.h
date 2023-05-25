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
 * struct list - struct for singly linked list.
 * @length: size of data string.
 * @valueLength: size of string data.
 * @string: data string.
 * @value: string data value.
 * @nextNode: pointer to the next node in the list.
*/
typedef struct list
{
	unsigned int length;
	unsigned int valueLength;
	char *string;
	char *value;
	struct list *nextNode;
} list_n;

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

/**
 * struct current_operation - a buildin function
 * @cmd: builtin command
 * @func: pointer to buildin function
 */
typedef struct current_operation
{
	char *cmd;
	void (*func)(param *);
} op_t;

/* Function prototypes */
param *initializeParameters(char **argv, char *env[]);
void freeParameters(param *params);
void freeNodeList(list_n *head);
void printPrompt(void);
int parseInput(param *params);
char *searchPath(param *params);
void execute(param *params);
void printError(param *params, char *out);
void intToString(int value, char *str);
list_n *addNodeList(list_n **head, char *str, char *value);
list_n *getNodeList(list_n *head, char *str);
void (*myBuitIns(param *params))(param *);
void printEnvList(list_n *head);
int stringToInt(char *s);
void EXIT(param *params);
int numValidator(char *str);
int _isDelim(char character, char *delim);

/* Prototypes of our custom functions */
size_t _strlen(const char *str);
char *_strdup(const char *str);
char *_strcat(char *string1, char *string2);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *string1, char *string2);
char *_strchr(char *str, char character);
char *_getenv(char *name, const param *parameters);
void _setenv(param *params);
void _unsetenv(param *params);
void _printenv(param *params);
char *_strtok(char *string, char *delim, char **state);

#endif
