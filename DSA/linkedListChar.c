#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

node *memoAlloc();


int main()
{
    node *list =NULL;//1D list for struct node type values(pointers)
    // scanf("%d", list->num);
    // printf("%d", *list);

    node *pNode = NULL;

    pNode = memoAlloc();
    pNode->num = 2;
    pNode->next = NULL;
    list = pNode;

    pNode = memoAlloc();
    pNode->num = 3;
    pNode->next = NULL;
    list->next=pNode;




    printf("%d", list->num);
    while (list != NULL)
    {
        node *tmp =list;
        free(list);
        list = tmp->next;
    }
    return 0;
}

node *memoAlloc()
{
    node *pll;
    pll = (node *)malloc(sizeof(node));
    if (!pll)
    {
        printf("Unable to allocate memory \n");
        free(pll);
        exit(1);
    }
    return pll;
}
