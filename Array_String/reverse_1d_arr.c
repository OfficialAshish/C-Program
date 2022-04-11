#include <stdio.h>
#define SIZE 5
int main()
{
    int p[SIZE] ;
    printf("\nEnter %d numbers : \n", SIZE);
    
    for (int i=0 ; i<SIZE ; i++)
    {
        scanf("%d", (p+i));
    }
    
    //printing original array
    printf("\n[ ");
    for (int i=0 ; i<SIZE; i++)
    {
        printf("  %d, ",*(p+i));
    }
    printf(" ]");
    
    //printing reverse array
    
    printf("\n\nReverse of above array is:\n[ ");
    for (int i=0 ; i<SIZE; i++)
    {
        printf("  %d, ",*(p+(SIZE-1-i)));
    }
    printf(" ]");
    
    return 0;
}