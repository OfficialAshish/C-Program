#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPANY_SER_SZ (2 + 1)
//#define MAX_SERIALNUM (26*26)
#define PROD_SER_SZ (COMPANY_SER_SZ + 4 + 1)
//(AB)DP84, 67600 diffrnt products for each company
#define TOT_COMP (200)
#define TOT_PROD_UNQ (700)
// 676*6bytes
#define TOT_PROD_QUANT (300)
// default 100 quantity for each unique prod

// structures

typedef struct company
{
    char companyName[20];

    char companySeries[COMPANY_SER_SZ]; // ex. (AA)2bytes

    short int companyRating;

} s_company;

typedef struct date
{
    unsigned short int dd;
    unsigned short int mm;
    unsigned int yy;
} s_date;

struct quantity
{
    int quantityIndex; // total num of quantity present for unique prod
};

typedef struct unique_productInfo
{
    char productName[30];
    s_company productCompany; // its caste & series it belongs

    // char productSeries[PROD_SER_SZ]; // 6bytes total(AA)(BD89)

    // unsigned int productQuantity;

    struct quantity productQuantity; // total num of quantity present for each unique product

    char productSeries[TOT_PROD_QUANT][PROD_SER_SZ];

    unsigned int productPrice;

    s_date manufactureDate;
    s_date expiryDate;

    short int productRating;

} s_productInfo;

// Global Declaration..

s_productInfo productInfo[TOT_PROD_UNQ]; // Each
// s_company comapanyInfo[TOT_COMP];

static int productIndex = 1; // total unique prod present till for each individual company
static int comapanyIndex;

// char *seriesPointer;

// Prototypes!..

char *uniqueCompanySerialAssign(int); // step1
char *uniqueProductSerialAssign(int); // step2, ,step1 required before this func. to give expected result

int searchProduct_Linear(char *); // returns index after searching from given serial num
int getUniqueProductDetail();

int getAllProductDetail();

int getAllProductSerial();
int getCompnsProdSerial(); // serial for diffrnt prod for particular company

int addProduct_auto(int);
int addproduct();

// main function..
int main()
{
    // default example products..

    strcpy(productInfo[productIndex].productName, "LG Laptop");

    strcpy(productInfo[productIndex].productCompany.companyName, "Pvt. LG Limited");

    strcpy(productInfo[productIndex].productCompany.companySeries, "AA");

    strcpy(productInfo[productIndex].productSeries[productIndex], uniqueProductSerialAssign(productIndex));

    productInfo[productIndex].productCompany.companyRating = 7;

    productInfo[productIndex].productPrice = 34000;
    // productInfo[0].productQuantity.quantityIndex ;
    productInfo[productIndex].productRating = 4;

    productInfo[productIndex].manufactureDate.dd = 2;
    productInfo[productIndex].manufactureDate.mm = 4;
    productInfo[productIndex].manufactureDate.yy = 2022;

    productIndex++;

    addproduct();

    // strcpy(productInfo[1].productCompany.companySeries, "AB");
    //  strcpy(productInfo[0].productSeries[1], uniqueProductSerialAssign(0));
    //  strcpy( productInfo[1].productSeries[1] , uniqueProductSerialAssign(1));

    // printf("\nprice:%d, \n quantity=%d, \n " , productInfo[0].productPrice ,productInfo[0].productQuantity );

    // printf("\nprice:%d, \n quantity=%d, \n date=%d,%d,%d ,rat=%d, series=%s,,%s \n company name=%s,\n", productInfo[0].productPrice, productInfo[0].productQuantity, productInfo[0].manufactureDate.dd, productInfo[0].manufactureDate.mm, productInfo[0].manufactureDate.yy, productInfo[0].productCompany.companyRating, productInfo[0].productCompany.companySeries,productInfo[1].productSeries , productInfo[0].productCompany.companyName);

    // printf("\n%s\n%s\n", productInfo[0].productSeries[0], productInfo[0].productSeries[1]);

    return 0;
}

// Functions

