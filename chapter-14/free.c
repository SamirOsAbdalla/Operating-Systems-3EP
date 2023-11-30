#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
6. Create a program that allocates an array of integers (as above), frees
them, and then tries to print the value of one of the elements of
the array. Does the program run? What happens when you use
valgrind on it?

7. Now pass a funny value to free (e.g., a pointer in the middle of the
array you allocated above). What happens? Do you need tools to
find this type of problem?
*/

int main(int argc, char **argv)
{

    int *data = (int *)malloc(10 * sizeof(int));
    // Question 6:
    // free(data);
    // printf("Value at index 2: %d", data[2]);

    // Question 7:
    free(data + 5);
}

/*
6. The program runs however it prints some absurdly large integer. Valgrind reports an invalid read of size
4, which makes sense considering we are attempting to read an integer at a memory location that is no
longer allocated.

7. In this case, the program reports that free was passed an invalid pointer. I guess tools would be
needed if you had multiple free() calls in your program and needed to find which one was the root cause.
*/