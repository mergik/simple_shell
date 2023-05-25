#include "main.h"

/**
 * _strcmp - compares two strings
 * @string1: string 1
 * @string2: string 2
 * Return: int less than, equal to, or greater than 0 if string1 is, respectively
 * less than, equal to, or greater than string2
 */
int _strcmp(char *string1, char *string2)
{
	int result = 0;

	do {
		result = *string1 - *string2;
		if (*string1 == 0 || *string2 == 0)
			break;
		string1++;
		string2++;
	} while (result == 0);

	return (result);
}