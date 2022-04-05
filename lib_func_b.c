#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"

/**
 * _atoi - will print numbers in string
 * @s: the string we want ot search for numbers
 * Description: long description
 *
 * Return: will return nothing
 */
int _atoi(char *s)
{
	unsigned int value = 0;
	int numOfNeg = 0;
	int posNeg = 1;

	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			break;
		}
		if (*s  == '-')
		{
			numOfNeg++;
		}
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		value *= 10;
		value += (*s - '0');
		s++;
	}
	if (numOfNeg % 2 != 0)
		posNeg = -1;
	return (value * posNeg);
}

/**
 * _puts - short description
 * @str: the string we want to display
 * Description: long description
 *
 * Return: nothing
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
