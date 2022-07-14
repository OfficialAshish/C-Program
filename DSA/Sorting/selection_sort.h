
void swap(int *, int *);
void selsort(int *, int , ...);


void selsort(int *numPoint, int LEN , ...)
{
    int cond=0;
    for (int j = 0; j < LEN - 1; j++)
    {
        for (int i = j + 1; i < LEN; i++)
        {
            if (*(numPoint + i) < (*(numPoint+j)))
            {
                swap((numPoint + i), (numPoint + j));
                
                //printf("\nswapping:- (max)= %d , (min) = %d ; at i =%d , j= %d \n" , *(numPoint + i) , *(numPoint + j), i, j);   
            }
        }
        //to print all sorting steps
        if (cond==1)
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


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
