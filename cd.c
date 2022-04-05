#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/**
 * change_dir- handles cd builtin
 * :
 * Description: locates if command entered exists in the bin directory
 *
 * Return: 0 for success, -1 for not found
 */


/* int main(void)
{
	char s[100];

	printf("%s\n", getcwd(s, 100));
	chdir("..");
     	printf("%s\n", getcwd(s, 100));
	chdir("/home");
	printf("%s\n", getcwd(s, 100));
	return (0);
}
*/
