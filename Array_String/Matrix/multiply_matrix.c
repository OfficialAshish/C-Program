#include <stdio.h>
#define R1 3
#define CR 3
//#define CR 3
#define C2 3

void multiply();
int main(){
        
    int A[R1][CR] , B[CR][C2] , C[R1][C2] ;
    
    printf("\nEnter Matrix A :\n");
    
    for (int i=0 ; i<R1 ; i++)
    {
        printf("\nEnter Row %d : ",i+1);
        for (int j=0 ; j<CR ; j++)
        {
            scanf("%d", (*(A+i)+j));
        }
    }
    
    printf("\nEnter Matrix B :\n");
    
    for (int i=0 ; i<CR ; i++)
    {
        printf("\nEnter Row %d : ",i+1);
        for (int j=0 ; j<C2 ; j++)
        {
            scanf("%d", (*(B+i)+j));
        }
    }
    
    printf("\n Matrix A :\n");
    
    for (int i=0 ; i<R1 ; i++)
    {
        for (int j=0 ; j<CR ; j++)
        {
            printf(" %d, ", *(*(A+i)+j));
        }
        printf("\n");
    }
    
    printf("\n Matrix B :\n");
    
    for (int i=0 ; i<CR ; i++)
    {
        for (int j=0 ; j<C2 ; j++)
        {
            printf(" %d, ", *(*(B+i)+j));
        }
        printf("\n");
    }
    
    //multiply (C=A*B)
    multiply( A,B,C );
    
    //printing C
    
    printf("\n Matrix (C=A*B) :\n");
    
    for (int i=0 ; i<R1 ; i++)
    {
        for (int j=0 ; j<C2 ; j++)
        {
            printf(" %d, ", *(*(C+i)+j));
        }
        printf("\n");
    }
    return 0;
}

void multiply ( int a[][CR], int b[][C2] , int c[][C2])
{
    for (int i=0 ; i<R1 ; i++)
    {
        for (int j=0 ; j<C2 ; j++)
        {
            int sum=0;
            for (int k=0; k<CR ; k++)
            {
                //sum= sum + (*(*(a+i)+k)) * (*(*(b+k)+j));
                sum = sum + ( a[i][k] * b[k][j] );
            }
            c[i][j] = sum;
        }
    }
}
     