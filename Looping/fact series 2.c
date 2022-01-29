#include <stdio.h>
int main(){
    
    int factorial(int f){
        int x,fact=1;
        if(f==0){
            return (1);
        }
        
        else {
            for (x=1;x<=f;x++){
                fact=fact*x;
            }
        }

        return (fact);
    }

    int n,summ;
    printf("Enter no. of terms to add upto in (1/1!+2/2!+3/3!+4/4!+5/5!....n/n!):\t");
    scanf("%d",&n);
    printf("%dhhggh",factorial(n-1));
    printf("%d\n",summ);
    summ=0;
    for (int a=1;a<=n;a++){
        summ=summ+(1/factorial(n-1));
        printf("%d\n",summ);
    }

    printf("\n Sum upto %d terms is \n%d\n",n,summ);
    return 0;

} 