#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
1. First, write a simple program called null.c that creates a pointer
to an integer, sets it to NULL, and then tries to dereference it. Compile this into an executable called null. What happens when you
run this program?

2. Next, compile this program with symbol information included (with
the -g flag). Doing so lets puts more information into the executable, enabling the debugger access more useful information about
variable names and the like. Run the program under the debugger
by typing gdb null and then, once gdb is running, typing run.
What does gdb show you?

3. Finally, use the valgrind tool on this program. We’ll use the memcheck
tool that is a part of valgrind to analyze what happens. Run
this by typing in the following: valgrind --leak-check=yes
null. What happens when you run this? Can you interpret the
output from the tool?
*/

int main(int argc, char *argv[])
{
    int *null = NULL;
    int temp = *null;

    return 0;
}

/*
1. The result is that we get a segmentation fault!

2. GDB gives us information about the signal that indicates a seg fault has occurred. It also gives
the virtual memory address of where the seg fault occurred.

3. A whole host information is given to us ranging from the error that occurred (seg fault), whether
or not any heap blocks were allocated/if a memory leak occurred and more. Valgrind is also able to
track which regions of the program are valid regions i.e. if a memory access is within the program's
region or not.
*/