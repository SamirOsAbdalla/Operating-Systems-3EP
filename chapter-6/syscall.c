#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Here we are going to measure the cost of a syscall
int main(int argc, char *argv[])
{
    int empty[0];
    FILE *fptr = fopen("empty.txt", "r");
    struct timespec start, finish, final_time;

    clock_gettime(CLOCK_REALTIME, &start);

    fread(empty, sizeof(int), 0, fptr);

    clock_gettime(CLOCK_REALTIME, &finish);

    final_time.tv_sec = finish.tv_sec - start.tv_sec;
    final_time.tv_nsec = finish.tv_nsec - start.tv_nsec;
    if (final_time.tv_nsec < 0)
    {
        final_time.tv_sec--;
        final_time.tv_nsec *= -1;
    }
    printf("%d.%.9ld\n", (int)(final_time.tv_sec), final_time.tv_nsec);
}

// Result was about 500-600 nanoseconds for a single system call