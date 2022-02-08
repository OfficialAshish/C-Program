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

/*  int *temp;
    temp=(int *) realloc(list,5*sizeof(int));
 */
    int *temp=realloc(list,5*sizeof(int));
     
    if (temp==NULL)
    {
        free(temp);
        return 1;
    }
     //printf("%d\n",*(temp+1));

     //inserting

    temp[3]=40;
    temp[4]=50;

    //if free isnt comment index 0,1 are giving address
    //free(list);
    for (int j =0; j<5; j++)
    {
        printf("List[%d]: %d \n",j, *(temp+j));
        //printf("\t\tSomething diff.List[%d]: %d \n",*(temp+j));
    }
    free(list);
    free(temp);
    return 0;
}