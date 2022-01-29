#include <stdio.h>

void prime_factor(int);

int main(){
    int n;
    printf("Enter number to get it\'s prime factor:\t");
    scanf("%d",&n);
    prime_factor(n);
    return 0;

}
void prime_factor(int n){
    printf("\nPrime factors are:\n");
    for(int a=1 ; a<=n && n!=1 ; a++){

        if ( n % a==0){

            printf("%d\n",a);
            n/=a;
            a=1;
        }
    }

}