// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int pid = fork();
    if (pid == 0) {
        printf("hello it's child again");
        char *args[3];
        args[0] = "/bin/ls";
        args[1] = "-n";
        args[2] = NULL;
        execvp(args[0], args);
    } else {
        printf("it's parent");
    }
    return 0;
}

// From what I can tell, one of the primary reasons there are so many variants
// within the exec family is because they require different numbers and types of arguments
// and they similarly offer different specifications and outputs.