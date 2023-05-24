#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: 0 if strings are identical, negative value if s1 is less than s2,
 *         positive value if s1 is greater than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
