#include <stdio.h>
#include <math.h>

bool checksum(long int *);

int main()
{
    long int num[1];
    printf("Enter 10 digit number (0-9,) : ");
    scanf("%ld",num);
    
    bool res=checksum(num);
    
    if (res == true)
    {
        printf("\nISBN number is correct !\n");
    }
    else printf("\nISBN number isn\'t correct !\n") ;
    
    return 0;
}

bool checksum( long int *cs)
{
    int i=10, dig, sum=0;
    
    
        for (long int j=10  ;( j<=pow(10,10) && (i>0) ) ; j*=10,i--)
        {
            dig = (( *cs % j ) - ( *cs % (j/10) )) / (j/10) ;
            printf("\ndig: %d",dig);
            
            sum += i*dig ;
            
        }
    
    if (sum % 11 == 0)
    {
        return true;
    }
    else return false;
}
        