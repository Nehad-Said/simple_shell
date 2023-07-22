#include "shell.h"

/**
 * _strdup - It is duplicating the string content
 * @str: The string the be duplicated.
 * Return: A pointer pointing to the duplicate string.
 */
char *_strdup(char *str)
{
	int length;
	char *b;

	if (str == NULL)
	{
		return (NULL);
	}
	length = _strlen(str);

	b = malloc(sizeof(char) * (length + 1));
	if (!b)
	{
		return (NULL);
	}
	strcpy(b, str);
	return (b);
}
/**
 * _strcpy - Coping the content of a pointer to another one
 * @src: The string to copy from.
 * @dest: The string to paste to.
 * Return: A pointer pointing to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == NULL)
	{
		return (dest);
	}
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
/**
 * _builtin - Checking for builtin commands.
 * @argv: Containing possible arguements.
 * @command: Input from user.
 * Return: -1 if exit and 0 if env.
 */
int _builtin(char **argv, char *command)
{
	int k;

	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
		{
			k = _atoi(argv[1]);
			free(command);
			exit(k);
		}
		else
		{
			free(command);
			exit(0);
		}
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		_printenv();
		return (1);
	}
	return (0);
}
/**
 * _strcat - Concatenating a string to the end of another.
 * @src: The string to be concatenated.
 * @dest: The string to concatenate to.
 * Return: A pointer pointing to the destination string
 */
char *_strcat(char *dest, char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}
/**
 * _strtok - Tokenizing a string.
 * @str: The string to be tokenized.
 * @del: The delimeter to watch out for.
 * Return: The tokenized string.
 */
char *_strtok(char *str, const char *del)
{
	static char *n;

	char *s = NULL;

	if (str != NULL)
	{
		n = str;
	}
	if (*n == '\0')
	{
		return (NULL);
	}
	while (*n != '\0' && *n == *del)
	{
		n++;
	}
	if (*n == '\0')
	{
		return (NULL);
	}
	s = n;
	while (*n != '\0')
	{
		if (*n == *del)
		{
			n++;
			if (*n == *del)
			{
				*(n - 1) = '\0';
			}
			while (*n == *del)
			{
				n++;
			}
			*(n - 1) = '\0';
			return (s);
		}
		n++;
	}
	return (s);
}