char *uniqueCompanySerialAssign(int index)
{
    static char v01 = 'A', v02 = 'A';
    static char tempSer[3];

    if (comapanyIndex <= TOT_COMP)
    {
        sprintf(tempSer, "%c%c", v01, v02);

        // Requirements for next serial assignments...UPDATING!

        comapanyIndex++;

        if (v01 < 90)
        {
            v01++;
        }
        else if (v01 == 90 && v02 < 90)
        {
            v02++;
            v01 = 'A';
        }
        else if (v01 == 90 && v02 == 90)
        {
            printf("\nCompany Series Assignment is Full, Cannot Assign more!...Aborting\n");
            // return 100;
            exit(9);
        }
        else
        {
            printf("\nSomething wrong in company serial assignment... Aborting!...\n");
            // return 100;
            exit(9);
        }
    }
    return tempSer;
}

char *uniqueProductSerialAssign(int index)
{
    static char tempSerial[7];
    static char v4 = 'A';
    static int v3, v2, v1;

    if (productInfo[productIndex].productQuantity.quantityIndex <= TOT_PROD_QUANT)
    {
        sprintf(tempSerial, "%s%c%d%d%d", productInfo[productIndex].productCompany.companySeries, v4, v3, v2, v1);

        printf("\nprodser: %s\n" , tempSerial);
        // Requirements for next serial assignments...UPDATING!

        productInfo[productIndex].productQuantity.quantityIndex += 1;

        if (v1 < 9)
            v1++;
        else
        {
            if ((v1 == 9) && (v2 < 9))
            {
                v2++;
                v1 = 0;
            }
            else if ((v2 == 9) && (v3 < 9))
            {
                v3++;
                v2 = 0;
                v1 = 0;
            }
            else if ((v3 == 9) && (v4 < 90))
            {
                v1++;
                v2 = 0;
                v3 = 0;
                v1 = 0;
            }
            else if ((v1 == 9) && (v2 == 9) && (v3 == 9) && (v4 == 90))
            {
                printf("\nSeries Assignment is Full, Cannot Assign more!...Aborting\n");
                // return 100;
                exit(10);
            }
            else
            {
                printf("\nSomething wrong in company serial assignment... Aborting!...\n");
                // return 100;
                exit(10);
            }
        }
    }

    return tempSerial;
}

