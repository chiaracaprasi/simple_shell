#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"

/**
 * exc_cmd_test - run the command
 * @cmd_array: the array of commands to execute and all other flags
 * Description: long description
 *
 * Return: void
 */
void exc_cmd_test(char * const cmd_array[])
{
	if (execve(cmd_array[0], cmd_array, NULL) == -1)
	{
		_puts("error executing system command\n");
	}
}

/**
 * exc_cmd - execute a system command
 * @head: list of tokens to execute.
 * @group: the group of elements to execute.
 * Description: long description
 *
 * Return: 0 upon success
 */
void exc_cmd(token_t **head, int group)
{
	char *argv[100];
	pid_t child_pid;
	int status, argc = 0, i = 0;
	token_t *hold = *head, *fill = *head;

	while (hold->group < group)
		hold = hold->next;

	while (hold->group == group)
	{
		argc++;
		if (hold->next == NULL)
			break;
		hold = hold->next;
	}
	while (i < argc)
	{
		if (_strcmp(fill->token, ";") == 0)
			break;
		argv[i] = fill->token;
		i++;
		fill = fill->next;
	}
	argv[i] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}

	if (child_pid == 0)
	{
		exc_cmd_test(argv);
	}
	wait(&status);

	return;
}
