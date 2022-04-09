#include <stdio.h>
int pos();
int neg();
void even_odd();

int main()
{
    int n;
    printf("Enter Total Numbers : ");
    scanf("%d",&n);
    int num[n];
    printf("\nEnter numbers : ");
    for (int i=0 ; i<n ; i++)
    {
        printf("\n");
        scanf("%d",(num+i));
    }

    printf("Array is [ ");
    for (int i=0 ; i<n; i++)
    {
        printf("%d, ",*(num+i));
    }
    printf("]");

    printf("Total positive numbers are %d .",pos(num,n));
    printf("\nTotal negative numbers are %d .",neg(num,n));
    even_odd(num,n);
    printf("\nTotal even numbers are %d .", even);
    printf("\nTotal odd numbers are %d .", odd);
    
    int pos(int *p, int n)
    {
        for (int m,c=0, i=0; i<n ;i++)
        {
            m=*(p+i);
            if (m >= 0)
            {
                c++;
            }
        }
        return c;
    }
    int neg(int *p, int n)
    {
        for (int m,c=0, i=0; i<n ;i++)
        {
            m=*(p+i);
            if (m < 0)
            {
                c++;
            }
        }
        return c;
    }
    void even_odd(int *p, int n)
    {
        static int even,odd;
        for (int m,i=0; i<n ; i++)
        {
            m=*(p+i);
            if (m % 2==0)
            {
                even++;
            }
            else odd++;
        }
    }


    return 0;
    
}