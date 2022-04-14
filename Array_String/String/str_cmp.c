#include <stdio.h>
//#include<string.h>
//#include<stdlib.h>
#define SIZE1 40
#define SIZE2 40

int xstrcmp(const char *,const char *);

int main()
{
    char str1[SIZE1];
    char str2[SIZE2];

    printf("\nEnter string 1 : ");
    scanf("%[^\n]s ", str1);
    fflush(stdin);
    printf("\nEnter string 2 : ");
    scanf("%[^\n]s ", str2);
    
    //printf("\n str1 : %s\n ", str1);
    int res = xstrcmp(str1, str2);
    
    //printf("\n str2 : %s\n ", str2);
    if (res == 0)
    {
        printf("Strings are identical .");
    }
    else
        printf("Strings are not identical . %d", res);

    return 0;
}

int xstrcmp(const char *s1 , const char *s2 )
{
    int i=0 ;
    //printf("\n%s\n", s1);
    int res = (*(s1) ) - (*( s2 ));
    //printf("\n%d\n",res);
    while ( res==0 )
    {
        //printf("\nins : %d\n",res);
        //printf("\n Str1: %s\n",s1);
        //printf("\n lens1: %d\n", strlen(s1));
        if (*(s1) == '\0' )
        {
            return res ;
        }
        res = (*(++s1) ) - (*( ++s2 ));
    }
    
    return ( res );
}



/*
error made in this prgm

"/0" --> '\0'
[\n]s  -->  [^\n]s
 
 
 */