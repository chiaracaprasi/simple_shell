#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"

/**
 * exc_built - execute a builtin function
 * @head: list of tokens to execute.
 * @group: the group of elements to execute.
 * @env: enviroment variables
 * Description: long description
 *
 * Return: 0 upon success
 */
void exc_built(token_t **head, int group, char **env, char *buffer)
{
	char *argv[100];
	token_t *hold = *head, *use = *head;
	int builtNum, argc = 0, i = 0, funcNum;

	while (hold->group < group)
	{
		hold = hold->next;
		use = use->next;
	}

	while (hold->group == group)
	{
		argc++;
		if (hold->next == NULL)
			break;
		hold = hold->next;
	}
	while (i < argc)
	{
		if (_strcmp(use->token, ";") == 0)
			break;
		argv[i] = use->token;
		i++;
		use = use->next;
	}
	argv[i] = NULL;

	builtNum = is_builtin(argv[0]);

	if (builtNum == 0)
	{
		funcNum = 0;
		if (argv[1] != NULL)
			funcNum = _atoi(argv[1]);

		exit_built(head, funcNum, buffer);
	}
	if (builtNum == 1)
	{
		if (argc <= 2)
			cd_built(argv[1], env);
		else
			_puts("shell: cd: too many arguments\n");
	}
	if (builtNum == 2)
	{
		env_built(env);
	}
}
