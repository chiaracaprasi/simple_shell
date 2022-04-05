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
 * _strlen - will return the length of the string passed through
 * @s: the string we need to count
 * Description: long description
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	char string = *s;
	int counter = 0;

	while (string != '\0')
	{
		counter++;
		string = *(s + counter);
	}
	return (counter);
}

/**
 * _strcpy - a string to copy to a saved buffer
 * @dest: buffer for string
 * @src: the string we are going to copy
 * Description: long description
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int counter = _strlen(src);
	int i = 0;

	while (i <= counter)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _strdup - duplicate string
 * @str: the string we will duplicate.
 * Description: long description
 *
 * Return: pointer to new string or null
 */
char *_strdup(char *str)
{
	int len;
	char *cpy;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	cpy = malloc(len + 1);
	if (cpy == NULL)
		return (NULL);
	_strcpy(cpy, str);
	return (cpy);
}

/**
 * _strcmp - compare two string values
 * @s1: first string to compare
 * @s2: second string to compare
 * Description: long description
 *
 * Return: the difference between the strings
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int retValue = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			break;
		if (s2[i] == '\0')
			break;
		i++;
	}
	retValue = s1[i] - s2[i];
	return (retValue);
}
