#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    printf("***Problem #2***\n");
    
    const char* file_name = "answers.txt";
    int file_mode = O_WRONLY | O_APPEND;
    int file_desc;    
    
    int rc = fork();
    if(rc < 0) {
        //fork failed; exit
        exit(1);
    }
    else if(rc == 0) {
        //Child process
        printf("Child process (pid: %d)\n", (int)getpid());
        
        file_desc = open(file_name, file_mode);
        if(file_desc == -1) {
            printf("An error has occurred %s cannot be opened for writing.\n",
                file_name);
        }
        else {
            printf("The child has opened the file!\n");
            
            if( write(file_desc, "I'm writing to a file! - Child\n", 31)
                != 31) {
                printf("Write error!\n");
            }
            else {
                printf("The child wrote to the file!\n");
            }
        }
    }
    else {
        //Parent process
        printf("Parent process (pid: %d)\n", (int)getpid());
        
        file_desc = open(file_name, file_mode);
        if(file_desc == -1) {
            printf("An error has occurred %s cannot be opened for writing.\n",
                file_name);
        }
        else {
            printf("The parent has opened the file!\n");
        
            if( write(file_desc, "I'm writing to a file! - Parent\n", 32)
                != 32) {
                printf("Write error!\n");
            }
            else {
                printf("The parent wrote to the file!\n");
            }
        }
    }

    return 0;
}
