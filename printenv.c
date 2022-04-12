#include <unistd.h>
#include "main.h"

/**
 * env_built - prints env variables
 * @env: the list of env variables
 *
 * return: void
 */
int env_built(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}

	return (0);
}
