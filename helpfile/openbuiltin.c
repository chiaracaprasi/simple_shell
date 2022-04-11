#include "main.h"
#define ERROR "C_SHELL: help: no help topics match your input"
/**
 * help_open - reads and writes files
 * @fd: the file descriptor
 * Return: 0 (success)
 */

int help_open(int fd)
{
	char *buffer;
	int bytread;
	int bytwrite;

	buffer = malloc(1024);
	bytread = read(fd, buffer, 1024);
	bytwrite = write(STDOUT_FILENO, buffer, bytread);

	if (bytwrite < 0)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(fd);
	return (0);
}
/**
 * output_help - sends help page to standard output
 * Return: 0 (success)
 */

int output_help(void)
{
	int fd;
	char cmd[100];

	if (strcmp(cmd, "cd") == 0)
	{
		fd = open("cdhelp.txt", O_RDONLY);
		help_open(fd);
	}

	else if (strcmp(cmd, "env") == 0)
	{
		fd = open("envhelp.txt.", O_RDONLY);
		help_open(fd);
	}
	else if (strcmp(cmd, "help") == 0)
	{
		fd = open("helphelp.txt", O_RDONLY);
		help_open(fd);
	}
	else if (strcmp(cmd, "exit") == 0)
	{
		fd = open("exithelp.txt", O_RDONLY);
		help_open(fd);
	}
	else
		_puts(ERROR);
	return (0);
}
