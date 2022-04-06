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

char *find_real_path(char *dir, char *cmd)
{
	char *path[20];
	char *path_list = strtok(dir, ":");
	char *path_list_cpy = NULL;
	int len2 = _strlen(cmd), newsize;
	int file_found, i = 0, k = 0;

	while (path_list != NULL)
	{
		newsize = (_strlen(path_list) + len2 + 2) * sizeof(char);
		path_list_cpy = malloc(newsize);
		path_list_cpy = _strcat(path_list_cpy, path_list);
		path_list_cpy = _strcat(path_list_cpy, "/");
		path_list_cpy = _strcat(path_list_cpy, cmd);
		path[i] = path_list_cpy;
		i++;
		path_list = strtok(NULL, ":");
	}
	path[i] == NULL;
	i = 0;
	while (path[i] != NULL)
	{
		printf("path[i] = %s\n", path[i]);
		i++;
	}
	while (path[i] != NULL)
	{
		file_found = access(path[i], X_OK);
		if (file_found == -1)
		{
			printf("file not found\n");
			i++;
		}
		if (file_found >= 0)
		{
			printf("path returned: %s\n", path[i]);
			return (path[i]);
		}
	}

	return (NULL);
}
/**
 * path_finder - handles the PATH
 * @cmd: command entered
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */
char *path_finder(char *cmd, char **env)
{
	char *dir = NULL;
	int file_found;
	int len1, len2 = strlen(cmd);
	char *path = NULL;

	if ((_strcmp(cmd, "env")) == 0)
		return (cmd);
	dir =  _getenv("PATH", env);
	if (dir == NULL)
		dir = _strdup("/bin/");
	len1 = strlen(dir);

	if ((path_start(cmd)) == 1)
	{
		path = malloc((len2 + 1) * sizeof(char));
		if (path == NULL)
		{
			printf("return NULL\n");
			return NULL;
		}
		path = strcat(path, cmd);
		printf("line 96: path = %s\n", path);
	}
	else
	{
		path = find_real_path(dir, cmd);
		if (path == NULL)
			return (cmd);
	}

	file_found = access(path, X_OK);

	if (file_found == -1)
	{
		free(path);
		return (cmd);
	}

	printf("final return of path: %s\n", path);
	return (path);
}
