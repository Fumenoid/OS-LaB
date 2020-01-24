#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define MSGSIZE 20

int main()
{
    int a=fork();
    int fd[2];
    char inbuf[MSGSIZE];
    pid_t id;
    if (pipe(fd) < 0) {
        return 1;
    }
    if(a==0) {
        printf("Child process created\n");
        id=getpid();
        printf("Process Id = %d\n", id); 
        close(fd[1]);  
        close(fd[1]);
        read(fd[0], inbuf, MSGSIZE);  
        printf("Data read= % s\n", inbuf);     
    }
    else if (a>0)
    {
        printf("Parent process\n");
        id=getpid();
        char* msg1 = "hello world!";
        printf("Process Id = %d\n", id);
        write(fd[1], msg1, MSGSIZE); 
        //read(fd[0], inbuf, MSGSIZE);  
        //printf("Data Written= % s\n", inbuf);
        close(fd[0]);
        close(fd[1]);
    }
    else
    {
        printf("Process failed");
    }
	return 0;
}