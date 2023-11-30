#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
5.Write a program that creates an array of integers called data of size
100 using malloc; then, set data[100] to zero. What happens
when you run this program? What happens when you run this
program using valgrind? Is the program correct?
*/

int main(int argc, char **argv)
{
    int *data = (int *)malloc(100 * sizeof(int));
    data[100] = 0;

    return 0;
}

/*
Valgrind reports an invalid write of size 4 which makes sense considering we are writing an integer
to memory that was not explicitly allocated for our program. The program is not correct since we
are acting as if we had 101 integers given to use instead of 100.
*/