int addproduct()
{
    printf("\nAdding Product... \n");
    int condition = 0;
    int tempNum = 0;
    short int subCondition_1 = 0;
    char cond_yn = 'y';

    char tempCompName[15], tempProdName[20];
    // static int newProductIndex;

    do
    {

        // printf("\n1: Add Product by Company...\n2: Add Product Individually...\n3: Exit!\nSelect Option : ");
        // company details related to product
        printf("\n1: Add Product Individually...\n2: Exit!\nSelect Option : ");

        scanf("%d", &condition);
        if (condition == 1)
        {
        again:
            printf(("\nWant to ...\n1: Enter or 2: Select Company Name?? or Press Enter to Skip...\n"));
            // fflush(stdin);
            scanf("%d", &subCondition_1);
            // fflush(stdin);

            if (subCondition_1 == 1)
            {
                printf("\nEnter Company Name : \n");
                scanf("%s", tempCompName);
                fflush(stdin);
                strcpy(productInfo[productIndex].productCompany.companyName, tempCompName);
            }
            else if (subCondition_1 == 2)
            {
                if (productIndex > 0)
                {
                    int i;
                    for (i = 1; i < productIndex; i++)
                    {
                        printf("\nCompanies Names Are: \n");
                        printf("\n\t\t%d : %s ,\n", i, productInfo[i].productCompany.companyName);
                    }
                    printf("\nSelect Company Name :");
                    scanf("%d", &i);
                    // fflush(stdin);
                    strcpy(productInfo[productIndex].productCompany.companyName, productInfo[i].productCompany.companyName);
                    printf("\nC_Done\n");
                }
                else
                {
                    printf("\nNo Company to Show!...Add some.\n");
                }
            }
            else
            {
                // company name for each product
                printf("\nWARNING!...Company Name Required For Expected Product Serial No.\n");
                // char cn = 'y';
                printf("\nWant to still Skip...Y/N or Enter to skip...");
                // fflush(stdin);
                scanf("%c", &cond_yn);
                // fflush(stdin);
                if (cond_yn == 110 || cond_yn == 78)
                {
                    goto again;
                }
                else
                {
                    printf("\nOkay!\n");
                }
            }

            // rating products
            printf("\nWant to give Rating to product? ...Y/N or Press Enter to Skip!: ");
            fflush(stdin);

            scanf("%c", &cond_yn);
            fflush(stdin);

            if ((cond_yn == 89) || (cond_yn == 121))
            {
                scanf("%d", &tempNum);
                fflush(stdin);
                productInfo[productIndex].productCompany.companyRating = tempNum;
            }
            else
            {
                productInfo[productIndex].productCompany.companyRating = 7;
                printf("\nDefault set to 7 out of 10..\n");
            }

            // product name
            printf("\nEnter Product Name : \n");
            scanf("%s", tempProdName);
            fflush(stdin);
            strcpy(productInfo[productIndex].productName, tempProdName);

            strcpy(productInfo[productIndex].productCompany.companySeries, uniqueCompanySerialAssign(productIndex));

            strcpy(productInfo[productIndex].productSeries[productIndex], uniqueProductSerialAssign(productIndex));

            // rating
            printf("\nWant to give Rating to product? ...Y/N or Press Enter to Skip!: ");
            scanf("%c", &cond_yn);
            // fflush(stdin);

            if ((cond_yn == 89) || (cond_yn == 121))
            {
                printf("\nEnter Rating out of 10 : ");
                scanf("%d", &tempNum);
                // fflush(stdin);
                productInfo[productIndex].productRating = tempNum;
            }
            else
            {
                productInfo[productIndex].productRating = 7;
                printf("\nDefault set to 7 out of 10..\n");
            }

            // set price
            printf("\nEnter Price : \n");
            scanf("%d", &tempNum);
            productInfo[productIndex].productPrice = tempNum;

            // expiry date
            printf("\nWant to give Expiry date to product? ...Y/N or Press Enter to Skip!: ");
            // fflush(stdin);
            scanf("%c", &cond_yn);
            // fflush(stdin);

            short int td = 0, tm = 0, ty = 0;
            if ((cond_yn == 89) || (cond_yn == 121))
            {
                printf("\nEnter Expiry Date (dd mm yy) :");
                scanf("%d%d%d", &td, &tm, &ty);
                fflush(stdin);
                productInfo[productIndex].manufactureDate.dd = td;
                productInfo[productIndex].manufactureDate.mm = tm;
                productInfo[productIndex].manufactureDate.yy = ty;
            }
            else
            {
                productInfo[productIndex].manufactureDate.dd = td;
                productInfo[productIndex].manufactureDate.mm = tm;
                productInfo[productIndex].manufactureDate.yy = ty;
                printf("\nDefault set to 0 0 0...\n");
            }
            printf("\nDude, %d\'th Product Added Successfully! .\n", productIndex);

            printf("\nPrinting Product...\n");
            printf("\nprod_name: %s ,price:%d, \n quantity=%d, \n date=%d,%d,%d ,rat=%d, series=%s,,%s \n company name=%s,\n", productInfo[productIndex].productName , productInfo[productIndex].productPrice, productInfo[productIndex].productQuantity.quantityIndex, productInfo[productIndex].manufactureDate.dd, productInfo[productIndex].manufactureDate.mm, productInfo[productIndex].manufactureDate.yy, productInfo[productIndex].productCompany.companyRating, productInfo[productIndex].productCompany.companySeries, productInfo[productIndex].productSeries, productInfo[productIndex].productCompany.companyName);

            productIndex++;
        }
        else if (condition == 2)
        {
            printf("\nExiting!...\n");
            return 100;
        }
        else
        {
            printf("\n%d ,Wrong Option Selected! Try Again...\n", condition);
        }
        fflush(stdin);
    } while (condition != 2);

    return 100;
}
