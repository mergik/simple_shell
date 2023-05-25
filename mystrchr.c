#include "main.h"

/**
 * _strchr - searches for the first occurrence of the character provided
 * @str: string to be scanned
 * @character: character to be searched
 * Return: pointer to the first occurrence of the character or 0
 */
char *_strchr(char *str, char character)
{
	int index = 0;

	do {
		if (str[index] == character)
			return (&str[index]);
		index++;
	} while (str[index] != '\0');
	if (character == '\0')
		return (&str[index]);

	return (0);
}
