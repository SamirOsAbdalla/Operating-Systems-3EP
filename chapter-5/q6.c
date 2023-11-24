#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/*
Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be
useful?
*/
int main(int argc, char *argv[])
{
    int rc = fork();
    int status;
    if (rc < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Hi, I'm a child process\n");
    }
    else
    {
        int wc = waitpid(rc, &status, WUNTRACED);

        if (wc == rc)
        {
            printf("Hi, I'm a parent process\n");
        }
    }
    return 0;
}

/*
waitpid() would be useful if you have multiple child processes and you want the parent process
to obtain the status information of a specific one
*/