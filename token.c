#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"

/**
 * add_token - adds a new token element to the end of list
 * @head: first string to compare
 * @group: second string to compare
 * @str_tok: tokens
 * @env: enviroment variables
 * Description: Every new elemnt category is set to 1
 * and will be defined as a syste call unless told otherwise.
 *
 * Return: pointer to new list element.
 */
token_t *add_token(token_t **head, int group, char *str_tok, char **env)
{
	char *strCpy = NULL;
	token_t *new = NULL;
	token_t *hold = NULL;
	int file_found;

	strCpy = _strdup(str_tok);
	if (strCpy == NULL)
		return (NULL);
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);

	new->group = group;
	new->cat = set_tok_cat(str_tok);
	if (new->cat == 0)
	{
		strCpy = get_path(strCpy, env);
		file_found = access(strCpy, X_OK);
		if (file_found >= 0)
			new->cat = 1;
	}
	new->token = strCpy;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	hold = *head;
	while (hold->next != NULL)
		hold = hold->next;
	hold->next = new;
	return (new);
}

/**
 * free_tok - frees list of tokens
 * @head: list to free
 * Description: long description
 *
 * Return: void
 */
void free_tok(token_t **head)
{
	token_t *hold = NULL;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		hold = *head;
		if (hold->token != NULL)
			free(hold->token);
		*head = (*head)->next;
		free(hold);
	}
	head = NULL;
}

/**
 * set_tok_cat - chooses cat from list.
 * @tok: token to check
 * Description: long description
 *
 * Return: cat number
 */
int set_tok_cat(char *tok)
{
	if (is_builtin(tok) >= 0)
		return (2);
	if (is_alias(tok) >= 0)
		return (3);
	if (tok[0] == '-')
		return (4);
	if (_strcmp(tok, "||") == 0)
		return (5);
	if (_strcmp(tok, "&&") == 0)
		return (6);
	if (_strcmp(tok, ";") == 0)
		return (7);
	return (0);
}
/**
 * set_tok_grp - sets group;
 * @head: list to set group of
 * @group: group number tokens are up to.
 * Description: long description
 *
 * Return: group
 */
int set_tok_grp(token_t *head, int group)
{
	token_t *use = head;

	while (use->next != NULL)
		use = use->next;
	if (use->cat == 7)
		return (group + 1);
	return (group);
}
/**
 * tokenise - splits the initial string into it's seperate parts.
 * @head: list to store tokens in
 * @str: full str passed into command line
 * @env: enviroment variables
 * Return: always 0.
 */
int tokenise(token_t **head, char *str, char **env)
{
	char *rem_nl = strtok(str, "\n");
	char *buff_commands = strtok(rem_nl, " ");
	int group = 1;

	while (buff_commands != NULL)
	{
		add_token(head, group, buff_commands, env);
		group = set_tok_grp(*head, group);
		buff_commands = strtok(NULL, " ");
	}

	return (group);
}
