#ifndef MAIN_H
#define MAIN_H

#define clear() printf("\033[H\033[J")

/**
* struct s_hist - list of inputss typed into shell during runtime
* @command - pointer to the string used.
* @next: pointer to next element in list
*
* Description: this list is stored in a file upon close for later inspection.
*/
typedef struct s_hist
{
	int pos;
	char *command;
	struct s_hist *next;
} hist_t;

/**
* struct s_tokens - list of input broken down into words
* @token: the full token of what was typed
* @cat: the category the token fits (1=linux command, 2=builtin, 4=flag)
* @group:the group of tokens that this token belongs to.
* @next: pointer to next element in list
*
* Description: When the input is parsed, each word is broken into different
* parts and each part is allocated a group (used if the ';' operator is used) and a
* category that is used to define how the shell will use this particular token
*
*/
typedef struct s_tokens
{
	char *token;
	int cat;
	int group;
	struct s_tokens *next;
} token_t;

int print_logo_welcome(void);
int print_logo_goodbye(void);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void *_calloc(unsigned int nmemb, unsigned int size);
int exc_cmd(token_t **head, int group);
int _strcmp(char *s1, char *s2);

#endif
