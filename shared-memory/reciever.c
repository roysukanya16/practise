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
    int shmid=shmget((key_t)1122,1024,0666);
    shared_memory=shmat(shmid,NULL,0);
    printf("\nContnt in shared memory: %s",(char *)shared_memory);

    return 0;
}