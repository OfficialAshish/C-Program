#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    typedef struct node
    {
        int number;
        struct node *next;
    }
    node;
    
    node *linkedList=NULL;

    node *n=malloc(sizeof(node));

    if(n==NULL){
        free(n);
        return 1;
    }

    (*n).number=10;
    (*n).next=NULL;
    linkedList=n;

    n=malloc(sizeof(node));
    (*n).number=20;
    (*n).next=NULL;
    //linkedList->next->next=n;//*(*linkedList.next).next

/* 
    for (node *i=linkedList; i->next!=NULL; i=i->next)
    {
        printf("%d",i->number);
    }
 */
    printf("%d\n",linkedList  -> number);
    
    while(linkedList!=NULL)
    {
        node *tmp = linkedList->next;
        free(linkedList);
        linkedList=tmp;
    }
    free(linkedList);
    free(n);
    return 0;



}

//**((*linkedList.next).number