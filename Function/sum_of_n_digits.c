#include <stdio.h>
//#include <stdlib.h>
#include <math.h>

int sumndigits(int,int);

int main(){
    int num,n;
    printf("Enter digits & no. of digits:\t");
    scanf("%d%d",&num,&n);
    //int temp=pow(10,n);
    printf("Sum of Digits is : %d\n",sumndigits( num, n));
    return 0;
}

int sumndigits( int num,int n){
    int temp1=0;
    for (int a=10 ; a<= (pow(10,n)) ; a*=10){
    
        temp1+= ( ( num % a ) - ( num % (a/10) ))/(a/10) ;
        //printf("%d\n temp:%d\n",a, temp1);
    }
    return temp1;
}