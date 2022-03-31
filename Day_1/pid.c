#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
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
