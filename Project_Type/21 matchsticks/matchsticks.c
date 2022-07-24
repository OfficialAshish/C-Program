#include <stdio.h>
int main(){
    
    int user,syst,sum;
    sum=0;
    syst=0;
    printf("\nThere are total 25 Matchsticks,\nYou can choose (1-10) at first, then only (1) \n");

    //lets begin play
    while(sum<25){
        printf("\nYour choise:\t");
        scanf("%d",&user);
        if(sum>=25){
            printf("\nYou won!");
            return 0;
        }
        if(user>10 || user<1 ){
            printf("\nNot Allowed Value\n");
            return 0;//terminate
        }
        else if (user>1 && user<=10 && sum<=15){
            if(sum>=25){
                printf("\nYou won!");
                return 0;
            }
            if (user%2==0){
                syst=3;
                printf("System choise is %d\n",syst);
                //syst+=3;
                sum=sum+user+syst;
                if((25-sum)>0){
                    printf("\nRemaining matchsticks are %d\n",25-sum);
                }
                else printf("\nRemaining matchsticks are 0");
                
                if(sum>=25){
                    printf("\n System won!\n");
                    return 0;
                }
            }
            else {
                syst=4;
                printf("\nSystem choise is %d\n",syst);
                //syst+=syst;
                sum=sum+user+syst;
                if((25-sum)>0){
                    printf("\nRemaining matchsticks are %d\n",25-sum);
                }
                else printf("\nRemaining matchsticks are 0");
                
                if(sum>=25){
                    printf("\n System won!");
                    return 0;
                }
                
            }
        }
        else if(user==1){
            syst=1;
            printf("System choise is %d\n",syst);
            sum=sum+syst+user;
            if((25-sum)>0){
                printf("\nRemaining matchsticks are %d\n",25-sum);
            }
            else printf("\nRemaining matchsticks are 0");

            if(sum>=25){
                printf("\n System won!");
                return 0;
            }
        }

    
    fflush(stdin);
    }

    return 0;
}

