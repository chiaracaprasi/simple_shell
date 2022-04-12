#include "main.h"
#define ERROR "C_SHELL: help: no help topics match your input\n"
#define ERRORWRITE "C_SHELL: failed to read helpfile\n"

/**
 * output_help - sends help page to standard output
 * @cmd: the argument to look for help files for.
 * Return: 0 (success)
 */

void output_help(char *cmd)
{
	char *cdhelp =
#include "cd.help"
		;
	char *envhelp =
#include "env.help"
		;
	char *helphelp =
#include "help.help"
		;
	char *exithelp =
#include "exit.help"
		;

	if (_strcmp(cmd, "cd") == 0)
		_puts(cdhelp);

	else if (_strcmp(cmd, "env") == 0)
		_puts(envhelp);

	else if (_strcmp(cmd, "help") == 0)
		_puts(helphelp);

	else if (_strcmp(cmd, "exit") == 0)
		_puts(exithelp);

	else
		_puts(ERROR);
}
