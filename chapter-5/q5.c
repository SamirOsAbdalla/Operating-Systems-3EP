#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?
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
        int wc = wait(NULL);
        printf("Hi, I'm a child process\n");
        printf("Wait return value: %d\n", wc);
    }
    else
    {
        printf("Hi, I'm a parent process\n");
    }
    return 0;
}
/*
wait() returned -1 which signifies an error. Apparently when wait() is
called in a child process 'C', it will immediately return if there are no more
child processes of 'C' (which makes sense because what would it be waiting for).
Also the parent process consistently ran first.
*/