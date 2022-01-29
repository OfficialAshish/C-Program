#include <stdio.h>

int sum_upto_n(int);

int main(){
    int num;
    printf("Enter number to print it\'s sum: ");
    scanf("%d",&num);
    
    printf(" =: %d\n",sum_upto_n(num));
    
    return 0;
}

int sum_upto_n(int num){
    int sum=0;
    for (int a=1 ;a<=num ;a++){
        sum+=a;
        printf(" %d +",a);    
    }
    return sum;
}