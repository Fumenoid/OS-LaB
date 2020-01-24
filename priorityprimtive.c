#include<stdio.h>
int minarival(int arivatT[],int priority[], int min, int nj) {
    int y;
    for(y=0;y<nj;y++){
        if(arivatT[y]<arivatT[min]) {
            min=y;
        }
    }
    for(y=0;y<nj;y++){
        if(arivatT[min]==arivatT[y]){
           if(priority[min]>priority[y]) {
              min=y;
           } 
        }
    }
    return min;
}
int process(int arivatT[], int burstT[],int priority[],int atime2[], int total, int x, int min,int waitT,int nj){
        printf("\n....%d job is starting....\n", min+1);
        printf("Waiting time for job %d is %d\n", min+1, waitT);
        //Condtions for total time.
        if(x==0) {
            while(total<=(total+arivatT[min]+burstT[min])){
                total+=1;
                for(int z=0;z<nj;z++){
                if(total==atime2[z]){
                    if(priority[min]<=priority[z]){
                        continue;
                    }
                    else {
                        printf("To be continuied\n");
                    }
                }
                }
            }
        }
        else if(arivatT[min]<total && x!=0 ){
            total=(total+burstT[min]);
            while(total<=(total+burstT[min])){
                total+=1;
                for(int z=0;z<nj;z++){
                if(total==atime2[z]){
                    if(priority[min]<=priority[z]){
                        continue;
                    }
                    else {
                        printf("To be continuied\n");
                    }
                }
                }
            }
        }
        else if(arivatT[min]>total && x!=0 )
        {
            while(total<=(arivatT[min]+burstT[min])){
                total+=1;
                for(int z=0;z<nj;z++){
                if(total==atime2[z]){
                    if(priority[min]<=priority[z]){
                        continue;
                    }
                    else {
                        printf("To be continuied\n");
                    }
                }
                }
            }
        }
        else if(arivatT[min]==total)
        {
            while(total<=(total+burstT[min])){
                total+=1;
                for(int z=0;z<nj;z++){
                if(total==atime2[z]){
                    if(priority[min]<=priority[z]){
                        continue;
                    }
                    else {
                        printf("To be continuied\n");
                    }
                }
                }
            }
        }
        else{
            printf("Total computation error\n");
        }
        return total;
}
int main() {
    int nj,x,y,min,temp;
    int waitT=0, TaT;
    int AvgT=0;
    int total=0;
    printf("Enter the number of jobs\n");
    scanf("%d", &nj);
    //All the arrays
    int arivatT[nj];
    int burstT[nj];
    int priority[nj];
    int arrstwt[nj];
    int arrsttt[nj];
    int atime2[nj];
    ///////////////.........Inputs........///////////////
    printf("Enter the arival time of all %d jobs\n", nj);
    for(x=0;x<nj;x++) {
        scanf("%d", &arivatT[x]);
    }
    for(x=0;x<nj;x++) {
        atime2[x]=arivatT[x];
    }
    printf("Enter the burst time of all %d jobs\n", nj);
    for(y=0;y<nj;y++) {
        scanf("%d", &burstT[y]);
    }
    printf("Shorter no. represents higher priority\n");
    printf("Enter the priority of all %d jobs\n", nj);
    for (x=0;x<nj;x++) {
        scanf("%d", &priority[x]);
    }
    /////////////////....process....////////////////
    printf("Process Starting\n");
    //finding the smallest value
    for(x=0;x<nj;x++) {
        min=x;
        min=minarival(arivatT,priority,min,nj);
        //condition for waiting time
        if(arivatT[min] < total){
            waitT=total - arivatT[min];
        }
        total=process(arivatT,burstT,priority,atime2,total,x,min,waitT,nj);
        arrstwt[min]= waitT;
        arrsttt[min]= total;
        waitT=0;
        arivatT[min]=100000;
    }
    ///////////......calculations...../////////////
    for(x=0;x<nj;x++)
    {
        AvgT+= arrstwt[x];
    }
    AvgT= AvgT/nj;
    printf("\nTotal time to complete the process = %d\n", total);
    printf("\nPrinting the values of waiting time\n");
    for(x=0;x<nj;x++){
        printf("Waiting time of process %d = %d\n", x+1, arrstwt[x]);
    }
    printf("\nAverage waiting time= %d\n", AvgT);
    printf("\n\ndebugging process \n");
    for(x=0;x<nj;x++){
        printf("Total at %d = %d\t", x+1, arrsttt[x]);
    }
    printf("\n");
    for(x=0;x<nj;x++){
        printf("Time at %d = %d\t", x+1, atime2[x]);
    }
    printf("\n");
    printf("\nPrinting the turn around time for each process\n");
    for(x=0;x<nj;x++) {
        printf("Turn around time of job %d => %d\n", x+1, arrsttt[x]-atime2[x]);
    }
    printf("\n");
    return 0;
}