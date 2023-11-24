#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/*
Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?
*/
int main(int argc, char *argv[])
{
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        close(STDOUT_FILENO);
        printf("Hi from the child");
    }
    else
    {
        wait(NULL);
        printf("Hi from the parent");
    }
    return 0;
}

/*
Only the output from the parent is printed
*/
