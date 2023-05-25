#include "main.h"

/**
 * _strdup - duplicate a string
 * @str: string to be duplicated
 * Return: pointer to newly-allocated space in memory containing the
 *         duplicated string, or NULL if str is NULL or if malloc fails.
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t i, length;

	if (str == NULL)
		return (NULL);

	length = _strlen(str);

	new_str = malloc(sizeof(char) * (length + 1));

	if (new_str == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
		new_str[i] = str[i];

	new_str[i] = '\0';

	return (new_str);
}
