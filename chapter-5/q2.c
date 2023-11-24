#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?
*/

#define BUFFER_SIZE 5
int main(int argc, char *argv[])
{
    FILE *fptr;
    fptr = fopen("file.txt", "w");
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        char buffer[] = "CCCCC";
        fwrite(buffer, sizeof(buffer[0]), BUFFER_SIZE, fptr);
    }
    else
    {
        char buffer[] = "PPPPP";
        fwrite(buffer, sizeof(buffer[0]), BUFFER_SIZE, fptr);
    }
    return 0;
}

/*
The result here is that both buffers are written to the file. This makes sense considering that
a fork() call copies the parent process information which includes variables, open files, etc.
*/