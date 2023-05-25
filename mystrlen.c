#include "main.h"

/**
 * _strlen - calculate the length of a string
 * @str: string to be measured
 * Return: length of the string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}
