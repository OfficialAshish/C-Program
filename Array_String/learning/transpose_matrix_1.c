#include <stdio.h>

#define R 3
#define C 3

void transpose(int om[][C], int nm[][R]);

int main()
{
    /*
    printf("\nEnter rows and coloums  of A matrix : ");
    scanf("%d", &R);
    scanf("%d", &C);
    */

    int om[R][C];
    int nm[C][R];

    for (int i = 0; i < R; i++)
    {
        printf("\nEnter Row %d : ", (i + 1));
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &om[i][j]);
        }
    }
    printf("\nOriginal Matrix :");
    for (int i = 0; i < R; i++)
    {
        printf("\n");
        for (int j = 0; j < C; j++)
        {
            printf(" %d, ", om[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose of above Matrix :");

    transpose(om, nm);
    for (int i = 0; i < C; i++)
    {
        printf("\n");
        for (int j = 0; j < R; j++)
        {
            printf(" %d, ", nm[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void transpose(int om[R][C], int nm[C][R])
{
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            nm[i][j] = om[j][i];
        }
    }
}
