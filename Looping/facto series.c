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

    int n,ans;
    printf("Enter no. of terms to add upto in (1/1!+2/2!+3/3!+4/4!+5/5!....n/n!):\t");
    scanf("%d",&n);
    for (int a=1;a<=n;a++){
        ans=ans+(1/factorial(n-1));
    }
    printf("\n Sum upto %d terms is %d\n",n,ans);
    return 0;

} 