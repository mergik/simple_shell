#include "main.h"

/**
 * _strcpy - copies a string to another memory address
 * @dest: pointer to the destination address
 * @src: pointer to the source string
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}
