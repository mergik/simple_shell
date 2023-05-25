#include "main.h"

/**
 * strtok - custom strtok function
 * @string: string to be passed
 * @delim: delimiter
 * @state: state
 * Return: next token found in string, NULL if not found
 */
char *_strtok(char *string, char *delim, char **state)
{
    char *ptr, *modifier, *end;
    int quoteFound = 0;

    if (*state)
        ptr = *state;
    else
        ptr = string;
    end = ptr;
    while (*end)
        end++;
    while (*ptr && _isDelim(*ptr, delim))
        ptr++;
    modifier = ptr;
    if (*ptr == '\0')
        return NULL;
    if (*ptr == '\'')
    {
        ptr++;
        modifier = _strchr(ptr, '\'');
        if (!modifier)
        {
            write(1, "no matching quote found!\n", 25);
            exit(-1);
        }
        *modifier = '\0';
        *state = modifier + 1;
        return (_strdup(ptr));
    }
    while (*modifier)
    {
        if (*modifier == '\'')
            quoteFound = 1;
        if (_isDelim(*modifier, delim) && quoteFound == 0)
            break;
        modifier++;
    }
    if (*modifier == '\0')
        *state = modifier;
    else
        *state = modifier + 1;
    *modifier = '\0';
    return (_strdup(ptr));
}

/**
 * _isDelim - check if a character is one of the delimiters
 * @character: character
 * @delim: delimeters
 *
 * Return: 1 if it is a delimiter, 0 otherwise
 */
int _isDelim(char character, char *delim)
{
    while (*delim)
    {
        if (character == *delim)
            return (1);
        delim++;
    }
    return (0);
}
