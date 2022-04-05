#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * cd_built- handles cd builtin, limited, does not UPDATE PWD.
 * :
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */
void cd_built(char *dir, char **env)
{
	char pwd[100];
	char *curr_dir;
	int error;

	if (dir == NULL)
	{
		curr_dir = malloc(100);
		if (curr_dir == NULL)
			return;
		if (!getenv("HOME"))
			error = chdir("/home/");
		else
			error = chdir(getenv("HOME"));
		if (error == -1)
		{
			return;
		}
		getcwd(pwd, 100);
		puts(pwd);
		return;
	}

	error = chdir(dir);
	if (error == -1)
	{
		puts(dir);
		puts(": directory not found\n");
		return;
	}

	getcwd(pwd, 100);
	puts(pwd);
}
