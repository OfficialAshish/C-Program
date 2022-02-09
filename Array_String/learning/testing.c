#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s={"hello"};
    char str[]={"hello"};

    //*s="s";
    printf("%s\n",&s[0]);
    //str[2]="";
    printf("%s\n",str);
}

