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
 * Description: Every new elemnt category is set to 1
 * and will be defined as a syste call unless told otherwise.
 *
 * Return: pointer to new list element.
 */
token_t *add_token(token_t **head, int group, char *str_tok)
{
	char *strCpy;
	token_t *new = NULL;
	token_t *hold = NULL;

	strCpy = _strdup(str_tok);
	if (strCpy == NULL)
		return (NULL);

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);

	new->group = group;
	new->cat = 0;
	strCpy = path_finder(strCpy);
	if ((path_start(strCpy)) == 1)
		new->cat = 1;
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
		*head = (*head)->next;
		if (hold->token != NULL)
			free(hold->token);
		free(hold);
	}
	head = NULL;
}

/**
 * set_tok_cat - sets category in list
 * @head: list to free
 * @group: group number tokens are up to.
 * Description: long description
 *
 * Return: void
 */
int set_tok_cat(token_t *head, int group)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	if (is_builtin(head->token) >= 0)
		head->cat = 2;
	if (is_alias(head->token) >= 0)
		head->cat = 3;
	if (head->token[0] == '-')
		head->cat = 4;
	if (_strcmp(head->token, "||") == 0)
		head->cat = 5;
	if (_strcmp(head->token, "&&") == 0)
		head->cat = 6;
	if (_strcmp(head->token, ";") == 0)
	{
		head->cat = 7;
		return (group + 1);
	}
	return (group);
}
/**
 * tokenise - splits the initial string into it's seperate parts.
 * @head: list to store tokens in
 * @str: full str passed into command line
 * Return: always 0.
 */
int tokenise(token_t **head, char *str)
{
	char *rem_nl = strtok(str, "\n");
	char *buff_commands = strtok(rem_nl, " ");
	int group = 1, size = _strlen(str) + 1;

	while (buff_commands != NULL)
	{
		add_token(head, group, buff_commands);
		group = set_tok_cat(*head, group);
		buff_commands = strtok(NULL, " ");
	}

	return (group);
}
