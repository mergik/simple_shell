#include "main.h"

/**
 * execute - execute the given command
 * @params: command to be executed
 */
void execute(param *params)
{
	char *command = NULL;
	pid_t pid;
	void (*builtIn)(param *);

	builtIn = myBuitIns(params);
	if (builtIn)
	{
		builtIn(params);
		return;
	}

	command = searchPath(params);
	if (!command)
		return;
	pid = fork();
	if (pid < 0)
	{
		freeParameters(params);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		execve(command, params->arguments, NULL);
	else
	{
		wait(&params->status);
		params->status = WEXITSTATUS(params->status);
		free(command);
	}
}