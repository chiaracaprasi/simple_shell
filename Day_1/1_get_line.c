#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define clear() printf("\033[H\033[J")

char *tokenise(char *str)
{
    // Returns first token
	char* token = strtok(str, " ");

// Keep printing tokens while one of the
    // delimiters present in str[].
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	return 0;
}
/**
 * get_line - gets line and waits for input.
 * @av: the strings/arguments we need to print
 * Return: always 0.
 */
int get_line()
{
    char *buffer = NULL;
    size_t bufsize = 32, error;
    int flag = 0;

    printf("****WELCOME TO OUR C-SHELL****\n");
    do {
	    printf("$ ");
	    error = getline(&buffer,&bufsize,stdin);
	    if (error == -1)
	    {
		    printf("could not handle argument, memory issues\nAborting Shell\n");
		    flag = 1;
	    }
	    if ((strcmp(buffer, "exit\n")) == 0)
	    {
		    printf("goodbye!\n");
		    flag = 1;
	    }
	    else
		    tokenise(buffer);

    } while (flag == 0);

    free(buffer);
    return(0);
}

/**
 * main - voids ac.
 * @ac: number of arguments passed (VOID)
 * @av: the strings/arguments we need to print
 * Return: result of get_line function.
 */
int main(int ac, char **av)
{
	(void)ac;
	clear();
	return (get_line());
}
