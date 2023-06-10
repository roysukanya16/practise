#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#define MAX_SIZE 100

int main(){
    char buffer[MAX_SIZE];
    void *shared_memory;
    int shmid;
    shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
    printf("\nShmid= %d",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("\nProcess atached at address: %p",shared_memory);
    printf("\nEnter your message: ");
    int n= read(0,buffer,MAX_SIZE);
    strcpy(shared_memory,buffer);
    printf("your message: %s",(char *)shared_memory);

    return 0;
}