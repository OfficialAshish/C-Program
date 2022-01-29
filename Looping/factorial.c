#include <stdio.h>
int main(){
    
    int factorial(int f){
        int x,fact=1;
        for (x=1;x<=f;x++){
            fact=fact*x;
        }
        return (fact);
    }

    int num,ans;
    printf("Enter factorial upto:\t");
    scanf("%d",&num);
    ans=factorial(num);
    printf("%d\n",ans);
    return 0;

} 