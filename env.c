#include "shell.h"

/**
 * _customsetenv - Initialize a new environment variable,
 *             or modify an existing one by info-name&value
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototypes.
 *  Return: Always 0
 */
int _customsetenv(info_t *info)
{
	if (info->argc != 3)
	{
		custom_stderr("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _customunsetenv - Removes an environment variable by name
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototypes.
 *  Return: Always 0
 */
int _customunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		custom_stderr("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}
/**
 * _env - prints the current environment in the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}


/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * _getenv - gets the value of an environ variable given name
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
