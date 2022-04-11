#include <stdio.h>
int main()
{
    int j=2, num,i;
    printf("Enter num");
    scanf("%d", &num);

    for (j = 2; j <= num; j++)
    {
        for (i = 2; i <= j / 2; i++)
        {
            if (j % i == 0)
            {
                break;
            }
        }
        if (i>j/2)
        {
            printf("%d ,",j );
        }
    }

    return 0;
}