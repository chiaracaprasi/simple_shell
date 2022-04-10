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
int group_sort(int grp_test, token_t **head, char **env, char *buffer)
{
	token_t *use = *head;

	if (use != NULL)
	{
		while (use->group != grp_test)
		{
			if (use->next != NULL)
				use = use->next;
			else
				break;
		}
	}

	if (use->cat == 0)
	{
		print_error_unknown(head, grp_test);
		return (grp_test + 1);
	}
	if (use->cat == 1)
	{
		exc_cmd(head, grp_test);
		return (grp_test + 1);
	}

	if ((*head)->cat == 2)
	{
		exc_built(head, grp_test, env, buffer);
		return (grp_test + 1);
	}
	return (grp_test +  1);
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
	size_t bufsize = 0;
	ssize_t error = 0;
	int flag = 0, group, grp_test = 1, l = 0;

	/*create liked list with the hist_func stuff*/
	do {
		grp_test = 1;
		if (isatty(STDIN_FILENO))
			print_prompt();

		error = getline(&buffer, &bufsize, stdin);
		if (error <= 0 || buffer[0] == '\n')
		{
			if (!is_end_of_shell(buffer, error))
				flag = -1;
			continue;
		}

		fflush(stdin);
		group = tokenise(&head, buffer, env);
		while (grp_test <= group)
		{
			grp_test = group_sort(grp_test, &head, env, buffer);
		}
		free(buffer);
		buffer = NULL;
		free_tok(&head);
		l++;
	} while (flag != -1);
	print_logo_goodbye();
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
void print_prompt(void)
{
	write(STDOUT_FILENO, "->", 3);
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

	signal(SIGINT, signal_handler);
	if (isatty(STDIN_FILENO))
	{
		clear();
		print_logo_welcome();
	}

	return (get_line(env));
}
