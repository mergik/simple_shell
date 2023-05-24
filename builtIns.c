#include "main.h"

/**
 * EXIT - our custom exit function
 * @params: parameters struct
 */
void EXIT(param *params)
{
	int status = 0;

	if (!params->arguments[1])
	{
		status = params->status;
		freeParameters(params);
		exit(status);
	}
	if (numValidator(params->arguments[1]))
	{
		status = stringToInt((params->arguments)[1]);
		if (status == -1)
		{
			printError(params, "Illegal number: ");
			write(STDERR_FILENO, params->arguments[1],
			      _strlen(params->arguments[1]));
			write(STDERR_FILENO, "\n", 1);
			params->status = 2;
			return;
		}
		freeParameters(params);
		exit(status);
	}
	else
	{
		params->status = 2;
		printError(params, "Illegal number: ");
		write(STDERR_FILENO, params->arguments[1],
		      _strlen(params->arguments[1]));
		write(STDERR_FILENO, "\n", 1);
	}
}