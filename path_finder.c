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
	int i = 0;

	path_con = malloc(newsize * sizeof(char));
	if (path_con == NULL)
		return (NULL);

	while (dir[i] != '\0')
	{
		if (dir[i] == ':')
		{
			dir[i] = '\0';
			break;
		}
		i++;
	}

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
 * get_path - finds the path
 * @path: path name
 * @nums: number
 *
 * Return: pointer
 **/

char *get_path(char *path, int nums)
{
	int i = 0, k = 0;
	char *search = _strdup(path);

	if (k <= nums)
	{
		while (search[i] != '\0')
		{
			if (search[i] == ':' || search[i] == '\0')
			{
				if (k == nums)
				{
					search[i] = '\0';
					break;
				}
				k++;
			}
			i++;
		}
	}
	/*moves past newly set null byte */
	i++;

	return (search + i);
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
	char *path_list_cpy = NULL;
	int len2 = _strlen(cmd), newsize;
	int file_found, i = 0, k = 0;

	while (k < 25)
	{
		path_list_cpy = get_path(dir, k);
		if (path_list_cpy[0] == '\0')
			break;
		k++;
		path_list_cpy = path_checker(path_list_cpy, cmd);
		if (path_list_cpy != NULL)
			break;
		i++;
	}
	i = 0;

	if (path_list_cpy[0] != '\0')
	{
		return (path_list_cpy);
	}

	return (cmd);
}
/**
 * path_finder - handles the PATH
 * @cmd: command entered
 * @env: envoriomental variables
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
	}
	if (path[0] != '/')
	{
/*		free(dir);*/
		return (cmd);
	} else
		return (path);
}
