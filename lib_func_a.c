#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"

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

/**
 * char *_strcat - add src to the end of dest
 * @dest: will be the string that is added too
 * @src: the string to copy
 * Description: long description
 *
 * Return: pointer to dest.
 */
char *_strcat(char *dest, char *src)
{

	int startCopy = _strlen(dest);
	int i = 0;

	while (src[i] != '\0')
	{
		dest[startCopy] = src[i];
		i++;
		startCopy++;
	}
	dest[startCopy] = src[i];
	return (dest);
}
