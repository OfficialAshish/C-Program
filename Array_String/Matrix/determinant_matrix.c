#include <stdio.h>
#include <math.h>
int determinant(int A[][3]);


int main()
{
    int A[3][3];
    printf("Determinant for 3×3 matrix. \n");

    for (int i = 0; i < 3; i++)
    {
        printf("Enter Row %d : ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
        printf("\n");
    }

    //printing matrix

    printf("\nMatrix A is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d, ", *(*(A + i) + j));
        }
        printf("\n");
    }
    printf("\nDeterminant of above Matrix is : %d \n", determinant(A));

    return 0;
}

int determinant( int A[3][3])
{
    int j=0,sum=0;
    for (int i=0 ; i<3 ; i++)
    {
        int m=0,l=0;
        m=i+1;
        l=i+2;
        if ( l==3 )
        {
            l=0;
        }
        else if ( m==3 )
        {
            m=0;
            l=1;
        }
        sum = sum + ( ( A[i][j] ) * ( (A[m][j+1] * A[l][j+2] )  - (A[m][j+2] * A[l][j+1])) );   
    }
    return sum;
}












        //int p=pow(-1,i+j);
        // p need to be ignore here(i=1), due to opposite pattern in this case
        //printf("%d",p);
        
        //printf ("\ni= %d, , m=%d, l=%d , \n", i,m,l);
        //printf("\narr: %d ",   ( (  A[i][j] ) * ( (A[m][j+1] * A[l][j+2] )  - (A[m][j+2] * A[l][j+1])) )  );