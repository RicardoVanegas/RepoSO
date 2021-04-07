#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv){
    int fd[2];
    int pid;
    pipe(fd);
    pid=fork();
    if(pid==0){
        //Hijo
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execl("/bin/tr","tr","' '","-", NULL);
    }
    if(pid > 0){
        //padre
        //close(fd[0])
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execl("/bin/cat","cat",NULL);
    }
    
    return 0;
}