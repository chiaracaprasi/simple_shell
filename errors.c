#include "main.h"

/**
 * print_error_unknown - prints an error that unknow object passed through.
 * @head: list of tokens to print the token that is unknown.
 * grp_test: used to find unknown token.
 *
 * return: void
 */
void print_error_unknown(token_t **head, int group)
{
	token_t *hold = *head;

	while (hold->group < group)
	{
		hold = hold->next;
	}

	_puts("Error - unknown command: ");
	_puts(hold->token);
	_puts("\n");
}