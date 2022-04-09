#include <stdio.h>
#include "main.h"

/**
 * print_logo_welcome - prints C Shell logo when user starts cshell
 *
 * Return: 0 for success
*/
int print_logo_welcome(void)
{
	_puts("         Welcome to...\n");
	_puts("\n");
	_puts("              /\\\n");
	_puts("             {.-}\n");
	_puts("            ;_.-'\\\n");
	_puts("           {    _.}_\n");
	_puts("           \\.-' /  `,\n");
	_puts("             \\  |    /\n");
	_puts("              \\ |  ,/\n");
	_puts("               \\|_/\n");
	_puts("   ____   ____  _   _ _____ _     _  \n");
	_puts("  / ___| / ___|| | | | ____| |   | |\n");
	_puts(" | |     \\___ \\| |_| |  _| | |   | |\n");
	_puts(" | |___   ___) |  _  | |___| |___| |___\n");
	_puts("  \\____| |____/|_| |_|_____|_____|_____|\n");
	_puts("\n");
	_puts("\n");
	_puts("\n");
	return (0);
}

/**
 * print_logo_goodbye - prints Shell image when user exit shell
 *
 * Return: 0 for success
*/
int print_logo_goodbye(void)
{
	_puts("          Goodbye!\n");
	_puts("\n");
	_puts("            ___\n");
	_puts("        .-'; ! ;'-.\n");
	_puts("      .'!  : | :  !`.\n");
	_puts("     /\\  ! : ! : !  /\\\n");
	_puts("    /\\ |  ! :|: !  | /\\\n");
	_puts("   (  \\ \\ ; :!: ; / /  )\n");
	_puts("  ( `. \\ | !:|:! | / .' )\n");
	_puts("  (`. \\ \\ \\!:|:!/ / / .')\n");
	_puts("   \\ `.`.\\ |!|! |/,'.' /\n");
	_puts("    `._`.\\\\\\!!!// .'_.'\n");
	_puts("       `.`.\\\\|//.'.'\n");
	_puts("        |`._`n'_.'|\n");
	_puts("        \"----^----\"\n");
	_puts("\n");
	_puts("\n");
	_puts("\n");
	return (0);
}
