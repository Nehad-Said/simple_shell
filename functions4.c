#include "shell.h"

/**
 *  ignore_stderr-Ignore stderr output
 *  Return: Void.
 */
void ignore_stderr(void)
{
	int dvnull_fd;
	int stder_fd;
	int new_stder_fd;

	dvnull_fd = open("/dev/null", O_WRONLY);
	if (dvnull_fd == -1)
	{
		return;
	}
	stder_fd = 2;
	close(stder_fd);
	new_stder_fd = open("/dev/null", O_WRONLY);

	if (new_stder_fd == -1)
	{
		close(dvnull_fd);
		return;
	}
	if (new_stder_fd != stder_fd)
	{
		if (new_stder_fd != dvnull_fd)
		{
			close(new_stder_fd);
		}
	}
	close(dvnull_fd);
}
/**
 *  _atoi - Converting ascii to integer
 *  @str: The string to be converted.
 *  Return: The converted string.
 */
int _atoi(char *str)
{
	int l = 0;
	int p = 0;
	int j = 0;

	l = _strlen(str);
	l--;
	while (l >= 0)
	{
		p = p + ((str[l] - '0') * j);
		j = j * 10;
		l--;
	}
	return (p);
}
