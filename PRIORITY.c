/*
Algorithm..

Priority based - It is an primtive approach to decide how cpu will execute processes on the basis 
of thier  priority,if the priority is same then it is decided on the basis of arival time.

step-1 - Store all the arival time in an array
step-2 - store all the burst time in an another array
step-3 - store all the priorities min no= higher priority

In a loop
step-4 -find the index of the shortest elemt in burst time array
step-5 -if there is some process which starts and ends faster than the min burst execute it
step-6 -compute the waiting time
if(shortest arival time < total time) then
    waiting time= totaltime - shortest arival time;
}
step-7 -compute the total time
Condtions for total time.
if(x==0) that is first itteration {
total time = totaltime + shortestarivattime + burstTtimeofthatshortestarivalt);
}
else if(shortestarivattime < totaltime && x!=0 ){
total time=(total+burstTtime);
}
else if(shortestarivattime > totaltime && x!=0 )
{
total time = burstTtime + arivaltimeofthatprocess;
}
else if(arivatTtime==totaltime)
{
totaltime += burstTtime;
}
else{
    print Total computation error
}
step-8 - store all these waiting times and total time in seperate arrays
step-9 - compute all data required :)
*/
#include<stdio.h>
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
    int arivatT2[nj];
    //Taking Inputs

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
    for(y=0;y<nj;y++) {
        arivatT2[y]=arivatT[y];
    }
    printf("Shorter no. represents higher priority\n");
    printf("Enter the priority of all %d jobs\n", nj);
    for (x=0;x<nj;x++) {
        scanf("%d", &priority[x]);
    }
    printf("Process Starting\n");
    //finding the smallest value
    for(x=0;x<nj;x++) {
        min=0;
        for(y=0;y<nj;y++){
            if(priority[y]<priority[min]){
               min=y;
            }
        }
        for(y=0;y<nj;y++) {
        if(priority[min]==priority[y]){
            if(arivatT[min]>arivatT[y])
            {
            min = y;
            }
        } 
        }
        //condition for waiting time
        if(arivatT[min] < total){
            waitT=total - arivatT[min];
        }
        printf("\n....%d job is starting....\n", min+1);
        printf("Waiting time for job %d is %d\n", min+1, waitT);
        //Condtions for total time.
        if(x==0) {
            total=(total+arivatT[min]+burstT[min]);
            //printf("total at x=0, %d\n", total);
        }
        else if(arivatT[min]<total && x!=0 ){
            total=(total+burstT[min]);
            //printf("total at arival < total, %d\n", total);
        }
        else if(arivatT[min]>total && x!=0 )
        {
            total=(burstT[min]+arivatT[min]);
            //printf("total at arival > total, %d\n", total);
        }
        else if(arivatT[min]==total)
        {
            total+=burstT[min];
            //printf("total at arival == total, %d\n", total);
        }
        else{
            printf("Total computation error\n");
        }
        arrstwt[min]= waitT;
        arrsttt[min]= total;
        waitT=0;
        priority[min]=10000;
    }
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
