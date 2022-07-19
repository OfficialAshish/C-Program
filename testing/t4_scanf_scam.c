#include <stdio.h>
#include <string.h>

int main()
{
    int x,y;

    
    char a, b, c;

    char arr[6];

    printf("entrt arr:");
    scanf("%s", arr);
    // gets(arr);
    fflush(stdin);
    fflush(stdin);

    printf("entrt a:");
    // scanf("%c", &a);
    // fflush(stdin);

    a=getchar();
    printf("entrt b:");
    scanf("%c", &b);

    printf("entrt c:");
    scanf("%c", &c);

    printf("\nchar.. , arr: %s ,%d ,a=%c ,%d , , b: %c, %d, c: %c, %d,  \n", arr, strlen(arr), a, a, b, b, c, c);
    
    
    
    printf("entrt x:");
    scanf("%d", &x);

    printf("entrt y:");
    scanf("%d", &y);

    printf("\n integers x : %d , y: %d \n" , x,y);

    
    
    
    
    
    
    
    
    return 0;
}
