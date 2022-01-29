#include <stdio.h>

int sum_upto_nr(int,int);

int main(){
    int num;
    printf("Enter number to print it\'s sum: ");
    scanf("%d",&num);
    
    printf(" =: %d\n",sum_upto_nr(num,0));
    
    return 0;
}


int sum_upto_nr( int num,int sum){
    
    if (num==1){
        printf(" 1 ");
        return 1;
    }
    else{
        sum+=num;
        printf(" %d +",num);
        return (num+sum_upto_nr( num-1,sum));
    }


}


/*
//non recursive method
int sum_upto_n(int num){
    int sum=0;
    for (int a=1 ;a<=num ;a++){
        sum+=a;
        printf(" %d +",a);    
    }
    return sum;
}
*/