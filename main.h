#ifndef MAIN_H
#define MAIN_H

#define clear() printf("\033[H\033[J")

/**
* struct s_tokens - list of input broken down into words
* @token: the full token of what was typed
* @cat: the category the token fits (1=linux command, 2=builtin, 4=flag)
* @group:the group of tokens that this token belongs to.
* @next: pointer to next element in list
*
* Description: When the input is parsed, each word is broken into different
* parts and each part is allocated a group (used if the ';' operator is used) &
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

/*Main functions*/
int print_logo_welcome(void);
int print_logo_goodbye(void);
int is_builtin(char *str_tok);
int is_alias(char *str_tok);
int group_sort(int grp_test, token_t **head);
int get_line(char **env);
/* tokeniser functions */
token_t *add_token(token_t **head, int group, char *str_tok);
void free_tok(token_t **head);
int set_tok_cat(token_t *head, int group);
int tokenise(token_t **head, char *str);
/* system exc functions */
void exc_cmd_test(char * const cmd_array[]);
int exc_cmd(token_t **head, int group);
/* library functions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
#endif
