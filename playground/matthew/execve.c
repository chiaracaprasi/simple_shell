#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"

/**
 * _calloc - Write a function that allocates memory for an array
 * @nmemb: the number of elements in the array
 * @size: the size of each array element
 * Description: long description
 *
 * Return: add in what is supposed to be returned if anything
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *array;
	char *fill;
	unsigned int counter = 0;

	if (size == 0 || nmemb == 0)
		return (NULL);

	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);

	fill = array;
	while (counter < nmemb * size)
	{
		fill[counter] = 0;
		counter++;
	}

	return (array);
}

void exc_cmd_test(char * const cmd_array[])
{
	if (execve(cmd_array[0], cmd_array, NULL) == -1)
	{
		printf("ERROROROROR!!!!!\n");
		return;
	}
	printf("child process executed");
}

int exc_cmd(token_t **head, int group)
{
	char *argv[100];
	pid_t child_pid;
	int status, argc = 0, i = 0;
	token_t * hold = *head;

	while (hold->group < group)
		hold = hold->next;

	while (hold->group == group)
	{
		argc++;
		if (hold->next == NULL)
			break;
		hold = hold->next;
	}
	while (i < argc)
	{
		if (_strcmp((*head)->token, ";") == 0)
			break;
		argv[i] = (*head)->token;
		i++;
		(*head) = (*head)->next;
	}
	argv[i] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}

	if (child_pid == 0)
	{
		exc_cmd_test(argv);
	}
	wait(&status);
	return (0);
}
