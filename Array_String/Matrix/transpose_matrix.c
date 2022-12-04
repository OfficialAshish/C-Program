#include <stdio.h>
#include <stdlib.h>

int *transpose();

int main()
{
    int a, b;
    printf("\nEnter rows and coloums  of A matrix : ");
    scanf("%d", &a);
    scanf("%d", &b);

    int ma[a][b];

    for (int i = 0; i < a; i++)
    {
        printf("\nEnter Row %d : ", (i + 1));
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &ma[i][j]);
        }
    }
    printf("\nOriginal Matrix :");
    for (int i = 0; i < a; i++)
    {
        printf("\n");
        for (int j = 0; j < b; j++)
        {
            printf(" %d, ", ma[i][j]);
        }
        printf("\n");
    }

    /*
    int *mt=transpose(ma[a][b],a,b);

     for (int i=0 ; i<b ; i++)
    {
        for (int j=0 ; j<a ; j++)
        {
            printf("%d, ",mt[i][j]);
        }
        printf("\n");
    }
    */

    printf("\nTranspose of above Matrix :");
    int *mt[] = transpose(ma[a][b], a, b);
    for (int i = 0; i < b; i++)
    {
        printf("\n");
        for (int j = 0; j < a; j++)
        {
            printf(" %d, ", (*(mt + i) + j));
        }
        printf("\n");
    }
    free(mt);
    return 0;
}

int *transpose(int *ma, int r, int c)
{

    static int mt[3][3];
    /*
    int *mt=malloc(r*c);
    */
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            /*
            mt[i][j] = ma[j][i] ;
            */
            (*(mt + j * r + i)) = *(ma + c * i + j);
            /**/
        }
    }
    return mt;
}
/*
void transpose(int mt[][3] , int r, int c)
{
    for (int i=0 ; i<r ; i++)
    {
        int *temp;
        for (int j=0 ; j<c ; j++)
        {

            temp=(*(*(p+i) + j));
            *(*(p+i)+j)= *(*(p+j)+i);
            *(*(p+j)+i)= temp;



            temp=&mt[i][j] ;
            mt[i][j]= mt[j][i] ;
            mt[j][i]= temp ;

        }
    }
}
*/