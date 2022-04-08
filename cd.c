#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * set_getenv - get enviroment var list for setenv function
 * @name: variable name
 * @value: variable value
 * @env: array containing environment variables.
 *
 * Return: pointer to var in list
 */

int set_getenv(char *name, char **env)
{
	int i = 0;

	while(env[i] != NULL)
	{
		if ((env_start(name, env[i])) == 1)
		{
			break;
		}
		i++;
	}

	return (i);
}
/**
 * _setenv - handles setting an env variable
 *
 * return: void
 */
void _setenv(char *variable, char *value, char **env)
{
	char *new_var, *old_var;
	int var_len, i = 0, limit = 0;

	if (variable == NULL || value == NULL)
	{
		perror("Error! Missing variable name or new value");
		return;
	}

	var_len = _strlen(variable) + _strlen(value) + 2;
	new_var = malloc(var_len * sizeof(char));

	if (new_var == NULL)
	{
		perror("Error: malloc failed");
		return;
	}

	new_var = _strcat(new_var, variable);
	new_var = _strcat(new_var, "=");
	new_var = _strcat(new_var, value);

	i = set_getenv(variable, env);
	env[i] = new_var;
}

/**
 * cd_built- handles cd builtin, limited, does not UPDATE PWD.
 * :
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */
void cd_built(char *dir, char **env)
{
	char pwd[100];
	char *curr_dir;
	int error;

	if (dir == NULL)
	{
		curr_dir = malloc(100);
		if (curr_dir == NULL)
			return;
		if (!_getenv("HOME", env))
			error = chdir("/home/");
		else
			error = chdir(_getenv("HOME", env));
		if (error == -1)
		{
			return;
		}
		getcwd(pwd, 100);
		_setenv("PWD", pwd, env);
		_puts(pwd);
		_puts("\n");
		return;
	}

	if (dir[0] == '-')
	{
		curr_dir = malloc(100);
		if (curr_dir == NULL)
			return;
		if (!_getenv("PWD", env))
			error = chdir("/home/");
		else
			error = chdir(_getenv("PWD", env));
		if (error == -1)
		{
			return;
		}
		getcwd(pwd, 100);
		_setenv("PWD", pwd, env);
		_puts(pwd);
		_puts("\n");
		return;
	}

	error = chdir(dir);
	if (error == -1)
	{
		_puts(dir);
		_puts(": directory not found\n");
		return;
	}

	getcwd(pwd, 100);
	_setenv("PWD", pwd, env);
	_puts(pwd);
	_puts("\n");
}
