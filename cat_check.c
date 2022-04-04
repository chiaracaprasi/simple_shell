#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"

/**
 * is_builtin - checks if the token is a builtin
 * @str_tok: string to check if builtin
 * Description: long description
 *
 * Return: arrray number of builtin or -1 if not builtin
 */
int is_builtin(char *str_tok)
{
	char *builtin[] = {
		"ls",
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

/**
 * is_alias - checks if the token is an alias
 * @str_tok: string to check if alias
 * Description: long description
 *
 * Return: arrray number of alias or -1 if not alias.
 */
int is_alias(char *str_tok)
{
	/**
	 * this is a placeholder function at the moment, will need to
	 * make dynamic for final build and implementations
	 */

	char *alias[] =	{
		"e",
		 "NULL"};
	int i = 0;

	while (alias[i] != "NULL")
	{
		if (_strcmp(alias[i], str_tok) == 0)
			return (i);
		i++;
	}

	return (-1);
}
