#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * set_getenv - get enviroment var list for setenv function
 * @name: variable name
 * @value: variable value
 * @env: array containing environment variables.
 *
 * Return: pointer to var in list
 */

char *set_getenv(char *name, char **env)
{
	char *var = NULL;
	int i = 0;
	while(env[i])
	{
		if ((env_start(name, env[i])) == 1)
		{
			var = env[i];
			break;
		}
		i++;
	}
	return (var);
}


/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @variable: variable name
 * @value: variable value
 * @env: array of enviroment variables
 *
 * Return: void
 */
void _setenv(char *variable, char *value, char **env)
{
	char *new_var, char **old_var;
	int var_len, i;

	if (name == NULL || value == NULL || env == NULL)
	{
		perror("Error! Missing variable name or new value");
		return (-1);
	}

	var_len = _strlen(var) + _strlen(value) + 2;
	new_var = malloc(var_len * sizeof(char));

	if (new_var == NULL)
	{
		perror("Error: malloc failed");
		return (NULL);
	}
	new_var = _strcat(new_var, variable);
	new_var = _strcat(new_var, "=");

	new_var = _strcat(new_var, value);

	*old_var = _set_getenv(variable, env);

	if (*old_var != NULL)
		*old_var = new_var;

	if (old_var == NULL)
	{
		i = 0;
		while (env[i])
			i++;
		*old_var = env[i];
		*old_var = new_var;
	}
}
