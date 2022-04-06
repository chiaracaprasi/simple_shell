#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"

/**
 * exc_built - execute a builtin function
 * @head: list of tokens to execute.
 * @group: the group of elements to execute.
 * Description: long description
 *
 * Return: 0 upon success
 */
void exc_built(token_t **head, int group, char **env)
{
	char *argv[100];
	token_t *hold = *head;
	int builtNum, argc = 0, i = 0, funcNum;

	while (hold->group < group)
	{
		hold = hold->next;
		*head = (*head)->next;
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
		if (_strcmp((*head)->token, ";") == 0)
			break;
		argv[i] = (*head)->token;
		i++;
		(*head) = (*head)->next;
	}
	argv[i] = NULL;

	builtNum = is_builtin(argv[0]);

	if (builtNum == 0)
	{
		funcNum = 0;
		if (argv[1] != NULL)
			funcNum = _atoi(argv[1]);

		exit_built(head, funcNum);
	}
	if (builtNum == 1)
	{
		cd_built(argv[1], env);
	}
	if (builtNum == 2)
	{
		env_built(env);
	}
}
