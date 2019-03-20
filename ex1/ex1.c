// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    pid_t pid = fork();
    if (pid == 0) {
        printf("child %d; initially x is %i\n", pid, x);
        x = 50;
        printf("child %d; now x is %i\n", pid, x);
    } else {
        printf("parent %d; initially x is %i\n", pid, x);
        x = 20;
        printf("parent %d; now x is %i\n", pid, x);
    }
    return 0;
}

// outputs:
// parent 44655; initially x is 100
// parent 44655; now x is 20
// child 0; initially x is 100
// child 0; now x is 50

// In this implementation, the child gets the original value of x, 
// not the modified x from the parent. Both the parent and child can overwrite the value of x.
// The end value of x will be the modification of the last process, which is the child in this case.