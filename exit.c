#include <stdlib.h>
#include "main.h"
/**
 * exit_built - exits the shell safely
 * @status: the exit status required.
 * @head: the token list to free
 * return: void
 */
void exit_built(token_t **head, int status)
{
	print_logo_goodbye();
	free_tok(head);
	exit(status);
}
