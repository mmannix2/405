#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    printf("***Problem #3***\n");
    
    int rc = fork();
    if(rc < 0) {
        //fork failed; exit
        exit(1);
    }
    else if(rc == 0) {
        //Child process
        printf("Hello (pid: %d)\n", (int)getpid());
    }
    else {
        //Parent process
        wait(NULL);
        printf("Goodbye (pid: %d)\n", (int)getpid());
    }

    return 0;
}
