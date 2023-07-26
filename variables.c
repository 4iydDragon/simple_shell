#include "shell.h"
/**
 * checkChainCont - checks if we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the character buffer
 * @d: address of current position in buffer
 * @i: starting position in buffer
 * @len: length of buffer
 *
 * Return: Void
 */
void checkChainCont(info_t *info, char *buf, size_t *d, size_t i, size_t len)
{
	size_t k = *d;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			k = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			k = len;
		}
	}

	*d = k;
}

/**
 * substitute_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int substitute_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
/**
 * isChain - check if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the character buffer
 * @d: an address of current position in buf
 *
 * Return: 1 if it is a chain delimeter, 0 otherwise
 */
int isChain(info_t *info, char *buf, size_t *d)
{
	size_t i = *d;

	if (buf[i] == '|' && buf[i + 1] == '|')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[i] == '&' && buf[i + 1] == '&')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[i] == ';') /* found the end of this command */
	{
		buf[i] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*d = i;
	return (1);
}
/**
 * substitute_string - subs a string with a new one
 * @s1: address of first string
 * @s2: second string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int substitute_string(char **s1, char *s2)
{
	free(*s1);
	*s1 = s2;
	return (1);
}

/**
 * substitute_vars - puts actual values to vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int substitute_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			substitute_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			substitute_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			substitute_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		substitute_string(&info->argv[i], _strdup(""));

	}
	return (0);
}


