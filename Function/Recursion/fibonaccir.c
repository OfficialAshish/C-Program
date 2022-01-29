#include <stdio.h>
//#include <stdlib.h>

int fibonaccir(int);
int main(){
    int num;
    printf("Enter number to print Fibonacci seq. upto.. :");
    scanf("%d",&num);

    printf("Fibonacci Series is: \n 1, ");
    fibonaccir(num);
    printf("\n");
    return 0;
}

int fibonaccir(int n){
    static int a=0,b=1,c=0,counter=2;
    if (counter>n){
        return 0;
    }
    else {
        c=a+b;
        printf("%d, ",c);
        a=b;
        b=c;
        counter+=1;
        return (fibonaccir(n));


    }
}



/* 
// nonRecurive way
void fibonacci(int n){
    for(int i=1,a=0,b=1,c=0; i<n; i++){
        
        c=a+b;
        printf("%d, ",c);
        a=b;
        b=c;
    }
    printf("\n\n");
} 

*/