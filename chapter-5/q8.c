#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/*
Write a program that creates two children, and connects the standard output of one
to the standard input of the other, using the pipe() system call
*/
#define BUFFER_SIZE 20
int main(int argc, char *argv[])
{
    int p[2];
    if ((pipe(p) < 0))
    {
        printf("p error");
    }

    int pid1, pid2;
    pid1 = fork();

    if (pid1 < 0)
    {
        fprintf(stderr, " pid1 fork failed");
        exit(1);
    }
    else if (pid1 == 0)
    {
        close(p[0]);
        if (dup2(p[1], STDOUT_FILENO) < 0)
        {
            printf("error duplicating p1");
            exit(1);
        }

        printf("message from child1");
    }
    else
    {
        int status;
        if ((pid2 = fork()) < 0)
        {
            fprintf(stderr, "pid2 fork failed");
            exit(1);
        }

        if (pid2 == 0)
        {
            close(p[1]);
            if (dup2(p[0], STDIN_FILENO))
            {
                printf("error duplicating p0");
                exit(1);
            }

            char buf[BUFFER_SIZE];
            read(STDIN_FILENO, buf, BUFFER_SIZE);
            printf("Received message:%s\n", buf);
        }
        else
        {
            waitpid(pid1, NULL, 0);
            waitpid(pid2, &status, WUNTRACED);
        }
    }
    return 0;
}

/*Tough problem. I needed help from external resources GREATLY from this one but I ended
up learning much more about pipes and dup2. WORTH*/
