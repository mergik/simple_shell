#include "main.h"

/**
 * parseInput - process the input string into tokens
 * @params: string to be tokenized
 *
 * Return: number of tokens
 */
int parseInput(param *params)
{
	char *token = NULL, *aka = NULL, *val;
	list_n *node;

	token = strtok(params->nextCommand, " \n\t");
	if (!token)
	{
		params->tokenCount = 0;
		return 0;
	}
	node = getNodeList(params->alias, token);
	if (node != NULL)
	{
		free(token);
		token = NULL;
		aka = _strdup(node->value);
		if (!aka)
		{
			write(STDERR_FILENO, "alias expansion malloc error\n", 28);
			freeParameters(params);
			exit(-1);
		}
		val = strtok(aka, " \n\t");
		params->arguments[params->tokenCount++] = val;
		do
		{
			val = strtok(NULL, " \n\t");
			params->arguments[params->tokenCount++] = val;
		} while (val);
		free(aka);
	}
	else
		params->arguments[params->tokenCount++] = token;
	token = strtok(params->nextCommand, " \n\t");
	params->arguments[params->tokenCount++] = token;
	do
	{
		token = strtok(NULL, " \n\t");
		params->arguments[params->tokenCount++] = token;
		if (params->tokenCount == params->argumentsNum)
		{
			params->argumentsNum += 10;
			params->arguments = realloc(params->arguments, params->argumentsNum * sizeof(char*));
			if (!params->arguments)
			{
				write(STDERR_FILENO, "realloc error\n", 14);
				freeParameters(params);
				exit(-1);
			}
		}
	} while (token);
	return params->tokenCount - 1;
}
