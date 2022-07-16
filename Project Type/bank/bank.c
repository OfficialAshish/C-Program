#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma pack(1) // default

#define TOTALCUSTOMER (3 + 97)
// prototypes
void registerUser();
void accountDetail();
void modifyAccout();
void deposit_amnt();
void withdraw_amnt();
void exitBank();

int getAccount();
int accountNumber(int);
void createTestAccount(int);
int searchAccount_binary(int *, int, int);
int searchAccount_linear(int *, int, int);

// structure for customers accounts
typedef struct bankCustomer
{
    char acntName[20];
    int acntNumber;
    int acntBalance;

} bca;

bca customer[TOTALCUSTOMER];


int main()
{
    int option = 0;

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

restart:
    do
    {
        printf("\nWelcome To Our BANK !\n");
        printf("\n 1 : Register User. \n 2 : Modify Account. \n 3 : Account Detail. \n 4 : Deposit Ammount. \n 5 : Withdraw Ammount. \n 6 : Exit.\n");
        printf("\nSelect Option : ");
        scanf("%d", &option);
        fflush(stdin);
    } while (option == 0);

    switch (option)
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
    }
}

//FUNCTIONS
//assigning account number
int accountNumber(int index)
{
    static int accountIndex;
    int assignNum = 100 + accountIndex;
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

//registering new user account
void registerUser()
{
    printf("\nCreating new Account!\n");
    printf("\nEnter Your Name : \n");
    char temp[20];
    scanf("%[^\n]s",temp);
    fflush(stdin);
    
}
void accountDetail()
{
    printf("\nGet your Account Details.\n");
    printf("\nname=%s , accountNumber=%d , Account Balance = %d, \n", customer[0].acntName, customer[0].acntNumber, customer[0].acntBalance);
    printf("\nname=%s , accountNumber=%d , Account Balance = %d, \n", customer[1].acntName, customer[1].acntNumber, customer[1].acntBalance);
    printf("\nname=%s , accountNumber=%d , Account Balance = %d, \n", customer[2].acntName, customer[2].acntNumber, customer[2].acntBalance);

    int *baseAccount_Num_Add = &customer[0].acntNumber;
    /*
        for (int i = 0,j=0; i < 7*5; i+=7,j++)
        {
            printf("\nmodifing add : %u ,acc.no. : %d, i=%d\n" , (p+i), *(p+i), i);
            printf("\noriginal add : %u ,acc.no. : %d , j=%d\n" , &customer[j].acntNumber , customer[j].acntNumber , j);
        }
         */

    int index = searchAccount_linear(baseAccount_Num_Add, 101, 3);
    printf("\nndex =%d ,\n", index);
}
void modifyAccout()
{
}
void deposit_amnt()
{
}
void withdraw_amnt()
{

}

void exitBank()
{
    printf("\nGood-Bye!\n\tThank-You For Using Our Bank!\n\n");
    exit(1);
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

    for (int i = 0, index = 0;  i <= (totalAccount *28); i += 7, index++) // 7*4bytes==28bytes
    {

        printf("\nAccount:: add : %u ,acc.no. : %d, i=%d\n", (bankData + i), *(bankData + i), i);

        if (*(bankData + i) == account_num)
        {
            return index;
        }
    }
    return -1;
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