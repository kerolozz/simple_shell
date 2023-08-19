#include "shell.h"

/**
 * interactive - it return true if shell is interactive mode
 * @info: address of struct
 * Return: if interactive mode return 1, otherwise return 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - it checks if character is delimeter
 * @r: the character get to check
 * @delim: the delimeter strings
 * Return: if true return 1, 0 if false
 */
int is_delim(char r, char *delim)
{
	while (*delim)
		if (*delim++ == r)
			return (1);
	return (0);
}

/**
 * _isalpha - it checks for alphabetic char
 * @k: char to input
 * Return: if c is alphabetic return 1, 0 otherwise
 */

int _isalpha(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoikr - it converts a str to an int
 * @r: the str to be converted
 * Return: if no numbers in string return 0, converted number otherwise
 */

int _atoikr(char *r)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; r[i] != '\0' && flag != 2; i++)
	{
		if (r[i] == '-')
			sign *= -1;

		if (r[i] >= '0' && r[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (r[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
