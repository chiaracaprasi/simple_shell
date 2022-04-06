#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * path_checker - checks in the string starts with /bin/
 * @dir: the dir to check
 * @cmd: the cmd file to try to find
 * Description: locates if command entered exists in the path directory
 *
 * Return: pointer to file if exists or NULL if no file exists.
 */
char *path_checker(char *dir, char *cmd)
{
	char *path_con = NULL;
	int newsize = (_strlen(dir) + _strlen(cmd) + 2), file_found;

	path_con = malloc(newsize * sizeof(char));
	if (path_con == NULL)
		return (NULL);

	path_con = _strcat(path_con, dir);
	path_con = _strcat(path_con, "/");
	path_con = _strcat(path_con, cmd);
	file_found = access(path_con, X_OK);
	if (file_found == -1)
	{
		free(path_con);
		return (NULL);
	}

	return (path_con);
}

/**
 * find_real_path - finds the correct path value
 * @dir: the dir to check
 * @cmd: the cmd file to try to find
 * Description: locates if command entered exists in the path directory
 *
 * Return: pointer to file if exists or NULL if no file exists.
 */
char *find_real_path(char *dir, char *cmd)
{
	char *path[20];
	char *path_list = strtok(dir, ":");
	char *path_list_cpy = NULL;
	int len2 = _strlen(cmd), newsize;
	int file_found, i = 0, k = 0;

	while (path_list != NULL)
	{
		path_list_cpy = _strdup(path_list);
		path_list_cpy = path_checker(path_list_cpy, cmd);
		if (path_list_cpy != NULL)
			break;
		path_list = strtok(NULL, ":");
	}
	return (path_list_cpy);
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

	dir =  _getenv("PATH", env);
	if (dir == NULL)
		dir = _strdup("/bin/");
	len1 = strlen(dir);

	if (cmd[0] == '/')
	{
			return (cmd);
	}
	else
	{
		path = find_real_path(dir, cmd);
		if (path == NULL)
			return (cmd);
	}

	return (path);
}
