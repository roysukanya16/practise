#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    int fd[2],n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p=fork();
    
    if(p>0){
        //close(fd[0]);
        printf("\npassing value to child");
        write(fd[1],"hello/n",6);
    }
    else{
       // close(fd[1]);
        n=read(fd[0],buffer,100);
        write(1,buffer,n);
    }
    return 0;
}