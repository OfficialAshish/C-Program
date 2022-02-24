#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int tn;
    printf("Enter no. of strings: ");
    scanf("%d",&tn);
    char *name[tn];
    char n[50];
    int len,i;
    char *p;
    for (i=0;i<tn;i++)
    {
        printf("Enter name : ");
        scanf("%s",n);
        len=strlen(n);
        p=malloc((len+1));
        strcpy(p,n);
        name[i]=p;
    }
    for (i=0;i<tn;i++)
    {
        printf("Address: %u , Value: %s \n",*(name+i),*(name+i));
    }
    free(p);
    return 0;

}