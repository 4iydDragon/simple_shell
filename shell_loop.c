#include "shell.h"

/**
 * is_builtin - finds a builtin command in builtin table
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int is_builtin(info_t *info)
{
	int i, result = -1;
	builtin_table builtintbl[] = {
		{"exit", _customexit},
		{"env", _env},
		{"history", _history},
		{"setenv", _customsetenv},
		{"unsetenv", _customunsetenv},
		{"cd", _cd},
		{"alias", _alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			result = builtintbl[i].func(info);
			break;
		}
	return (result);
}

/**
 * check_cmd - finds a command in the PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void check_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((_interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_executable(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "command not found\n");
		}
	}
}
/**
 * hsh - main while shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main func
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int result = 0;

	while (r != -1 && result != -2)
	{
		clear_info(info);
		if (_interactive(info))
			prompt();
		_putchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			result = is_builtin(info);
			if (result == -1)
				check_cmd(info);
		}
		else if (_interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!_interactive(info) && info->status)
		exit(info->status);
	if (result == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (result);
}
