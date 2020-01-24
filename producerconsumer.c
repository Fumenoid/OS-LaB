#include<stdio.h>
#include<unistd.h>
int sumb=0;
int y=0;
int release() {
    sumb=0;
    y++;
    return 1;
}
int acquired(int y) {
    if(y==0){
        for(int z=1;z<=10;z++){
            sumb=sumb+z;
        }
        printf("Sum of 10 natral number=%d\n", sumb);
    }
        if(y==1){
        for(int z=2;z<=10;z+=2){
            sumb=sumb+z;
        }
        printf("Sum of even numbers till 10=%d\n", sumb);
    }
    return release();
}
int main() {
    int x,n=10,sum=0,lock=0,k=0;
    printf("This program will print sum of natural numbers till 10.\n");
    printf("And the sum of even numbers till 10.\n");
    for(x=1;x<=n;){
        sum=sum+x;
        x++;
        if(x%2==0){
            sum=sum+x;
        }
    }
    printf("The sum of 10 natural numbers=%d\n", sum);
    printf("The sum of even numbers till 10=%d\n", sum);
    printf("This will result in an error as Sum is used by both the proces..\nThat is the one that prints sumof natural noand the one that prints sum of even number\n");
    printf("\nSo, We are using binary semaphore to solve this problem\n");
    printf("Process 1 = process to add natural numbers\n");
    printf("Process 2 = process to add even number till 10\n");
    for(int x=0;x<2;x++) {
        while(lock==0){
            printf("\nprocess %d is running, to print..\n", x+1);
            printf("process %d entered critical section..\n", x+1);
            lock=acquired(y);
        }
        printf("process %d left critical section..\n", x+1);
        lock=0;
        k++;
        for(int y=k;y<2;y++){
            printf("process %d is waiting..\n", y+1);
        }
    }
    return 0;
}