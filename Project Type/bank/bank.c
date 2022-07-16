#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma pack(1) // default

#define TOTALCUSTOMER (3 + 97)
// prototypes
int registerUser();
int accountDetail();
int forgotAccountNumber();
int modifyAccout();
int depositAmount();
int withdrawAmount();
int exitBank();

int getAccount();
int accountNumber(int);
// char getString();//for multistring(full_name)
//  void createTestAccount(int);
int searchAccount_binary(int *, int, int);
int searchAccount_linear(int *, int, int);

// structure for customers accounts
typedef struct bankCustomer
{
    char acntName[20];
    unsigned int acntNumber;
    int acntBalance;

} bca;

// global declaration
bca customer[TOTALCUSTOMER];
static unsigned int accountIndex;
int option = 100;

int main()
{

    // default 3 customers
    strcpy(customer[0].acntName, "Ashish Prajapati");
    customer[0].acntNumber = accountNumber(0);
    customer[0].acntBalance = 100.0;

    strcpy(customer[1].acntName, "Abhi Dev");
    customer[1].acntNumber = accountNumber(1);
    customer[1].acntBalance = 100.0;

    strcpy(customer[2].acntName, "Hritunjay");
    customer[2].acntNumber = accountNumber(2);
    customer[2].acntBalance = 100.0;

    // restart:
    do
    {
        if (option == 100)
        {
            printf("\n\nWelcome To Our BANK !\n");
            printf("\n 1 : Register User. \n\n 2 : Modify Account. \n\n 3 : Account Detail. \n\n 4 : Deposit Amount. \n\n 5 : Withdraw Amount. \n\n 6 : Forgot Account Number, Reset!. \n\n 7 : Exit.\n");
        }
        printf("\nSelect Option : ");

        scanf("%d", &option);

        fflush(stdin);

        {
            if (option == 1)
                option = registerUser();

            else if (option == 2)
                option = modifyAccout();

            else if (option == 3)
                option = accountDetail();

            else if (option == 4)
                option = depositAmount();

            else if (option == 5)
                option = withdrawAmount();

            else if (option == 6)
                option = forgotAccountNumber();

            else if (option == 7)
                option = exitBank();
            
            else
            {
                printf("%d, Wrong Option Selected! \n", option);
                fflush(stdin);
            }
        }
    } while (option != (89 || 121)); // 89=Y,121=y

    return 0;

    // [ ERROR! ] printg all execn, after any one execn
    /* switch (option)
    {
    case 1:
        registerUser();
    case 2:
        modifyAccout();
    case 3:
        accountDetail();
    case 4:
        deposit_amnt();
    case 5:
        withdraw_amnt();
    case 6:
        exitBank();
    default:
    {
        printf("Wrong Option Selected! \n");
        goto restart;
    }
    } */
}

// FUNCTIONS
// assigning account number
int accountNumber(int index)
{
    unsigned int assignNum = 6901000 + accountIndex;
    if (index != accountIndex)
    {
        printf("\nSomething wrong with account number assigning!\n");
        return -1;
    }
    else
    {
        accountIndex++; // for next number assignment
        return (assignNum);
    }
}

// get index of account to perform functions,
int getAccount()
{
    printf("\nGetting Account Details...\n");
    char tempName[20];
    int tempAccNum;
    printf("\nEnter Your Name :  ");
    scanf("%s", tempName);
    fflush(stdin);
    printf("\nDear %s , Enter Your Account Number : ", tempName);
    scanf("%d", &tempAccNum);

    int *baseAccount_Num_Add = &(customer[0].acntNumber);

    int index = searchAccount_linear(baseAccount_Num_Add, tempAccNum, accountIndex - 1);

    // printf("\nIndex =%d ,\n", index);

    return (index);
}

// registering new user account
int registerUser()
{
    printf("\nCreating new Account!\n");
    printf("\nEnter Your Name : ");
    char temp[20];
    scanf("%s", temp);
    fflush(stdin);

    int index = accountIndex;
    strcpy(customer[index].acntName, temp);
    customer[index].acntNumber = accountNumber(index);
    customer[index].acntBalance = 100.0;
    printf("\nYEAH! %s, Your Account has been Created! ,\nYour New Account Number is : %d .\n And Curent Balance is : %d. \n", temp, customer[index].acntNumber, customer[index].acntBalance);

    printf("\nEnter anything to continue...");
    // getchar();
    return 100;
}

// check balance
int accountDetail()
{
    // printing default customers
    //  for (int i=0; i<3; i++)
    //  {
    //      printf("\nname=%s , accountNumber=%d , Account Balance = %d, \n", customer[i].acntName, customer[i].acntNumber, customer[i].acntBalance);
    //  }

    printf("\nGet your Account Details.\n");

    int index = getAccount();

    printf("\n\tHello %s, Your Account Number is : %d .\n \tAnd Curent Balance is : %d. \n", customer[index].acntName, customer[index].acntNumber, customer[index].acntBalance);

    printf("\nEnter anything to continue...");
    // getchar();
    return 100;
}

