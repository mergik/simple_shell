#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: string to which source string will be appended
 * @src: string to be appended
 *
 * Return: pointer to destination string
 */
char *_strcat(char *dest, const char *src)
{
	size_t i, j;

	i = _strlen(dest);

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

	return (dest);
}
