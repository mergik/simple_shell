#include "main.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 * @parameters: Pointer to parameter struct containing the environment list.
 * Return: A pointer to the value of the environment variable, or NULL if not.
 */
char *_getenv(char *name, const param *parameters)
{
	list_n *ptr = parameters->envn;

	while (ptr)
	{
		if (!_strcmp(name, ptr->string))
			return (_strdup(ptr->value));
		ptr = ptr->nextNode;
	}
	return (NULL);
}

/**
 * _setenv - searches environment list for environment variable name
 * @params: accesses the parameter struct for values
*/
void _setenv(param *params)
{
	char *tmp = NULL;
	char *name = params->arguments[1], *val = params->arguments[2];
	list_n *head = params->envn;

	if (params->tokenCount != 3)
	{
		params->status = 0;
		return;
	}

	for (; head != NULL; head = head->nextNode)
	{
		if (_strcmp(name, head->string) == 0) /* Environment variable exists */
		{
			tmp = head->value;
			free(tmp);
			head->value = _strdup(val);
			if (!head->value)
			{
				write(STDERR_FILENO, "setenv malloc error\n", 18);
				exit(-1);
			}
			head->valueLength = _strlen(val);
			params->status = 0;
			return;
		}
	}

	/* Environment variable does not exist */
	params->envn = addNodeList(&(params->envn), name, val);
	params->status = 0;
}

/**
 * _unsetenv - searches environment for env variable name and removes it.
 * @params: parameters struct
*/
void _unsetenv(param *params)
{
	char *name = params->arguments[1];
	list_n *prevNode = NULL;
	list_n *currNode = params->envn;
	if (params->tokenCount != 2)
	{
		params->status = 0;
		return;
	}

	for (; currNode; currNode = currNode->nextNode)
	{
		if (_strcmp(name, currNode->string) == 0)
		{
			if (currNode == params->envn)
				params->envn = currNode->nextNode;
			else
				prevNode->nextNode = currNode->nextNode;
			free(currNode->string);
			free(currNode->value);
			free(currNode);
			params->status = 0;
			return;
		}
		prevNode = currNode;
	}

	params->status = 0;
}

/**
 * _printenv - prints the environment
 * @params: parameters struct
 * Return: void
 */
void _printenv(param *params)
{
	if (params->tokenCount != 1)
	{
		char error_message[100];
		int length = snprintf(error_message, sizeof(error_message), "env: %s: No such file or directory\n",
		params->arguments[1]);
		write(STDOUT_FILENO, error_message, length);
		params->status = 2;
		return;
	}
	printEnvList(params->envn);
	params->status = 0;
}

/**
 * printEnvList - prints the environment variables
 * @head: pointer to the head of the environment list
*/
void printEnvList(list_n *head)
{
	if (head)
	{
		printEnvList(head->nextNode);
		if (head->string)
		{
			char buffer[256];
			int len = snprintf(buffer, sizeof(buffer), "%s=%s\n", head->string, head->value);
			
			write(STDOUT_FILENO, buffer, len);
		}
	}
}

