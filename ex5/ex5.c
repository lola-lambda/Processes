// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    char buff[MSGSIZE];
    int desc[2];

    if (pipe(desc) < 0) {
        printf("failed:(\n");
        exit(1);
    }

    int pid = fork();
    if (pid == 0) {
        close(desc[1]);
        for (int i = 0; i < 3; i++) {
            read(desc[0], buff, MSGSIZE);
            printf("%s\n", buff);
        }
    } else {
        close(desc[0]);
        write(desc[1], msg1, MSGSIZE);
        write(desc[1], msg2, MSGSIZE);
        write(desc[1], msg3, MSGSIZE);
    }
    return 0;
}
