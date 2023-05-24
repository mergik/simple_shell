#include "main.h"

/**
 * initializeParameters - initialize params
 * @argv: command line argument
 * Return: params on success
 */
param *initializeParameters(char **argv)
{
	unsigned int i;
	param *params = malloc(sizeof(*params));

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
	for (i = 0; params->arguments[i]; i++)
		free(params->arguments[i]);
	free(params->arguments);
	free(params);
}
