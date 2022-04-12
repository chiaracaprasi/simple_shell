#ifndef MAIN_H
#define MAIN_H

#define clear() _puts("\033[H\033[J")

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
int is_builtin(char *str_tok);
int is_alias(char *str_tok);
int group_sort(int grp_test, token_t **h, char **env, char *buffer, char **av);
int get_line(char **av, char **env);
int is_end_of_shell(char *buffer, int error);
void signal_handler(int signal);
/* print functions */
void print_logo_welcome(void);
void print_logo_goodbye(void);
void print_prompt(void);
/* tokeniser functions */
token_t *add_token(token_t **head, int group, char *str_tok, char **env);
void free_tok(token_t **head);
int set_tok_cat(char *tok);
int set_tok_grp(token_t *head, int group);
int tokenise(token_t **head, char *str, char **env);
/* system exc functions */
char *get_path(char *search, char **env);
char **path_seperator(char *str, char *delims);
char *path_checker(char *cmd, char **dir);
char *path_finder(char *cmd, char **env);
void exc_cmd_test(char * const cmd_array[]);
void exc_cmd(token_t **head, int group);
/* library functions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
void _puts(char *str);
int _putchar(char c);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* builtin funcs */
void exc_built(token_t **head, int group, char **env, char *buffer);
void exit_built(token_t **head, int status, char *buffer);
void cd_built(char *dir, char **env);
int env_built(char **env);
char *_getenv(char *name, char **env);
int env_start(char *path, char *var);
void output_help(char *cmd);
/* functions for testing */
void print_list(const token_t *h);

#endif
