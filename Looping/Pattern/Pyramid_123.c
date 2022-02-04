#include <stdio.h>

int main() {
    
    for(int i=1;i<11;i++){
        if(i==2 || i==4 || i==7){
            printf ("\n");
        }
        if(i==1){
            printf ("\t\t\t\t");
        }
        if(i==2){
            printf ("\t\t\t");
        }
        if(i==4){
            printf ("\t\t");
        }
        if(i==7){
            printf ("\t");
        }
        
        printf("\t%d",i);
    }
    return 0;
}
