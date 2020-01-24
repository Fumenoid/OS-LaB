#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
struct page_table
{
int page;
int frame;
};
int main()
{
int n, x;
int msize, hsize, ndiv, ndivp;
int tmem;
printf("Enter the Size of the memory in KB\n");
scanf("%d", &msize);
printf("Enter the Size of a Partition in KB\n");
scanf("%d", &hsize);
if(msize%hsize==0){
    ndiv = msize/hsize;
}
else
{
    int temp=msize-(msize%hsize);
    ndiv = temp/hsize; 
    printf("Space wasted due to uneven distribution = %d\n", (msize%hsize));
}
printf("\nNumber of divisions = %d\n", ndiv);
int rdiv=ndiv;
printf("Enter the number of processes\n");
scanf("%d", &n);
printf("Calculating..\n");
struct page_table Process[n];
for(x=0;x<n;x++)
{
    Process[x].page=x+1;
    Process[x].frame=x+1;
}
for(x=0;x<n;x++){
    printf("Enter the size of memory required by process %d in kb\n", x+1);
    scanf("%d", &tmem); 
    if(tmem%hsize==0){
        ndivp = tmem/hsize;
    }
    else if(tmem<hsize)
    {
        ndivp = 1;
    }
    else
    {
        int temp2 = tmem%hsize;
        ndivp = tmem/hsize;
        printf("Memory wasted due to internal fragmentation = %d\n", hsize-temp2);     
    }
    if(rdiv>=ndivp){
    printf("Partitions used by the process = %d\n", ndivp);
    rdiv=rdiv-ndivp;
    printf("Remaing unallocated partitions = %d\n", rdiv);
    //logiacal address
    int pagenumber=(rand()%n)+1;
    int offset=rand()%100;
    for(int i=0;i<n;i++){
        if(Process[i].page==pagenumber){
            printf("Generating Physical address\n");
            printf("Physical address = %d,%d\n", Process[i].frame*Process[i].page+100, offset);
        }
    }
    }
    else
    {
        printf("\nExiting because Memory is Full\n");
        break;
    }    
}
return 0;
}