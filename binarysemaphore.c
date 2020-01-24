#include<stdio.h>
#include<unistd.h>
int release() {
    return 1;
}
int acquired() {
    sleep(3);
    return release();
}
int main() {
    int nj,lock=0,k=0;
    printf("Enter the number of jobs\n");
    scanf("%d", &nj);
    for(int x=0;x<nj;x++) {
        printf("\nprocess %d running..\n", x+1);
        while(lock==0){
            printf("process %d entered critical section..\n", x+1);
            k++;
            for(int y=k;y<nj;y++){
            printf("process %d is waiting..\n", y+1);
            }
            lock=acquired();
        }
        printf("process %d left critical section..\n", x+1);
        lock=0;
    }
    return 0;
}