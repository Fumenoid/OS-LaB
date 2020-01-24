#include <stdio.h> 
#include <unistd.h> 
#define MSGSIZE 16 
char* msg1 = "hello, world #1"; 
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], i; 
  
    if (pipe(p) < 0) 
        return 1; 
  
    write(p[1], msg1, MSGSIZE); 
    read(p[0], inbuf, MSGSIZE); 
    printf("% s\n", inbuf); 
    return 0; 
} 