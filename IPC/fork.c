#include <stdio.h>
#include <unistd.h>

void signalHandler(int sig){
  int pidHijoTermino = wait(NULL);
  printf("Mi hijo termino %d\n", pidHijoTermino);
}

int main(){
    signal(17,signalHandler);
    int pid= fork();
    int pidHijoTermino;
    if(pid==0){
        printf("Soy el proceso hijo\n");
    }else{
        printf("Soy el proceso padre y mi hijo es %d\n", pid);
        //wait(NULL);
        while(1){
            printf("Trabajando\n");
            sleep(1);
        }
        printf("Mi hijo termino\n", pidHijoTermino);
    }
    printf("Terminando\n");
    return 0;
}