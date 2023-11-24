#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/*
Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including execl(), execle(), execlp(),
execv(), execvp(), and execvP(). Why do you think there
are so many variants of the same basic call?
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
        char *myargs[2];
        myargs[0] = strdup("ls");
        myargs[1] = NULL;
        execvp(myargs[0], myargs);

        /*
        The below will not print out anything. This is because I removed the 'p' from execvp.
        p uses the PATH environment variable therefore I can type ls which would eventually look in
        /bin/ls to find the command. Without p I would need to specify an absolute path.

        myargs[0] = strdup("ls");
        myargs[1] = NULL;
        execv(myargs[0], myargs);
        */
    }
    else
    {
        int wc = wait(NULL);
    }
    return 0;
}

/*
We have different types of exec functions due to multiple scenarios that arise. If you know all of your arguments at compilation
time, then maybe an 'l' type exec would be of use. If you are executing a command in your current path, then a 'p' type
exec could help.
*/