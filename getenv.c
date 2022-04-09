#include <stdlib.h>
#include "main.h"

/**
 * env_val - finds the actual variabl (words after = sign)
 * to the character beyond the equal sign.
 *
 * @ret_env: pointer to the pointer to path token
 *
 * Return: always void.
 */
void env_val(char **ret_env)
{
	char *token = NULL;

	if (ret_env == NULL)
		return;
	token = *ret_env;
	while (*token != '=')
		token++;
	token++; /* set to first character after = sign */
	*ret_env = token;
}

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

	if (i == _strlen(path))
		return (1);

	return (0);
}

/**
 * _getenv - finds the enviro variable sent to this function
 * @env: the list of env variables
 * @name: the variable to look for
 * Return: pointer to variable or NULL if no match.
 */
char *_getenv(char *name, char **env)
{
	char *var = NULL;
	int i = 0;

	while (env[i])
	{
		if ((env_start(name, env[i])) == 1)
		{
			var = env[i];
			break;
		}
		i++;
	}

	if (var != NULL)
		env_val(&var);

	return (var);
}
