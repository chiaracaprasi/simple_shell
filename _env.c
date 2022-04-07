#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * env_start - looks for start of the env list.
 * @path: the string to look at.
 * @var: the env variable to look against.
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */
int env_start(char *path, char *var)
{
	int i = 0;

	while (var[i] == path[i])
	{
		i++;
	}

	if (i == strlen(path))
		return (1);

	return (0);
}

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

	return (i);
}


/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @variable: variable name
 * @value: variable value
 * @env: array of enviroment variables
 *
 * Return: 0 for success, -1 for error
 */
int _setenv(char *variable, char *value, char **env)
{
	char *new_var;
	char *old_var;
	int var_len, i;

	if (variable == NULL || value == NULL)
	{
		perror("Error! Missing variable name or new value");
		return (-1);
	}

	var_len = strlen(variable) + strlen(value) + 2;
	new_var = malloc(var_len * sizeof(char));

	if (new_var == NULL)
	{
		perror("Error: malloc failed");
		return (-1);
	}

	new_var = strcat(new_var, variable);
	new_var = strcat(new_var, "=");
	new_var = strcat(new_var, value);

	i = set_getenv(variable, env);

	if (old_var != NULL)
	{
		env[i] = new_var;
	}
	if (old_var == NULL)
	{
		i = 0;
		while (env[i] != NULL)
			i++;
		old_var = env[i];
		old_var = new_var;
	}

	return (0);
}

int main(int argc, char *argv[], char **env)
{
	char *home, *new_home;

	home = getenv("TEST");
	printf("Orginal $TEST is %s\n", home);

	_setenv("TEST", "/test", env);
	printf("New test is %s\n", getenv("TEST"));

	return (0);
}
