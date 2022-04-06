#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

/**
 * read_textfile - reads text file and prints to POSIX standard output
 *@filename: file name
 *@letters: letters
 *Return: Number of letters to read and print or 0 if error occurs.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	int bytread;
	int bytwrite;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters + 1);

	if (buffer == NULL)
		return (0);

	bytread = read(fd, buffer, letters);

	if (bytread == -1)
	{
		free(buffer);
		return (0);
	}

	bytwrite = write(STDOUT_FILENO, buffer, bytread);

	if (bytwrite == -1)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fd);
	return (bytwrite);
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    ssize_t n;

    if (ac != 2)
    {
        dprintf(2, "Usage: %s filename\n", av[0]);
        exit(1);
    }
    n = read_textfile(av[1], 114);
    printf("\n(printed chars: %li)\n", n);
    n = read_textfile(av[1], 1024);
    printf("\n(printed chars: %li)\n", n);
    return (0);
}
