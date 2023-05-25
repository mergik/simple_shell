#include "main.h"

/**
 * _strcat - concatenate two strings
 * @string1: string to which source string will be appended
 * @string2: string to be appended
 *
 * Return: pointer to destination string or NULL
 */
char *_strcat(char *string1, char *string2)
{
	char *ptr;
	int i = 0, j = 0, x = 0;

	if (string1 == NULL)
	{
		string1 = "";
	}
	if (string2 == NULL)
	{
		string2 = "";
	}
	while (string1[i] != '\0')
	{
		i++;
	}
	while (string2[j] != '\0')
	{
		j++;
	}
	ptr = malloc((i * sizeof(char)) + (j * sizeof(char)) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; string1[i] != '\0'; i++)
	{
		ptr[i] = string1[i];
		x++;
	}
	for (j = 0; string2[j] != '\0'; j++)
	{
		ptr[x] = string2[j];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}
