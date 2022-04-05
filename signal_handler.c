#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"


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
		printf("\n->");
	}
}
