#include <stdio.h>
#include <stdlib.h>

void prime_factor(int, int);

int main()
{
    int n;
    printf("Enter number to get it\'s prime factor:\t");
    scanf("%d", &n);
    printf("\nPrime factors are:\n");
    prime_factor(n, 1);
    return 0;
}
void prime_factor(int n, int a)
{
    if (a >= n && n == 1)
    {
        exit(0);
    }
    else if (n % a == 0)
    {
        printf("%d\n", a);
        n /= a;
        a = 2; // for first time a=1;then 2 all time
    }
    else
        a++;
    return (prime_factor(n, a));
}

/*
// non recursive way

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
 */