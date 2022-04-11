#include "main.h"

/**
 * print_error_unknown - prints an error that unknow object passed through.
 * @head: list of tokens to print the token that is unknown.
 * @group: used to find unknown token.
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

	_puts("1: ");
	_puts(hold->token);
	_puts(": not found\n");
}
