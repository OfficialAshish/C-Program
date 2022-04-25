#include <stdio.h>

bool verifycc(int *cc ) ;

int main()
{
    int cc[16] ;
    
    printf("\nEnter Credit card no. (with space between each no. ) : ");
    
    for (int i=0 ; i<16 ; i++)
    {
        scanf("%d",(cc+i));
    }
    bool res=verifycc(cc);
    
    if (res == true)
    {
        printf("\nIt is valid Credit Card! ");
    }
    else printf("\nIt is not valid Credit Card! ");
    
    return 0;
}


bool verifycc( int *cc )
{
    int ev=0,od=0;
    for (int i=1 ; i<16 ; i+=2)
    {
        od = od + *( cc +i) ;
    }
    
    for (int i=0 ; i <16 ; i+=2)
    {
        int a2=0 ;
        a2 = *(cc + i) *2 ;
        if (a2 > 9 )
        {
            a2=a2-9;
        }        
        ev += a2 ;
        
    }
    if (( ev + od )%10 == 0 )
    {
        return true;
    }
    else return false;
}