#include <stdio.h>
#include <unistd.h>

/**
 * print_av - print argv without using argc
 * @av: the strings/arguments we need to print
 * Return: always 0.
 */
int print_av(char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("av[%d] = %s\n", i, av[i]);
		i++;
	}

	return (0);
}

/**
 * main - voids ac.
 * @ac: number of arguments passed (VOID)
 * @av: the strings/arguments we need to print
 * Return: result of print_av function.
 */
int main(int ac, char **av)
{
	(void)ac;

	return (print_av(av));
}
