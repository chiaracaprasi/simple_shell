#include <stdio.h>
#include "main.h"

/**
 * print_logo_welcome - prints C Shell logo when user starts cshell
 *
 * Return: 0 for success
*/
int print_logo_welcome(void)
{
	printf("         Welcome to...\n");
	printf("\n");
	printf("              /\\\n");
	printf("             {.-}\n");
	printf("            ;_.-'\\\n");
	printf("           {    _.}_\n");
	printf("           \\.-' /  `,\n");
	printf("             \\  |    /\n");
	printf("              \\ |  ,/\n");
	printf("               \\|_/\n");
	printf("   ____   ____  _   _ _____ _     _  \n");
	printf("  / ___| / ___|| | | | ____| |   | |\n");
	printf(" | |     \\___ \\| |_| |  _| | |   | |\n");
	printf(" | |___   ___) |  _  | |___| |___| |___\n");
	printf("  \\____| |____/|_| |_|_____|_____|_____|\n");
	printf("\n");
	printf("\n");
	printf("\n");
	return (0);
}

/**
 * print_logo_goodbye - prints Shell image when user exit shell
 *
 * Return: 0 for success
*/
int print_logo_goodbye(void)
{
	printf("          Goodbye!\n");
	printf("\n");
	printf("            ___\n");
	printf("        .-'; ! ;'-.\n");
	printf("      .'!  : | :  !`.\n");
	printf("     /\\  ! : ! : !  /\\\n");
	printf("    /\\ |  ! :|: !  | /\\\n");
	printf("   (  \\ \\ ; :!: ; / /  )\n");
	printf("  ( `. \\ | !:|:! | / .' )\n");
	printf("  (`. \\ \\ \\!:|:!/ / / .')\n");
	printf("   \\ `.`.\\ |!|! |/,'.' /\n");
	printf("    `._`.\\\\\\!!!// .'_.'\n");
	printf("       `.`.\\\\|//.'.'\n");
	printf("        |`._`n'_.'|\n");
	printf("        \"----^----\"\n");
	printf("\n");
	printf("\n");
	printf("\n");
	return (0);
}

/*
 int main(void)
 {

	print_logo_welcome();
	print_logo_goodbye();
	return (0);
}
*/
