//wrong way to add, by recopying old one to new list & then inserting,so,solution is linked list


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list=malloc(3*sizeof(int));

    if (list==NULL)
    {
        free(list);
        return 1;
    }
    *list = 10;
    *(list+1) = 20;
    *(list+2) = 30;

/*     for (int i =0; i<3; i++)
    {
        printf("List[%d]: %d \n",i,*(list+i));
    } */

    int *temp;
    temp=(int *) malloc(5*sizeof(int));
     
     if (temp==NULL)
     {
         free(temp);
         return 1;
     }
     for (int a=0; a<3;a++)
     {
         *(temp+a)=*(list+a);
     }
     temp[3]=40;
     temp[4]=50;
     free(list);
    for (int i =0; i<5; i++)
    {
        printf("List[%d]: %d \n",i,*(temp+i));
    }
    free(temp);
    return 0;
}