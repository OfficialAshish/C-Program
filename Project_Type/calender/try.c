//pattern11-2
#include <stdio.h>
#include <math.h>

int main() {
    
    printf("%d\n",1);
    for(int lay=1, l=1;l<6;l++){
        
        lay=1*lay;

        for(int n=(pow(10,(l)));n>=10; n-=10){
            {
                int a,b,c;
                a= lay % (10* n) ;
                b= (a - lay % (1* n) ) ;
                c= b/ (1* n );
                //printf("\t%d",c);
            //}
            printf("\nl:%d\n",l);
            printf(" n:%d\n",n);
            }
        }
        printf ("\n");
        lay=lay*11;
        //printf("lay:%d\n",lay);
    }
    printf("\ndone");

    return 0;
}