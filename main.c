#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"

/**
 * group_sort - handles the number of groups
 * @grp_test: the group we are handling now
 * @head: list of tokens
 * Return: always 0.
 */
int group_sort(int grp_test, token_t **head)
{
	if ((*head) != NULL)
	{
		while ((*head)->group != grp_test)
		{
			if ((*head)->next != NULL)
				(*head) = (*head)->next;
			else
				break;
		}
	}

	if ((*head)->cat == 1)
	{
		exc_cmd(head, grp_test);
		return (grp_test + 1);
	}

	return (grp_test);
}

/**
 * get_line - gets line and waits for input.
 * @env: list of enviroment properties
 * Return: always 0.
 */
int get_line(char **env)
{
	token_t *head = NULL;
	char *buffer = NULL;
	size_t bufsize = 0, error;
	int flag = 0, group, grp_test = 1;

	/*create liked list with the hist_func stuff*/
	do {
		grp_test = 1;
		write(1, "-> ", 3);
		error = getline(&buffer, &bufsize, stdin);
		if (error == -1)
		{
			printf("could not handle argument, memory issues\nAborting Shell\n");
			flag = 1;
		}
		/**
		 * if ((_strcmp(buffer, "\n")) == 0)
		 * go back or something or rather
		 */
		if ((_strcmp(buffer, "exit\n")) == 0)
		{
			print_logo_goodbye();
			flag = 1;
		}
		if (flag != 1)
		{
			group = tokenise(&head, buffer);
			while (grp_test <= group)
			{
				grp_test = group_sort(grp_test, &head);
			}
			free_tok(&head);
		}
	} while (flag == 0);
	free(buffer);
	return (0);
}

/**
 * main - voids ac.
 * @ac: number of arguments passed (VOID)
 * @av: the strings/arguments we need to print
 * @env: list of eviroment properties
 * Return: result of get_line function.
 */
int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	clear();
	print_logo_welcome();
	return (get_line(env));
}
