#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
1. Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?
*/
int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        x = 101;
        printf("Child process value of x: %i\n", x);
    }
    else
    {
        x = 102;
        printf("Parent process value of x: %i\n", x);
    }
    return 0;
}

/*
I believe the point of this problem was to get us to realize that a child process has access
to its own set of variables.

Edit: After some digging, I believe this is due to the copy-on-write mechanism which will
detect that the child is writing to a parent's memory page due to changing x. Then a
duplicated page is created for the child.
*/