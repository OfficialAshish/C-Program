//pattern11
#include <stdio.h>
#include <math.h>

int main() {
    
    
    for(int lay=1, l=1; l<6; l++){
        
        lay= 1 * lay;
        for(int n =( pow(10, (l-1)) ); n>=10; n=(n/10) ){
            
            printf("\t%d\n",lay);
            
            printf("n:%d\n",n);
            {
                //int d;
                //d=(lay%(10*n)-lay%(1*n))/(1*n);
                //printf("\t%d",d);
            }
            
        }
        lay=lay*11;
        printf("lay:%d\n",lay);
    }
    printf("\ndone");
    
    return 0;
}
