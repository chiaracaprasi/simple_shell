#include <stdlib.h>
#include "main.h"

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use seperator out words
 *
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i) != '\0')
	{
		if (str[i] == delims[0])
			pending = 1;
		else if (pending == 1)
		{
			wLen++;
		}
		if (wLen > 0 && str[i] == delims[0])
			break;
		i++;
	}
	return (wLen);
}

/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use seperator out words
 *
 * Return: the word count
 */

int get_word_count(char *str, char *delims)
{
	int wordCount = 0, pending = 1, i = 0;

	while (*(str + i) != '\0')
	{
		if (str[i] == delims[0])
			pending = 1;
		else if (pending == 1)
		{
			pending = 0;
			wordCount++;
		}
		i++;
	}
	return (wordCount);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use seperator out words
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i) != '\0')
	{
		if (str[i] == delims[0])
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}

/**
 * path_seperator - takes a path list and seperates it
 *
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: an array of pointers to each individual path
 */

char **path_seperator(char *str, char *delims)
{
	char **words;
	int wordCount, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wordCount = get_word_count(str, delims);
	if (wordCount == 0)
		return (NULL);
	words = malloc((wordCount + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	for (; i < wordCount; i++)
	{
		wordLen = get_word_length(str, delims);
		if (*str == delims[0])
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delims);
	}
	words[i] = NULL;
	return (words);
}
