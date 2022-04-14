#include <stdio.h>
#include <string.h>
void xstrcat(char *t,char *s);
int main()
{
    char sstr[20] ;
    char tstr[40] ;
    printf("Enter sstr : ");
    scanf("%[^\n]s",sstr);
    fflush(stdin);
    
    printf("\nEnter tstr : ");
    scanf("%[^\n]s",tstr);
    xstrcat(tstr,sstr);
    printf("Concated string is : %s",tstr);
    //printf("%s,,,%s",sstr,tstr);
    return 0;
}

void xstrcat(char *t , char *s)
{
    t= (t + strlen(t));
    while ( *s != '\0')
    {
        *t = *s;
        t++;
        s++;
    }
    *t = '\0';
}
        