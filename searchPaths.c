#include "main.h"

char *searchPath(param *params)
{
    char *path = NULL, *pathCopy = NULL, *fullPath = NULL, *temp = NULL;
    char *pathToken, *state = NULL;

    if (access(params->arguments[0], F_OK | X_OK) == 0)
    {
        free(path);
        return _strdup(params->arguments[0]);
    }
    if (errno == EACCES)
    {
        params->status = 126;
        printError(params, "Permission denied\n");
        return NULL;
    }
    path = _getenv("PATH", params);
    if (!path)
    {
        printError(params, "1st not found\n");
        return (NULL);
    }
    for (pathToken = _strtok(path, ":", &state); pathToken; pathToken = _strtok(path, ":", &state))
    {
        temp = fullPath;
        fullPath = _strcat(pathToken, "/");
        free(temp);
        temp = fullPath;
        fullPath = _strcat(fullPath, params->arguments[0]);
        free(temp);
        if (access(fullPath, F_OK) == 0)
        {
            free(path);
            free(pathCopy);
            return fullPath;
        }
        free(pathCopy);
        pathCopy = _strdup(pathToken);
    }
    params->status = 127;
    printError(params, "2nd not found\n");
    free(path);
    free(pathCopy);
    free(fullPath);
    return NULL;
}


/**
 * myBuitIns - Get built-in function
 * @params: Pointer to the struct containing command parameters
 * Return: function pointer to inbuilt functions and NULL if not found.
 */
void (*myBuitIns(param *params))(param *)
{
    op_t operations[] = {
        {"exit", EXIT},
        /*{"cd", _cd},*/
        /*{"alias", _alias},*/
		{"env", _printenv},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL},
    };
    op_t *current_operation = operations;

    do {
        if (!_strcmp(params->arguments[0], current_operation->cmd))
            return (current_operation->func);
        current_operation++;
    } while (current_operation->cmd);


    return (NULL);
}