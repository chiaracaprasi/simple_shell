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
	int newsize = (_strlen(dir) + _strlen(cmd) + 2), file_found = 0;
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
		path_con = NULL;
		return (dir);
	}

	return (path_con);
}

/**
 * get_path - breaks the path name into individual sections
 * @search: the entire path name
 * @nums: number of path names we have already searched
 *
 * Return: pointer
 **/

char *get_path(char *search, int nums)
{
	int i = 0, k = 0, l = 0;

	if (k <= nums)
	{
		while (search[i] != '\0' || k != nums)
		{
			if (search[i] == ':' || search[i] == '\0')
			{
				if (k == nums)
				{
					search[i] = '\0';
					break;
				}
				l = i + 1;
				k++;
			}
			i++;
		}
	}

	i++;
	return (search + l);
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
	char *path_list_cpy = _strdup(dir);
	char *address_of_list = path_list_cpy;
	int i = 0, k = 0, size1, size2;

	while (k < 25)
	{
		path_list_cpy = get_path(path_list_cpy, k);
		if (path_list_cpy[0] == '\0')
			break;
		k++;
		size1 = _strlen(path_list_cpy);
		path_list_cpy = path_checker(path_list_cpy, cmd);
		size2 = _strlen(path_list_cpy);
		if (size1 != size2)
			break;
		i++;
	}

	if (path_list_cpy[0] != '\0')
	{
		return (path_list_cpy);
	}

	free(address_of_list);
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
	char *path = NULL;
	int flag = 0;

	if (cmd[0] == '/')
	{
		return (cmd);
	}
	dir =  _getenv("PATH", env);
	if (dir == NULL)
	{
		dir = _strdup("/bin/");
		flag = 1;
	}
	path = find_real_path(dir, cmd);
	if (path[0] != '/')
	{
		if (flag == 1)
		{
			free(dir);
			dir = NULL;
		}
		return (cmd);
	} else
		return (path);
}
