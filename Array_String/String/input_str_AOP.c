#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPSIZE 3
#define ARRSIZE 1

void *getString();

int arrsize = 0;
//init Array (ARRSIZE)
char *arr[ARRSIZE];  //size doesnt matters

int main()
{
    //char *getAr;
    getString();

    //printing array
    printf("   {");
    for (int i = 0; i < arrsize; i++)
    {
        //printf("\n elem %d : %s", i, *(arr+i));
        printf("\n Name - %d : %s  ,", i + 1, *(arr + i));
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
    }
    char *p;
    while (inp == 'y' && i < n)
    {
        char temp[50];
        printf("\nEnter name : ");
        arrsize++;
        // scanf("%[^\n]s", temp);
        // fflush(stdin);
        gets(temp);
        p = (char *)malloc(strlen(temp + 1));
        strcpy(p, temp);
        //printf("\n%s", p);
        arr[arrsize - 1] = p;

        if (i + 1 == n)
        {
            printf("\nWant to enter another name : (y/n ) : ");

            // scanf("%c", &inp);
            inp = getchar();
            // fflush(stdin);
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
    
}