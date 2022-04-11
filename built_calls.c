#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"

/**
 * bIn_pick - picks the builtin to use
 * @av: list of arguments
 * @bN: the built number to execute
 * @h: list of tokens to execute.
 * @env: enviroment variables
 * @b: original buffer to free.
 * @ac: argument count.
 * Description: long description
 * Return: 0 upon success
 */
void bIn_pick(char *av[100], int ac, int bN, token_t **h, char **env, char *b)
{
	int funcNum;

	if (bN == 0)
	{
		funcNum = 0;
		if (av[1] != NULL)
			funcNum = _atoi(av[1]);

		exit_built(h, funcNum, b);
	}
	if (bN == 1)
	{
		if (ac <= 2)
			cd_built(av[1], env);
		else
			_puts("shell: cd: too many arguments\n");
	}
	if (bN == 2)
	{
		env_built(env);
	}
	if (bN == 3)
	{
		if (ac <= 2)
			output_help(av[1]);
		else
			_puts("shell: help: too many arguments\n");
	}
}

/**
 * exc_built - execute a builtin function
 * @head: list of tokens to execute.
 * @group: the group of elements to execute.
 * @env: enviroment variables
 * @buffer: original buffer to free.
 * Description: long description
 *
 * Return: 0 upon success
 */
void exc_built(token_t **head, int group, char **env, char *buffer)
{
	char *argv[100];
	token_t *hold = *head, *use = *head;
	int builtNum, argc = 0, i = 0;

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
	bIn_pick(argv, argc, builtNum, head, env, buffer);
	
}
