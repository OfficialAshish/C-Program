#include <stdio.h>
#include <math.h>
bool verifycc(long int *cc ) ;

int main()
{
    long int cclong[1] ;
    
    printf("\nEnter Credit card no. : ");
    
    scanf("%ld" , &cclong[0] );
    //printf("\n no:%ld " , cclong[0]);
    
    bool res=verifycc(cclong);
    
    if (res == true)
    {
        printf("\nIt is valid Credit Card! ");
    }
    else printf("\nIt is not valid Credit Card! ");
    
    return 0;
}


bool verifycc(long int *cc )
{
    int ev=0,od=0 , m,n ;
    
    for (long int i=10 ; i <= pow(10,16) ; i = i*100)
    {
        n =( ( *(cc) % i ) - ( *cc % (i/10)) ) / (i/10);
        od = od + n ;
        //printf("\n odd:%d" , n);
    }
    
     for (long int i=100 ; i <= pow(10,16) ; i = i*100)
    {
        m =( ( *(cc) % i ) - ( *cc % (i/10)) ) / (i/10);
        
        //printf("\n even: %d" , m);
        int a2=0 ;
        a2 = m *2 ;
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