#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * test_path - tests if the path to a file exists or not
 * @full_path: path to the file
 *
 * Return: 1- can open and close file. 0 - can't find file
 * -1 - opened filebut can't close it.
 */
int test_path(char *full_path)
{
	int error = 0;

	error = open(full_path, O_RDONLY);
	if (error < 0)
		return (0);
	if (close(error) < 0)
		return (-1);
	return (1);
}

/**
 * free_path - frees the list of path dirs
 * @path: the list of path dirs to free
 *
 * Return: always void.
 */

void free_path(char **path)
{
	int i = 0;

	if (path == NULL)
		return;
	while (path[i] != NULL)
	{
		free(path[i]);
		i++;
	}
	free(path);
}

/**
 * get_path - breaks the path name into individual sections and tests
 * @search: the file name to search through the path for
 * @env: the list of enviro varaibles
 *
 * Return: pointer
 */
char *get_path(char *search, char **env)
{
	char **paths = NULL;
	char *fullPathList = NULL;
	char *retVal = NULL;

	if (search == NULL || env == NULL)
		return (NULL);

	fullPathList = _getenv("PATH", env);

	paths = path_seperator(fullPathList, ":");

	if (paths == NULL)
	{
		if (test_path(search))
			return (search);
		return (NULL);
	}
	retVal = path_checker(search, paths);
	free_path(paths);
	return (retVal);
}

/**
 * path_checker - gets the correct path from a list of tokenized dirs
 * @dir: dir to check
 * @cmd: the cmd to try to find
 *
 * Return: pointer to file if exists or NULL if no file exists
 */
char *path_checker(char *cmd, char **dir)
{
	char *new_path = NULL;
	int fname_len = 0, cur_path_len = 0, new_path_len = 0;
	int i = 0, new_path_i = 0, cmd_i = 0, path_i = 0;
	int is_file = 0;

	fname_len = _strlen(cmd);
	while (dir[i])
	{
		cur_path_len = _strlen(dir[i]);
		new_path_len = cur_path_len + fname_len + 1;
		new_path = malloc(sizeof(char) * new_path_len + 1);
		if (new_path == NULL)
			return (NULL);
		new_path_i = path_i = cmd_i = 0;
		while (new_path_i < new_path_len)
		{
			if (new_path_i < cur_path_len)
				new_path[new_path_i] = dir[i][path_i++];
			else if (new_path_i == cur_path_len)
				new_path[new_path_i] = '/';
			else
				new_path[new_path_i] = cmd[cmd_i++];
			new_path_i++;
		}
		new_path[new_path_i] = '\0';
		is_file = test_path(new_path);
		if (is_file == 1)
			return (new_path);
		else if (is_file < 0)
		{
			free(new_path);
			return (NULL);
		}
		free(new_path);
		i++;
	}
	if (test_path(cmd))
		return (cmd);
	return (cmd);
}
