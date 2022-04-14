#include <stdio.h>
#include <string.h>
//#include<stdlib.h>
#define SIZE1 20
#define SIZE2 20

int xstrcmp(char *, char *);

int main()
{
    char str1[SIZE1];
    char str2[SIZE2];

    printf("\nEnter string 1 : ");
    scanf("%[\n]s ", str1);
    fflush(stdin);
    printf("\nEnter string 2 : ");
    scanf("%[\n]s ", str2);
    int res = xstrcmp(str1, str2);
    if (res == 0)
    {
        printf("Strings are identical .");
    }
    else
        printf("Strings are not identical . %d", res);

    return 0;
}

int xstrcmp(char *s1 , char *s2 )
{
    int i=0 ;
    while ( *(s1++ ) == *(s2++) )
    {
        printf("%c",*(s1+i));
        if (*(s1+i) == "\0" )
        {
            return 0;
        }
        i++;
    }
    return ( (*(s1+i ) ) - (*( s2+i )) );
}





























    /*
    
    int i=0;
    while ( *(s1 + i) != '\0' )
    {
        printf("\n%s , ", *(s1+i));
        int sub = (*(s1 + i) - *(s2 + i));
        printf("\n %d , \n",sub);
        if (sub == 0)
        {
            sub=0;
        }
        else
        {
            return sub;
        }
        i++;
    }
    return 0;
}

*/