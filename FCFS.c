/*
Algorithm..

First come First serve - It is an non-primtive approach to decide how cpu will execute processes on the basis 
of thier arrival time

step-1 - Store all the arival time in an array
step-2 - store all the burst time in an another array

In a loop
step-3 -find the index of the shortest elemt in arrival time array
step-4 -compute the waiting time
if(shortest arival time < total time) then
    waiting time= totaltime - shortest arival time;
}
step-5 -compute the total time
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
step-6 - store all these waiting times and total time in seperate arrays
step-7 - compute all data required :)
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
    int arrstwt[nj];
    int arrsttt[nj];
    int atime2[nj];
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
    printf("Process Starting\n");
    //finding the smallest value
    for(x=0;x<nj;x++) {
        min=x;
        for(y=0;y<nj;y++){
            if(arivatT[y]<arivatT[min]){
               min=y;
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
        arivatT[min]=100000;
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