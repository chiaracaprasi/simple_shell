#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * path_start - checks in the string starts with /bin/
 * @path: the string to check.
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */
int path_start(char *path)
{
	char *check = "/bin/";
	int i = 0;

	while (check[i] == path[i])
	{
		i++;
	}

	if (i == 5)
		return (1);

	return (0);
}

/**
 * path_finder - handles the PATH
 * @cmd: command entered
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */
char *path_finder(char *cmd)
{
	char *dir = "/bin/";
	int file_found;
	int len1 = _strlen(dir), len2 = strlen(cmd);
	char *path = NULL;

	if ((path_start(cmd)) == 0)
	{
		path = malloc((len1 + len2 + 1) * sizeof(char));
		if (path == NULL)
		{
			return NULL;
		}
		strcpy(path, dir);
		path = strcat(path, cmd);
	}
	else
	{
		path = malloc((len2 + 1) * sizeof(char));
		if (path == NULL)
		{
			return NULL;
		}
		strcpy(path, cmd);
	}

	file_found = access(path, X_OK);

	if (file_found == -1)
	{
		free(path);
		return (cmd);
	}

	return (path);
}
