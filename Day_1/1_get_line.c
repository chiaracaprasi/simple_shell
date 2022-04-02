#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define clear() printf("\033[H\033[J")
/**
 * tokenise - splits the initial string into it's seperate parts.
 * @av: the strings/arguments we need to print
 * Return: always 0.
 */
char **tokenise(char *str, )
{

	/* store each token in an array, and return a pointer to the array to the get_line function
	   so that was can send each item seperatly to the execute function*/

	// Returns first token
	char* token = strtok(str, " ");


	// Keep printing tokens while one of the

	// delimiters present in str[].
	while (token != NULL)
	{
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
    /*create liked list with the hist_func stuff*/
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
		    /*advanced task, need to handle exit codes eg exit 98*/
		    printf("goodbye!\n");
		    flag = 1;
	    }
	    else
		    /*add buffer to new element in linked list with hist_func stuff*/

		    /*need a pointer to an array to store the return value*/
		    tokenise(buffer); /*split the arguments up divided by space " "*/

	    /*New function that will take the information and see if it is an executable*/
	    /*this function will handle the forking of children*/

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
