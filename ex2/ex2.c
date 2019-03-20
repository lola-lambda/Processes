// Write a program that opens the text.txt file 
// (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. 
// Can both the child and parent access the file descriptor returned by `fopen()`? 
// What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * filePointer;
    filePointer = fopen("./text.txt", "w+");
    pid_t pid = fork();
    if (pid == 0) {
        fprintf(filePointer, "%s", "hello! it's me, the child\n");
        fclose(filePointer);
        printf("child file %p\n", filePointer); 
    } else {
        fprintf(filePointer, "%s", "hello! it's me, the parent\n");
        fclose(filePointer);
        printf("parent file %p\n", filePointer); 
    }
    return 0;
}

// The parent and child processes are both able to access the file descriptor.
// When they both write to the file, the parent's string is written first and the child's follows.