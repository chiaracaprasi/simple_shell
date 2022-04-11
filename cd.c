#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * find_env_var - get enviroment var list for setenv function
 * @name: variable name
 * @env: array containing environment variables.
 *
 * Return: pointer to var in list
 */

int find_env_var(char *name, char **env)
{
	int i = 0;

	while (env[i] != NULL)
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
 * set_env_var - handles setting an env variable
 * @variable: variablename
 * @value: variable value
 * @env: enviromental variable
 *
 * return: void
 */
void set_env_var(char *variable, char *value, char **env)
{
	char *new_var;
	int var_len, i = 0;

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

	i = find_env_var(variable, env);
	env[i] = new_var;
}

/**
 * set_pwd - sets the PWD variable
 * @env: the list of env variables to edit
 *
 * return: void
 */
void set_pwd(char **env)
{
	 char pwd[100];

	 getcwd(pwd, 100);
	 set_env_var("PWD", pwd, env);
	 _puts(pwd);
	 _puts("\n");
}

/**
 * handle_home - handles what to do if no input is passesd
 * @env: the list of env variables to edit
 *
 * return: void
 */
void handle_home(char **env)
{
	char pwd[100];
	int error;

	getcwd(pwd, 100);
	set_env_var("OLDPWD", pwd, env);
	if (!_getenv("HOME", env))
		error = chdir("/HOME/");
	else
		error = chdir(_getenv("HOME", env));
	if (error == -1)
		return;
	set_pwd(env);
}

/**
 * cd_built- handles cd builtin, limited, does not UPDATE PWD.
 * @dir: directory name
 * @env: enviromental variable
 *
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */
void cd_built(char *dir, char **env)
{
	char pwd[100];
	int error;

	if (dir == NULL)
	{
		handle_home(env);
		return;
	}

	if (dir[0] == '-')
	{
		getcwd(pwd, 100);
		if (!_getenv("OLDPWD", env))
		{
			_puts("error, OLDPWD not set\n");
			return;
		}
		else
			error = chdir(_getenv("OLDPWD", env));
		if (error == -1)
			return;
		set_env_var("OLDPWD", pwd, env);
		set_pwd(env);

		return;
	}

	error = chdir(dir);
	if (error == -1)
	{
		_puts(dir);
		_puts(": directory not found\n");
		return;
	}

	set_pwd(env);
}
