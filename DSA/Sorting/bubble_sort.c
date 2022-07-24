
#include <stdio.h>
#define ARRSIZE 12
void swap(int *, int *);
void bubbleSort(int *, int, ...);

int main()
{
    int arr[] = {7, 2, 1, 4, 8, 5, 9, 0, 7, 5, 3, 3};
    bubbleSort(arr, ARRSIZE, 1); // 1 is optional arg

    // printing sorted arr
    printf("\n Final :\n   {");
    for (int i = 0; i < ARRSIZE; i++)
    {
        printf(" %d , ", arr[i]);
    }
    printf("  }\n");

    return 0;
}

void bubbleSort(int *numPoint, int LEN, ...)
{
    int cond = 0;
    for (int j = 0; j < LEN - 1; j++)
    {
        for (int i = j + 1; i < LEN; i++)
        {
            if (*(numPoint + i) < (*(numPoint + j)))
            {
                swap((numPoint + i), (numPoint + j));

                // printf("\nswapping:- (max)= %d , (min) = %d ; at i =%d , j= %d \n" , *(numPoint + i) , *(numPoint + j), i, j);
            }
        }
        // to print all sorting steps
        if (cond == 1)
        {
            printf("\n {{");
            for (int k = 0; k < LEN; k++)
            {
                printf(" %d ,", *(numPoint + k));
            }
            printf("  }}\n");
        }
    }
}
/**/

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
//ALTERNATIVE (Detailed)
void bubbleSort(int *numPoint, int LEN ,...)
{
    int cond=0;
    for (int j = 0; j < LEN - 1; j++)
    {
        int *minum = (numPoint + j);
        for (int i = j + 1; i < LEN; i++)
        {
            if (*(numPoint + i) < (*(minum)))
            {
                minum = (numPoint + i);

                //printf("\nswapping:- minum= %d , (numPoint+j) = %d ; at i =%d , j= %d " , *(minum) , *(numPoint + j), i, j);

            }
        }
        swap((numPoint + j), minum);
        if(cond==1)
        {
        printf("\n {{");
        for (int k = 0; k < ARRSIZE; k++)
        {
            printf(" %d ,", *(numPoint + k));
        }
        printf("  }}\n");
        }
    }
}

*/
