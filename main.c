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
int group_sort(int grp_test, token_t **head, char **env)
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

	if ((*head)->cat == 0)
	{
		print_error_unknown(head, grp_test);
		return (grp_test + 1);
	}
	if ((*head)->cat == 1)
	{
		exc_cmd(head, grp_test);
		return (grp_test + 1);
	}

	if ((*head)->cat == 2)
	{
		exc_built(head, grp_test, env);
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
		if (isatty(STDIN_FILENO))
			print_prompt();
		error = getline(&buffer, &bufsize, stdin);
		if (error <= 0 || buffer[0] == '\n')
		{
			if (!is_end_of_shell(buffer, error))
				return (0);
			continue;
		}
		fflush(stdin);
		if (flag != 1)
		{
			group = tokenise(&head, buffer);
			while (grp_test <= group)
			{
				grp_test = group_sort(grp_test, &head, env);
			}
			free_tok(&head);
		}
	} while (flag == 0);
	return (0);
}

/**
 * is_end_of_shell - checks if the input is end of shell or new line
 * @buffer: inputter string
 * @error: number of bytes in string
 * Return: 0 if \n or 1 if no bytes.
 */
int is_end_of_shell(char *buffer, int error)
{
	if (buffer)
	{
		buffer = NULL;
		return (1);
	}
	if (error <= 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		fflush(stdin);
		return (0);
	}
	return (1);
}
/**
 * print_prompt - prints prompt
 * Return: nothing.
 */
void print_prompt()
{
	write(STDOUT_FILENO, "-> ", 3);
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

	signal(SIGINT, signal_handler);
	return (get_line(env));
}
