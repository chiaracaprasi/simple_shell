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
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @variable: variable name
 * @value: variable value
 * @env: array of enviroment variables
 *
 * Return: 0 for success, -1 for error
 */

char **create_env(char *new_var, char **env, int limit)
{
	int i = 0;
	char **new_env;

	new_env = malloc(sizeof(char *));
	while(i <= limit)
	{
		new_env = realloc(new_env, (sizeof(char *) * (i + 1)));
		new_env[i] = malloc(strlen(env[i]) + 1);
		if (env[i] == NULL)
		{
			printf("malloc fail\n");
			return (NULL);
		}
		new_env[i] = env[i];
		printf("new_env[%d]: %s\n", i, new_env[i]);
		i++;
	}
	printf("new_env[%d]: %s\n", i, new_env[i]);
	if (new_env[i] != NULL)
	{
		printf("inside if statement\n");
		new_env[i] = malloc(sizeof(char*));
		new_env[i] = NULL;
		printf("%s\n", new_env[i + 1]);
	}
	return (new_env);
}


char **_setenv(char *variable, char *value, char **env)
{
	char *new_var, *old_var;
	char **new_env;
	int var_len, i = 0, limit = 0;

	printf("********************\n");
	if (variable == NULL || value == NULL)
	{
		perror("Error! Missing variable name or new value");
		return (NULL);
	}

	var_len = strlen(variable) + strlen(value) + 2;
	new_var = malloc(var_len * sizeof(char));

	if (new_var == NULL)
	{
		perror("Error: malloc failed");
		return (NULL);
	}

	new_var = strcat(new_var, variable);
	new_var = strcat(new_var, "=");
	new_var = strcat(new_var, value);

	while (env[limit] != NULL)
	{
		limit++;
	}

	i = set_getenv(variable, env);
	env[i] = new_var;
	new_env = create_env(new_var, env, limit);

	return (new_env);
}

int _unsetenv(char *variable, char **env)
{
	char *new_var = NULL;
	char *old_var;
	int var_len, i = 0;

	if (variable == NULL)
	{
		perror("Error! Missing variable name or new value");
		return (-1);
	}

	while(env[i] != NULL)
	{
		if ((env_start(variable, env[i])) == 1)
		{
			break;
		}
		i++;
	}

	if (env[i] == NULL)
		printf("Variable doesn't exist\n");

	else
		env[i] = new_var;

	return (0);
}


int main(int argc, char *argv[], char **env)
{
	char *home, *new_home;

	home = getenv("TEST");
	printf("Orginal $TEST is %s\n", home);
	env = _setenv("TEST", "cool_guy", env);
	printf("New test is %s\n", getenv("TEST"));
	env = _setenv("JEFF", "cool_guy", env);
	printf("JEFF is %s\n", getenv("JEFF"));
	_unsetenv("TEST", env);
	printf("New test is %s\n", getenv("TEST"));
	_unsetenv("FRANK", env);

	return (0);
}
