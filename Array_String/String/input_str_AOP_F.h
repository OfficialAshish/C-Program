
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 2
#define ARRSIZE 4

char **getString();
int arrsize = 0;

//init Array (ARRSIZE)
//char *arr[ARRSIZE];

/*

int main()
{
    char **getAr;
    getAr = getString();
    if (getAr == NULL)
        exit(1);
    //printing array, ((not working))

    
    printf("   {");
    for (int i = 0; i < arrsize; i++)
    {
        printf("\n Name %d : %s", i+1, *(getAr + i));
    }
    printf(" \n   }");
    
    return 0;
}

*/

char **getString()
{
    char another = 'y';
    static char *arr[ARRSIZE];
    int i = 0, n = SIZE;
    if (n == 0)
    {
        printf("Enter, how many names you want to insert in array : ");
        scanf("%d", &n);
        fflush(stdin);
    }
    char *p;
    while (another == 'y' && i < n)
    {
        char temp[40];
        printf("\nEnter name : ");
        arrsize++;
        // scanf("%[^\n]s", temp);
        // fflush(stdin);
        gets(temp);
        p = (char *)malloc(strlen(temp + 1));
        strcpy(p, temp);
        printf("\np:%d\n", strlen(p));
        arr[arrsize - 1] = p;
        if (i + 1 == n)
        {
            printf("\nWant to enter another name : (y/n ) : ");
            // scanf("%c", &another);
            another = getchar();
            // fflush(stdin);
            if (another != 'y')
            {
                break;
            }
            i = -1; //in ending while i++, i gets its index =0; for next repeatation
            printf("Enter, how many names you want to insert in array : ");
            scanf("%d", &n);
            // fflush(stdin);
        }
        i++;
    }
    /*
    //printing array
    printf("   {");
    for (int i = 0; i < arrsize; i++)
    {
        printf("\n Name %d : %s", i, *(arr + i));
    }
    printf(" \n   }");
    */
    return arr;
}