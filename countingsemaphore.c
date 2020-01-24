#include<stdio.h>
#include<unistd.h>
int wait(int s) {
     sleep(3);
     s--;
     return s;
}
int signal() {
   return 3;
}
int main() {
    int nj, s=3, k=nj,total=0;
    printf("Enter the number of Process\n");
    scanf("%d", &nj);
    for(int x=0;x<nj;x++) {
        printf("process %d,%d,%d is in crital state\n", total+1,total+2,total+3);
        while(s>0){
            if(total==nj){
                break;
            }
            total+=1;
            s=wait(s);
        }
        s=signal();
        if(total==nj){
                break;
        }
        for(int y=total;y<nj;y++){
            printf("process %d is waiting..\n", y+1);
        }
    }
printf("\n Task completed\n");
return 0;
}