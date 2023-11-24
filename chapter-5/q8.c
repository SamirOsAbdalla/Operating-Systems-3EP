#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/*
Write a program that creates two children, and connects the standard output of one
to the standard input of the other, using the pipe() system call
*/
#define MESSAGE_SIZE 14
char *message = "child1 message";
int main(int argc, char *argv[])
{

    int fds[] = {STDIN_FILENO, STDOUT_FILENO};
    if (pipe(fds) < 0)
    {
        printf("pipe error");
    }

    int child1 = fork();

    if (child1 < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (child1 == 0)
    {
        write(fds[1], message, MESSAGE_SIZE);
    }
    else
    {
    }
    return 0;
}
