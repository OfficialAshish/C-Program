#include <stdio.h>
void add(int A[][3], int B[][3], int C[][3]);
int main()
{
    int r, c;
    printf("\nEnter No. of Rows & column: ");
    scanf("%d %d", &r, &c);
    int A[r][c], B[r][c], C[r][c];

    printf("Enter Matrix A");
    
    for (int i = 0; i < r; i++)
    {
        printf("\nEnter Row %d: \n", i + 1);
        for (int j = 0; j < c; j++)
        {
            scanf("%d", (*(A + i) + j));
        }
        printf("\n");
    }
    
    printf("Enter Matrix B");
    for (int i = 0; i < r; i++)
    {
        printf("\nEnter Row %d: \n", i + 1);
        for (int j = 0; j < c; j++)
        {
            scanf("%d", (*(B+ i) + j));
        }
        printf("\n");
    }

    add(A, B, C);
    
    printf("\n\nMatrix A :");
    for (int i = 0; i < r; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {
            printf(" \t%d, ", A[i][j]);
        }
    }
    
    printf("\n\nMatrix B :");
    for (int i = 0; i < r; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {
            printf(" \t%d, ", B[i][j]);
        }
    }
    printf("\n\nMatrix C=(A+B)");
    for (int i = 0; i < r; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {
            printf(" \t%d, ", C[i][j]);
        }
    }

    return 0;
}

void add(int A[][3], int B[][3], C[][3])
{
    int r = 3, c = 3;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}