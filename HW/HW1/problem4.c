#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    printf("***Problem #4***\n");
    
    int rc = fork();
    if(rc < 0) {
        //fork failed; exit
        exit(1);
    }
    else if(rc == 0) {
        //Child process
        printf("Hello, I am the child. (pid: %d)\n", (int)getpid());
        
        char* const args[4] = {"/bin/ls", "-l", "answers.txt", NULL};

        execvp(args[0], args);
        
        printf("this shouldn't print out.\n");
    }
    else {
        //Parent process
        printf("Hello, I am the parent of %d. (pid: %d)\n", rc, (int)getpid());
    }

    return 0;
}
