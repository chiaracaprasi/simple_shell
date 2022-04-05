#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"

/**
 * print_newline - prints a newline
 * Return: nothing.
 */
void print_newline()
{
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * signal_handler - handles signals processing
 * @signal: signals given
 *
 * Return: void
 */

void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		print_newline();
		print_prompt();
	}
}
