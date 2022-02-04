
#include <stdio.h>
void pythagorean_triplets();

void pythagorean_triplets(int n) {
    int count=0;
    for (int a=1; a<=n ; a++){
        for (int b=1; b<=n ; b++){
            for (int c=1; c<=n ; c++){
                if(((a*a) ==(b*b)+(c*c)) || ((b*b)== (a*a) + (c*c)) || ((c*c) == (a*a) + (b*b))){
                    printf(" a:%d\n b:%d \n c:%d\n", a,b,c);
                    printf("( %d, %d, %d )\n\n", a,b,c);
                    count+=1;
                }
            }
        }
    }
    printf("Total no. of Triplets are : %d",count);
}

int main(){
    int n;
    printf("Enter no. to get pythagorean triplets upto : ");
    scanf("%d" ,&n);
    pythagorean_triplets( n );
    return 0;
}