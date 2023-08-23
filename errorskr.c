#include "shellkr.h"

/**
 * _eputs - it prints input string
 * @str: it is the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar - it writes character r to stderr
 * @r: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char r)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (r == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buf, k);
		k = 0;
	}
	if (r != BUF_FLUSH)
		buf[k++] = r;
	return (1);
}

/**
 * _putfd - writes the character r to given fd
 * @r: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, returned -1, and errno is set appropriately.
 */
int _putfd(char r, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (r == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (r != BUF_FLUSH)
		buf[k++] = r;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}

