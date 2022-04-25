#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPSIZE 0
//#define ARRSIZE 10

void *getString();

int arrsize = 0;
//init Array (ARRSIZE)
char *arr[];

int main()
{
    //char *getAr;
    getString();

    //printing array
    printf("   {");
    for (int i = 0; i < arrsize + 1; i++)
    {
        //printf("\n elem %d : %s", i, *(arr+i));
        printf("\n      %s  ,", *(arr + i));
        if (i + 1 == arrsize)
        {
            break;
        }
    }
    printf(" \n   }");

    return 0;
}

void *getString()
{
    char inp = 'y';
    int i = 0, n = INPSIZE;
    if (n == 0)
    {
        printf("Enter, how many names you want to insert in array : ");
        scanf("%d", &n);
        fflush(stdin);
    }
    char *p;
    while (inp == 'y' && i < n)
    {
        char temp[50];
        printf("\nEnter name : ");
        arrsize++;
        scanf("%[^\n]s", temp);
        fflush(stdin);
        p = (char *)malloc(strlen(temp + 1));
        strcpy(p, temp);
        //printf("\n%s", p);
        arr[arrsize - 1] = p;
        //free(p);

        if (i + 1 == n)
        {
            printf("\nWant to enter another name : (y/n ) : ");

            scanf("%c", &inp);
            fflush(stdin);
            if (inp != 'y')
            {
                break;
            }
            i = -1;
            printf("Enter, how many names you want to insert in array : ");
            scanf("%d", &n);
            fflush(stdin);
        }
        i++;
    }
    free(p);
}