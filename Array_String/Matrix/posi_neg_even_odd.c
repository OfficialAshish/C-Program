#include <stdio.h>
int pos();
int neg();
void even_odd();
void prime();
int even, odd;

int main()
{
    int n;
    printf("Enter Total Numbers : ");
    scanf("%d", &n);
    int num[n];
    printf("\nEnter numbers : ");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        scanf("%d", (num + i));
    }

    printf("Array is [ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", *(num + i));
    }
    printf("]");

    printf("\nTotal positive numbers are %d .", pos(num, n));
    printf("\nTotal negative numbers are %d .", neg(num, n));
    even_odd(num, n);
    printf("\nTotal even numbers are %d .", even);
    printf("\nTotal odd numbers are %d .", odd);
    printf("\n Prime numbers are . ");
    prime(num,n);

    return 0;
}

int pos(int *p, int n)
{
    int c = 0;
    for (int m, i = 0; i < n; i++)
    {
        m = *(p + i);
        if (m >= 0)
        {
            c++;
        }
    }
    return c;
}
int neg(int *p, int n)
{
    int c = 0;
    for (int m, i = 0; i < n; i++)
    {
        m = *(p + i);
        if (m < 0)
        {
            c++;
        }
    }
    return c;
}
void even_odd(int *p, int n)
{
    /*extern int even, odd; */
    for (int m, i = 0; i < n; i++)
    {
        m = *(p + i);
        if (m % 2 == 0)
        {
            even++;
        }
        else
            odd++;
    }
}

void prime(int *p, int n)
{
    printf("\n [ ");
    for (int i = 0; i < n; i++)
    {
        int new;
        if ((*(p+i)) <0)
        {
            new= (-1)*(*(p+i));
        }
        else new= (*(p+i));
        for (int j = 1; j < new; j++)
        {
            if (new % j == 0)
            {
                break;
            }
            else if (j < new)
            {
                printf("%d, ", *(p + i));
            }
        }
    }
    printf(" ] \n");
}
