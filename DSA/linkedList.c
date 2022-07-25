#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

typedef struct linkedList
{
    char str[SIZE];
    struct linkedList *node;
} linkedList;

// init
linkedList *ll1;

int main()
{
    char *p1 ;
    p1 = (char *)malloc(20);
    if (!p1)
    {
        printf("ER");
        return 1;
    }
    
    scanf("%s", p1);
    printf("%s", p1);

    strcpy(ll1->str, p1);
    ll1->node = NULL;
    printf("%s", ll1->str);
    free(p1);
    return 0;
}
