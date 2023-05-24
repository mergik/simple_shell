#include "main.h"

/**
 * printError - print error messages to STD_OUT
 * @params: struct containing command to be printed
 * @out: message to be printed
 */
void printError(param *params, char *out)
{
	char buffer[2048] = {0}, *errStart = buffer, *bufPtr = buffer, str[12];

	/* add program name*/
	_strcpy(errStart, params->argv[0]);
	errStart = bufPtr + _strlen(bufPtr);
	/* add a colon */
	_strcpy(errStart, ": ");
	errStart = bufPtr + _strlen(bufPtr);
	/* add line number */
	intToString(params->lineCount, str);
	_strcpy(errStart, str);
	errStart = bufPtr + _strlen(bufPtr);
	/* add a colon */
	_strcpy(errStart, ": ");
	errStart = bufPtr + _strlen(bufPtr);
	/* add the command inputed */
	_strcpy(errStart, params->arguments[0]);
	errStart = bufPtr + _strlen(bufPtr);
	/* add a colon */
	_strcpy(errStart, ": ");
	errStart = bufPtr + _strlen(bufPtr);
	/* add provided error message */
	_strcpy(errStart, out);
	errStart = bufPtr + _strlen(bufPtr);
	/* Print final error message to std out */
	write(STDERR_FILENO, buffer, _strlen(bufPtr));
}

/**
 * intToString - converts an integer to a string
 * @value: the integer value to convert
 * @str: the string buffer to store the result
 */
void intToString(int value, char *str)
{
	char *p = str;
	int digits = 0, tmp;

	if (value < 0)
	{
		*p++ = '-';
		value = -value;
	}
	tmp = value;
	do {
		++digits;
		tmp /= 10;
	} while (tmp);
	p += digits;
	*p-- = '\0';
	do {
		*p-- = '0' + (value % 10);
		value /= 10;
	} while (value);
}

/**
 * _atoi - turn a str into an int
 * @s: string to eval
 * Return: value of the first number in the string
 */
int stringToInt(char *s)
{
    int value, tmp, len, multiplier = 1;

    value = 0;
    tmp = 0;

    len = _strlen(s);
    for (len = len - 1; len >= 0; len--)
    {
        tmp = value;
        value = value + (s[len] - '0') * multiplier;
        if (value < tmp || value > INT_MAX)
            return (-1);
        multiplier *= 10;
    }

    return (value);
}
/**
 * numValidator - check if  the string is a valid number
 * @str: string input
 * Return: 0 success 1 failure
 */
int numValidator(char *str)
{
    while (*str)
    {
        if (*str > '9' || *str < '0')
            return 0;
        str++;
    }
    return (1);
}
