#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int a=fork();
    pid_t id;
    if(a==0) {
      printf("Child process created\n");
      id=getpid();
      printf("Process Id = %d\n", id);
      execve("./createafolder.sh", NULL, NULL);
    }
    else if (a>0)
    {
        printf("Parent process\n");
        id=getpid();
        printf("Process Id = %d\n", id);
    }
    else
    {
        printf("Process failed");
    }
	return 0;
}