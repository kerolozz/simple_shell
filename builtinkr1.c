#include "shellkr.h"

/**
 * _myhistory - it displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @inf: Structure containing potential arguments and it used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(inf_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @inf: the parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, on error 1
 */
int unset_alias(inf_t *inf, char *str)
{
	char *m, n;
	int ret;

	m = _strchr(str, '=');
	if (!m)
		return (1);
	n = *m;
	*m = 0;
	ret = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, str, -1)));
	*m = n;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @inf: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, on error 1
 */
int set_alias(inf_t *inf, char *str)
{
	char *m;

	m = _strchr(str, '=');
	if (!m)
		return (1);
	if (!*++m)
		return (unset_alias(inf, str));

	unset_alias(inf, str);
	return (add_node_end(&(inf->alias), str, 0) == NULL);
}

/**
 * print_alias - it prints an alias string
 * @node: alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *m = NULL, *n = NULL;

	if (node)
	{
		m = _strchr(node->str, '=');
		for (n = node->str; n <= m; n++)
		_putchar(*n);
		_putchar('\'');
		_puts(m + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtinkr (man alias)
 * @inf: Structure containing potential arguments and it used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(inf_t *inf)
{
	int i = 0;
	char *m = NULL;
	list_t *no = NULL;

	if (inf->argc == 1)
	{
		no = inf->alias;
		while (no)
		{
			print_alias(no);
			no = no->next;
		}
		return (0);
	}
	for (i = 1; inf->argv[i]; i++)
	{
		m = _strchr(inf->argv[i], '=');
		if (m)
			set_alias(inf, inf->argv[i]);
		else
			print_alias(node_starts_with(inf->alias, inf->argv[i], '='));
	}

	return (0);
}

