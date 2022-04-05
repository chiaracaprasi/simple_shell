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

#include <stdio.h>
#include <unistd.h>

int main (char ac, char **av, char **env)
{
	int i = 0;

	while (env[i])
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n" , 1);
		i++;
	}
}
