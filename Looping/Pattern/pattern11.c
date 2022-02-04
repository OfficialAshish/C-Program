//pattern11
#include <stdio.h>
#include <math.h>

int main() {
    
    static int lay=1;
    for(int  l=1; l<7; l++){
        
        lay= 1 * lay;
        for(int n =( pow(10, (l)) ); n>=10; n=(n/10) ){
            
            //printf("\t%d\n",lay);
            
            //printf("n:%d\n",n);
            {
                int d;
                d=(lay%(n)-lay%(n/10))/(n/10);
                printf("\t%d",d);
            }
            
        }
        printf("\n");
        //printf("lay:%d\n",lay);
        lay=lay*11;
        //printf("lay:%d\n",lay);
    }
    printf("\ndone");
    
    return 0;
}
