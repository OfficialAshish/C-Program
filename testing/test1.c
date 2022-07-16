#include <stdio.h>
//#define SIZE 5

int main()
{
    int n,temp;
    printf("\nEnter number of digits in array (n): ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d ,digits : ", n);
    for(int i=0; i<n ; i++)
    {
        scanf("%d",&temp);
        arr[i]=temp;
    }
    fflush(stdin);
    int size;
    size = sizeof(arr)/sizeof(arr[0]);
    printf("\nSize %d ", size);
    return 0;
}