// updating
int modifyAccout()
{
    int index = getAccount();

opt:
    printf("\nWhat you want to modify/update ?\n 1 : Change Name.\n 2 : Remove Your Account.\n 3 : Abort Modification or Exit. \n\nSelect Option : ");
    scanf("%d", &option);
    fflush(stdin);
    if (option == 1)
    {
        printf("\nChanging Account Name!\n");
        printf("\nEnter Your New Name : \n");
        char temp[20];
        scanf("%s", temp);
        fflush(stdin);
        strcpy(customer[index].acntName, temp);
        printf("\nName Changed...\n");
        return 100;
    }
    else if (option == 2)
    {
        // customer[index] = {'\0' , 0, 0};
        strcpy(customer[index].acntName, '\0');
        customer[index].acntNumber = 0;
        customer[index].acntBalance = 0;
        index--;
        accountIndex--;
        return 100;
    }
    else if (option == 3)
        return 100;
    else
    {
        printf("\nWrong option selected...Try again\n");
        goto opt;
    }
}

int depositAmount()
{
    forgotAccountNumber();
    int index = getAccount();
    int deposit;
    printf("\n%s, Enter Amount to Deposit :  ", customer[index].acntName);
    scanf("%d", &deposit);
    fflush(stdin);
    customer[index].acntBalance += deposit;
    printf("\nYour\'s New Account Balance is : %d.\n", customer[index].acntBalance);

    printf("\nEnter anything to continue...");
    // getchar();
    return 100;
}
int withdrawAmount()
{
    int index = getAccount();
    int withdraw;
    printf("\n%s, Enter Amount to Withdraw :  ", customer[index].acntName);
    scanf("%d", &withdraw);
    fflush(stdin);
    customer[index].acntBalance -= withdraw;
    printf("\nYour\'s Current Account Balance is : %d.\n", customer[index].acntBalance);

    printf("\nEnter anything to continue...");
    // getchar();
    return 100;
}

int exitBank()
{

    printf("Are you Sure, Want to Exit (y/n)? ...");
    char exitop[2];

    scanf("%s", exitop);
    fflush(stdin);
    if (strcmp(exitop, "y") == 0 || strcmp(exitop, "Y") == 0)
    {
        printf("\n\t\tGood-Bye!\n\tThank-You For Using Our Bank!\n\n");
        exit(1);
    }
    else
        return 100;
}

int searchAccount_linear(int *bankData, int account_num, int totalAccount)
{
    // bca is available here also,but still doing in another way
    /*
        for (int i = 0,j=0; i < 7*5; i+=7,j++)//i+=7 , bcoz diff in addr of 2 accn_num is 28 bytes and bankdata is simple int pointer of 4bytes so, 4 bytes * 7 == 28 bytes
        {
            printf("\nmodifing add : %u ,acc.no. : %d, i=%d\n" , (bankData+i), *(bankData+i), i);
            printf("\noriginal add : %u ,acc.no. : %d , j=%d\n" , &customer[j].acntNumber , customer[j].acntNumber , j);
        }
         */
    // printf("\ninside linear search...\n");

    for (int i = 0, index = 0; i <= (totalAccount * 28); i += 7, index++) // 7*4bytes==28bytes
    {

        // printf("\nAccount:: add : %u ,acc.no. : %d, i=%d\n", (bankData + i), *(bankData + i), i);

        if (*(bankData + i) == account_num)
        {
            return index;
        }
    }
    return -1;
}

// if forgot Accnt num, reset it;
int forgotAccountNumber()
{
    printf("\nResetting Your Account!\n \tVERIYING...\nEnter your name : ");
    char temp[20];
    scanf("%[^\n]s", temp);
    char *p;
    for (int i = 0; i <= accountIndex; i++)
    {
        p = &customer[i].acntName;
        //printf("\n%s\n", p);
        if (strcmp(p, temp) == 0)
        {
            printf("\nAccount Found! \nAccount No. is : %d ,\n", customer[i].acntNumber);
            return 100;
        }
    }
    printf("\nAccount is not Found!...\n");

    printf("\nEnter anything to continue...");
    // getchar();
    return 100;
}

/*
int searchAccount_binary(int *bankData, int account_num, int totalAccount)
{
    // bca is available here also,but still doing in another way

        // for (int i = 0,j=0; i < 7*5; i+=7,j++)//i+=7 , bcoz diff in addr of 2 accn_num is 28 bytes and bankdata is simple int pointer of 4bytes so, 4 bytes * 7 == 28 bytes
        // {
        //     printf("\nmodifing add : %u ,acc.no. : %d, i=%d\n" , (bankData+i), *(bankData+i), i);
        //     printf("\noriginal add : %u ,acc.no. : %d , j=%d\n" , &customer[j].acntNumber , customer[j].acntNumber , j);
        // }


    int start = 0, end = totalAccount - 1;

    for (int i = 0; i <= totalAccount * 7 && start <= end; i += 7) // 7*4bytes==28bytes
    {
        int mid = ((start + end) / 2) * i;
        printf("\nmid accnt num = %d ,mid=%d\n", *(bankData + mid), mid);

        if (*(bankData + mid) == account_num)
        {
            return mid;
        }
        else if (*(bankData + mid) > account_num)
        {
            start = mid + 28;
        }
        else
        {
            end = mid + 28;
        }
    }
}
*/