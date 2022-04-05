#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/**
 * path_finder - handles the PATH
 * @cmd: command entered
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */

int path_finder(char *cmd)
{
	char *dir = "/bin/";
	int file_found;
	int len1 = _strlen(dir), len2 = strlen(cmd);
	char *path = malloc((len1 + len2 + 1) * sizeof(char));

	if (path == NULL)
	{
		return (-1);
	}
	strcpy(path, dir);
	path = strcat(path, cmd);

	printf("TEST Path is %s\n", path);

	file_found = access(path, X_OK);
	printf("TEST filefound return is %d\n", file_found);

	if (file_found == -1)
	{
		printf("No such file or directory\n");
		return (-1);
	}
	else
		printf("File found\n");
}

int main(void)
{
	char *test = "ls";
	char *test1 = "frank";
	int result;

	result = path_finder(test);
	printf("Result for test in main is %d\n", result);
	result = path_finder(test1);
	printf("Result for test1 in main is %d\n", result);

	return (0);
}
