#include "main.h"

/**
 * initializeParameters - initialize params
 * @argv: command line argument
 * @env: environment variable
 * Return: params on success
 */
param *initializeParameters(char **argv, char *env[])
{
	unsigned int i;
	param *params = malloc(sizeof(*params));
	char *equal = NULL;

	if (!params)
		return (NULL);
	params->argumentsNum = 18;
	params->lineCount = 0;
	params->tokenCount = 0;
	params->status = 0;
	params->argv = argv;
	params->nextCommand = NULL;
	params->input = malloc(sizeof(char) * MAX_COMMAND_LENGTH);
	if (!(params->input))
	{
		free(params);
		exit(-1);
	}
	for (i = 0; i < MAX_COMMAND_LENGTH; i++)
		params->input[i] = 0;
	params->arguments = malloc(sizeof(char *) * params->argumentsNum);
	if (!(params->arguments))
	{
		free(params->input);
		free(params);
		exit(-1);
	}
	for (i = 0; i < params->argumentsNum; i++)
		params->arguments[i] = NULL;
	params->envn = NULL;
	for (i = 0; env[i]; i++)
	{
		equal = _strchr(env[i], '=');
		*equal = '\0';
		params->envn = addNodeList(&(params->envn),
					    env[i], equal + 1);
		if (!(params->envn))
		{
			free(params->input);
			free(params->arguments);
			freeNodeList(params->envn);
			free(params);
			exit(-1);
		}
	}
	params->alias = NULL;
	return (params);
}

/**
 * freeParameters - Frees memory allocated for the paramaters structure.
 * @params: pointer to parameters structure to free
 */
void freeParameters(param *params)
{
	int i;

	if (params->input)
		free(params->input);
	if (params->nextCommand)
		free(params->nextCommand);
	freeNodeList(params->envn);
	freeNodeList(params->alias);
	for (i = 0; params->arguments[i]; i++)
		free(params->arguments[i]);
	free(params->arguments);
	free(params);
}
/**
 * freeNodeList - frees the memory assigned to the linked list
 * @head: pointer to head of the linked list
 */
void freeNodeList(list_n *head)
{
	list_n *ptr = head;

	while (head != NULL)
	{
		ptr = head->nextNode;
		free(head->string);
		free(head->value);
		free(head);
		head = ptr;
	}
}
