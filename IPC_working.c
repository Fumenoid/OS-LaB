#include<stdio.h>
#include<unistd.h>
int main() {
   int fds[2];
   int returnstatus;
   int pid;
   char writemessage[20];
   char readmessage[20];
   returnstatus = pipe(fds);
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   printf("Write message to be displayed: ");
   scanf("%s",writemessage);

   pid=fork();
   if (pid==0) {
      printf("Child Process writing: %s\n", writemessage);
      write(fds[1], writemessage, sizeof(writemessage));
   } else {
   read(fds[0], readmessage, sizeof(readmessage));
      printf("Parent Process reading: %s\n", readmessage);
   }
   return 0;
}