#include <stdio.h>
#define R 3
#define C 3

bool sym(int m[][C] , int n);

int main()
{
    int m[R][C];
    printf("\nEnter Matrix : ");
    
    //initializing matrix
    for (int i=0 ; i<R ; i++)
    {
        printf("\nEnter Row %d : ", i+1);
        for (int j=0 ; j<C ;j++)
        {
            scanf("%d",(*(m+i)+j));
        }
        printf("\n");
    }
    //printing matrix
    printf("\nMatrix is: \n")
    for (int i=0; i<R ; i++)
    {
        for (int j=0; j<C ; j++)
        {
            printf("\t %d," , *(*(m+i)+j));
        }
        printf("\n");
    }
    
    //checking matrix
    bool ans=sym( m , C);
    
    if (ans==true)
    {
        printf("\nIt is Symmetric Matrix.");
    }
    else printf("\nIt is non-symmetric Matrix.");
    return 0;
}

bool sym( int m[][C] , int n)
{
    for (int i=0 ; i<R ; i++)
    {
        for (int j=0 ; j<C ; j++)
        {
            if ( m[i][j] == m[j][i] )
            {
                if (i==R-1){
                    return true;
                }
                else continue;
            }
            else return false;
        }
    }
}






/*
//with pointer (ERROR in passing array) 
#include <stdio.h>
#define R 3
#define C 3

bool sym(int *p, int n);

int main()
{
    int m[R][C];
    printf("Enter Matrix : ");
    
    for (int i=0 ; i<R ; i++)
    {
        for (int j=0 ; j<C ;j++)
        {
            scanf("%d",(*(m+i)+j));
        }
        printf("\n");
    }
    bool ans=sym( m , C);
    
    if (ans==true)
    {
        printf("\nIt is Symmetric Matrix.");
    }
    else printf("\nIt is non-symmetric Matrix.");
    return 0;
}

bool sym( int *p , int n)
{
    for (int i=0 ; i<R ; i++)
    {
        for (int j=0 ; j<C ; j++)
        {
            if ( *(*(p+i)+j) == *(*(p+j)+i) )
            {
                if (i==R-1){
                    return true;
                }
                else continue;
            }
            else return false;
        }
    }
}

*/