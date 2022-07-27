#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

typedef struct node
{
    char str[SIZE];
    struct node *next;
} node;


int main()
{
    node *strList = NULL;
    node *nextStr ;
    nextStr = (node *)malloc(SIZE);
    if (!nextStr)
    {
        printf("MEMO ERR!");
        return 1;
    }

    

    return 0;
}
