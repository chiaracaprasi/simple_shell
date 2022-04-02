#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _strlen - will return the length of the string passed through
 * @s: the string we need to count
 * Description: long description
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	char string = *s;
	int counter = 0;

	while (string != '\0')
	{
		counter++;
		string = *(s + counter);
	}
	return (counter);
}

/**
 * _strcpy - a string to copy to a saved buffer
 * @dest: buffer for string
 * @src: the string we are going to copy
 * Description: long description
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int counter = _strlen(src);
	int i = 0;

	while (i <= counter)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _strdup - duplicate string
 * @str: the string we will duplicate.
 * Description: long description
 *
 * Return: pointer to new string or null
 */
char *_strdup(char *str)
{
	int len;
	char *cpy;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	cpy = malloc(len + 1);
	if (cpy == NULL)
		return (NULL);
	_strcpy(cpy, str);
	return (cpy);
}

token_t *add_token(token_t **head, int group, char *str_tok)
{
	char *strCpy;
	int strLen = 0;
	token_t *new = NULL;
	token_t *hold = NULL;

	strCpy = _strdup(str_tok);
	if (strCpy == NULL)
		return (NULL);

	while (strCpy[strLen] != '\0')
	{
		strLen++;
	}

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);

	new->group = group;
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
 * _strcmp - compare two string values
 * @s1: first string to compare
 * @s2: second string to compare
 * Description: long description
 *
 * Return: the difference between the strings
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int retValue = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			break;
		if (s2[i] == '\0')
			break;
		i++;
	}
	retValue = s1[i] - s2[i];
	return (retValue);
}

int is_builtin(char *str_tok)
{
	char *builtin[] =
		{"billbo",
		 "NULL"};
	int i = 0;

	while (builtin[i] != "NULL")
	{
		if (_strcmp(builtin[i], str_tok) == 0)
			return (i);
		i++;
	}

	return (-1);
}

int set_tok_cat(token_t *head, int group)
{
	while (head->next != NULL)
	{
		head = head->next;
	}

	if (head->token[0] == '-')
		head->cat = 4;
	if (_strcmp(head->token, "||") == 0)
		head->cat = 5;
	if (_strcmp(head->token, "&&") == 0)
		head->cat = 6;
	if (is_builtin(head->token) >= 0)
		head->cat = 2;
	if (_strcmp(head->token, ";") == 0)
	{
		head->cat = 7;
		return (group + 1);
	}
	return (group);
}
/**
 * tokenise - splits the initial string into it's seperate parts.
 * @av: the strings/arguments we need to print
 * Return: always 0.
 */
token_t *tokenise(token_t **head, char *str)
{
	char *rem_nl = strtok(str, "\n");
	char *buff_commands = strtok(rem_nl, " ");
	int group = 1, size = _strlen(str) + 1;

	/*issue with not seperating out ALL ; tokens\
not sure how we will go about fixing it. maybe needle/haystack approach.
if sep_store = buff_seperator, ALL the address are the same so it appears
we will need to make a copy (_strcpy ^^ above) to be able to run it twice??*/

	while (buff_commands != NULL)
	{
		add_token(head, group, buff_commands);
		group = set_tok_cat(*head, group);
		buff_commands = strtok(NULL, " ");
	}

	return (*head);
}

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
 * print_list - list all elements in a list
 * @h: the list to display
 * Description: long description
 *
 * Return: the number of nodes.
 */
size_t print_list(const token_t *h)
{
	size_t nodeCount = 0;

	while (h != NULL)
	{
		if (h->token == NULL)
			printf("token: (nil)\n");
		else
			printf("token: %s\n", h->token);
		printf("cat: %d\n", h->cat);
		printf("group: %d\n", h->group);
		h = h->next;
		nodeCount++;
	}

	return (nodeCount);
}
/**
 * get_line - gets line and waits for input.
 * @av: the strings/arguments we need to print
 * Return: always 0.
 */
int get_line()
{
	token_t *head = NULL;
	char *buffer = NULL;
	size_t bufsize = 32, error;
	int flag = 0;

	/*create liked list with the hist_func stuff*/
	do {
		printf("$ ");
		error = getline(&buffer,&bufsize,stdin);
		if (error == -1)
		{
			printf("could not handle argument, memory issues\nAborting Shell\n");
			flag = 1;
		}
		if ((_strcmp(buffer, "exit\n")) == 0)
		{
			/*advanced task, need to handle exit codes eg exit 98*/
			print_logo_goodbye();
			flag = 1;
		}
		else
			/*add buffer to new element in linked list with hist_func stuff*/
			/*need a pointer to an array to store the return value*/
			tokenise(&head, buffer); /*split the arguments up divided by space " "*/
		print_list(head);
		free_tok(&head);
		/*New function that will take the information and see if it is an executable*/
		/*this function will handle the forking of children*/

	} while (flag == 0);
	free(buffer);
	return(0);
}

/**
 * main - voids ac.
 * @ac: number of arguments passed (VOID)
 * @av: the strings/arguments we need to print
 * Return: result of get_line function.
 */
int main(int ac, char **av)
{
	(void)ac;
	clear();
	print_logo_welcome();
	return (get_line());
}
