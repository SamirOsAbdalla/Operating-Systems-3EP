#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
4. Write a simple program that allocates memory using malloc() but
forgets to free it before exiting. What happens when this program
runs? Can you use gdb to find any problems with it? How about
valgrind (again with the --leak-check=yes flag)?
*/

int main(int argc, char **argv)
{
    int *p = (int *)malloc(sizeof(int));
    return 0;
}

/*
Valgrind was able to find the 4 bytes (the int that was dynamically allocated) that were lost.
*/