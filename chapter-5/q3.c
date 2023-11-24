#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/*
Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?
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
        printf("Hello\n");
    }
    else
    {
        /*sleep(2)*/
        wait(NULL);
        printf("Goodbye");
    }
    return 0;
}

/*
 I don't think the sleep will always guarantee that the child process finishes first. If
 for some reason you are 100% able to tell how long the child process will take to finish,
 then maybe the sleep function could work.
*/
