#include <stdio.h>
int checkLeapYear(int);

    //fucntion to check leap year sas checkLeapYear

    int checkLeapYear(int i)
    {
        if ((i%100==0 && i%400==0 && i!=0) || (i%100!=0 && i%4==0)){
            return 1;
        }
        else return 0;
    }
    
    

int main(){

    int mm,dd,yy;
    printf("Enter date in dd mm yy format:\t");
    scanf("%d%d%d",&dd,&mm,&yy);


    int leapYear,counter;
    counter=0;
    leapYear=0;

    while(counter<yy){
        if(checkLeapYear(counter)==1){
            leapYear+=1;
            //printf("%d\n\t",counter);
            //printf("first%d\n\t",leapYear);
        }
        counter+=4;
    }
    //printf("final%d\n\t",leapYear);
    
    /**/
    
    //total previous_years days as (tpd)
    long tpd;

    //days in current year as (cyd)
    int cyd;
    cyd=0;

    //total final days tillnow as (tfd)
    long tfd;

    tpd=((yy-1)*365)+leapYear;


    //terminate program for these four invalid cases;
    if (dd>29 && mm==2){
        printf("February cannot have more then 29 day\'s\n");
        return 0;
        //terminate program
    }
    else if (dd==29 && mm==2 && checkLeapYear(yy)==0){
        printf("%d is not a leap year.\n",yy);
        return 0;
        //terminate program
    }
    else if ( mm>12){
        if (mm>12){
            printf("Month cannot be greater then 12\n");
            return 0;
            //terminate program
            }
        if(dd>31){
            printf("Date cannot be greater then 31\n");
            return 0;
            //terminate program
        }
    }
    else if(mm==1 && dd<=31){
        cyd=cyd+dd;
    }
    else if(mm==2 && dd<=28){
        cyd=31;
        cyd=cyd+dd;
    }
    else if(mm==3 && dd<=31){
        cyd=59;//sum of jan& feb
        cyd=cyd+dd;
    }
    else if(mm==4 && dd<=30){
        cyd=90;//sum of jan& feb& mar
        cyd=cyd+dd;
    }
    else if(mm==5 && dd<=31){
        cyd=120;
        cyd=cyd+dd;
    }
    else if(mm==6 && dd<=30){
        cyd=151;
        cyd=cyd+dd;
    }
    else if(mm==7 && dd<=31){
        cyd=181;
        cyd=cyd+dd;
    }
    else if(mm==8 && dd<=31){
        cyd=212;
        cyd=cyd+dd;
    }
    else if(mm==9 && dd<=30){
        cyd=243;
        cyd=cyd+dd;
    }
    else if(mm==10 && dd<=31){
        cyd=273;
        cyd=cyd+dd;
    }
    else if(mm==11 && dd<=30){
        cyd=304;
        cyd=cyd+dd;
    }
    else if(mm==12 && dd<=31){
        cyd=334;
        cyd=cyd+dd;
    }
    
    //total days
    tfd=tpd+cyd;
    //printf("\n%ld",tfd);

    //if current year is leap 
    if(checkLeapYear(yy)==1 && mm>2 ){
        tfd+=1;
    }
    else if (dd==29 && mm==2){
        tfd+=1;
    }
    
    //printf("\nTotal days till now:\t%ld\n",tfd);

    //getting day now
    int day;
    day=tfd%7 ;

    printf("\n");
    switch (day){
        case 0:{
            printf("It is Sunday\n");
            break;
        }
        case 1:{
            printf("It is Monday\n");
            break;
        }
        case 2:{
            printf("It is Tuesday\n");
            break;
        }
        case 3:{
            printf("It is Wednesday\n");
            break;
        }
        case 4:{
            printf("It is Thursday\n");
            break;
        }
        case 5:{
            printf("It is Friday\n");
            break;
        }
        case 6:{
            printf("It is Saturday\n");
            break;
        default :{
            printf("Not a valid Day\n");
        }
        }

    }

    return 0;
}


    /*
    while(c<yy){
        if(c%100!=0 && c%4==0){
            leapYear+=1;
            printf("%d\n\t",c);
            printf("first%d\n\t",leapYear);
        }
        else if(c%100==0 && c%400==0 && c!=0){
            leapYear+=1;
            printf("century%d\n",c);

        }
        c+=4;
    }
    printf("final%d\n\t",leapYear);
     


    int invalidDate=0;

    if (invalidDate==1){
        again:{
            int mm,dd,yy;
            printf("Enter date in dd mm yy format:\t");
            scanf("%d%d%d",&dd,&mm,&yy);
        }
    }

            invalidDate=1;
            goto again;
    */
    