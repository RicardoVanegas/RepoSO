#include <unistd.h>
#include <ctype.h>
 #include <stdio.h>
int main(){
    char minC;
    int linea = 0;
    while(read(0,&minC,1)){
        
        if(minC == '\n'){
            
            linea++;
        }
       
    }
    if(minC != '\n'){
            
            linea++;
        }
    
    printf("lineas: %d \n", linea );
    
    return 0;
}
//programa probado y correcto con min2may