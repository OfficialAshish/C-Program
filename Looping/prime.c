#include <stdio.h>
int main(){
    int i,num;
    i=0;
    printf("Enter num");
    scanf("%d",&num);

    while(i<num){

        for (int x=1;x<i;x++){
            if(x%2==0){
                //x%2==0;
                break;
            }
            else if (x<i){
                printf("%d\n",i);

            }
        }
        i+=1;
    }
    return 0;
    
}