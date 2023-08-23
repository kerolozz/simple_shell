#include "shellkr.h"

/**
 * _myenv - it prints current environment
 * @inf: Structure containing potential arguments and it used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(inf_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _getenv - it gets value of environ variable
 * @inf: Structure containing potential arguments and it used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(inf_t *inf, const char *name)
{
	list_t *node = inf->env;
	char *m;

	while (node)
	{
		m = starts_with(node->str, name);
		if (m && *m)
			return (m);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - it Initialize new environment variable,
 *             or modify an existing one
 * @inf: Structure containing potential arguments and it used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(inf_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - it Removes environment variable
 * @inf: structure containing potential arguments and it used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(inf_t *inf)
{
	int r;

	if (inf->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (r = 1; r <= inf->argc; r++)
		_unsetenv(inf, inf->argv[r]);

	return (0);
}

/**
 * populate_env_list - it populates env linked list
 * @inf: structure containing potential arguments and it used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(inf_t *inf)
{
	list_t *node = NULL;
	size_t r;

	for (r = 0; environ[r]; r++)
		add_node_end(&node, environ[r], 0);
	inf->env = node;
	return (0);
}

