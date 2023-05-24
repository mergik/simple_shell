#include "main.h"

/**
 * _strcpy - copy a string from source to destination
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
