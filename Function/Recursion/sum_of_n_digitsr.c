//recursion sumndigits()

#include <stdio.h>
//#include <stdlib.h>
#include <math.h>

int sumndigitsr(int,int);

int main(){
    int num,n;
    printf("Enter digits & no. of digits:\t");
    scanf("%d%d",&num,&n);
    int temp=pow(10,n);
    printf("Sum of Digits is : %d\n",sumndigitsr( num, temp));
    return 0;
}

int sumndigitsr( int num,int a){
    
    if (a==10){
        return (num%a);
    }
    else{
        return ((( num % a ) - ( num % (a/10) )) /(a/10)) + sumndigitsr(num %a ,a/10);
    }
    
}
    
    
    

/*
    //int temp1=0;                        
    //for (int a=10 ; a<= (pow(10,n)) ; a*=10){
    
        //temp1+=  ;
        //printf("%d\n temp:%d\n",a, temp1);
    }
    return temp1;
}
*/