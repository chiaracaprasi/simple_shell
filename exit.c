#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * exit_built - exits the shell safely
 * @status: the exit status required.
 * @head: the token list to free.
 * @buffer: original buffer to free.
 * return: void
 */
void exit_built(token_t **head, int status, char *buffer)
{
	free(buffer);
	buffer = NULL;
	free_tok(head);
	exit(status);
}
