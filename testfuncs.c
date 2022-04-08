#include <stdio.h>
#include "main.h"

/**
 * print_list - list all elements in a list
 * @h: the list to display
 * Description: long description
 *
 * Return: the number of nodes.
 */
void print_list(const token_t *h)
{

	while (h != NULL)
	{
		if (h->token == NULL)
			printf("token: (nil)\n");
		else
			printf("token: %s\n", h->token);
		printf("cat: %d\n", h->cat);
		printf("group: %d\n", h->group);
		h = h->next;
	}
}
