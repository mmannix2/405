#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char** argv) {
    int num = 100;
    
    printf("*** Problem #1 ***\n");
    
    printf("num has been set to %d.\n", num);
    
    int rc = fork();
    if(rc < 0) {
        //fork failed; exit
        exit(1);
    }
    else if( rc == 0) {
        //Child process
        printf("Hello, I am the child. (pid:%d)\n", 
            (int) getpid());
        
        printf("\tnum: %d\n", num);
        num = 200;
        printf("\tnum: %d\n", num);
    }
    else {
        //Parent process
        printf("Hello, I am the parent of %d. (pid:%d)\n",
            rc, (int) getpid());
        
        printf("\tnum: %d\n", num);
        num = 0;
        printf("\tnum: %d\n", num);
    }
    
    return 0;
}
