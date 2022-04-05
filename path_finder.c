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
	char *path = strcat(dir, cmd);

	printf("TEST Path is %s", path);

	file_found = access(path, X_OK);
	printf("TEST filefound return is %d", file_found);

	if (file_found == -1)
	{
		printf("No such file or directory");
		return (-1);
	}
	else
		printf("File found");
}

int main(void)
{
	char *test = "ls";
/*	char *test1 = "frank"; */
	int result;

	result = path_finder(test);
	printf("%d\n", result);
	result = path_finder(test);
	printf("%d\n", result);

	return (0);
}
