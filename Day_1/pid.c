#include <stdio.h>
#include <unistd.h>

/**
 * main - finds and prints currant and parent PIDs
 * Description - my_pid is the pid for current process;
 * p_pid is the pid for parent process
 * test is testing that a pid is stored in an unsigned int
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t p_pid;
	unsigned int test;

	test = getpid();
	my_pid = getpid();
	p_pid = getppid();

	printf("pid: %u\n", my_pid);
	printf("test pid: %u\n", test);
	printf("ppid: %u\n", p_pid);

	return (0);
}
