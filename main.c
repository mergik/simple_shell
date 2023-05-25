#include "main.h"

/**
 * main - main function
 * @argc: argument size
 * @argv: argument list
 * @env: environment
 * Return: 0 if successful
 */
int main(int argc, char *argv[], char *env[])
{
	int errCheck = -2, errStatus;
	unsigned int i;
	param *params = NULL;
	size_t size = MAX_COMMAND_LENGTH;
	char *state = NULL;
	bool interactive;

	(void)argc;/*we declare argc to be unused*/

	params = initializeParameters(argv, env);
	if (!params)
		exit(-1);
	signal(SIGINT, SIG_DFL);
	interactive = isatty(STDIN_FILENO);
	while (true)
	{
		if (errCheck == -1)
		{
			errStatus = params->status;
			printPrompt();
			freeParameters(params);
			return (errStatus);
		}
		for (i = 0; i < MAX_COMMAND_LENGTH; i++)
			(params->input)[i] = 0;
		params->tokenCount = 0;
		if (interactive)
			printPrompt(); /* Print prompt */
		errCheck = getline(&params->input, &size, stdin);
		params->lineCount++;
		if (errCheck == -1 && _strlen(params->input) == 0)
		{
			errStatus = params->status;
			freeParameters(params);
			return (errStatus);
		}
		params->nextCommand = _strtok(params->input, ";\n", &state);
		while (params->nextCommand)
		{
			params->tokenCount = parseInput(params);
			if (params->tokenCount == 0)
				break;
			execute(params);
			for (i = 0; i < params->argumentsNum; i++)
			{
				free(params->arguments[i]);
				params->arguments[i] = NULL;
			}
			params->tokenCount = 0;
			free(params->nextCommand);
			params->nextCommand = _strtok(params->input, ";\n", &state);
		}
	}
}

/**
   * printPrompt - displays the shell prompt
    */
void printPrompt(void)
{
		char *display =  "Kingfish:$ ";

			write(STDOUT_FILENO, display, strlen(display));
}
