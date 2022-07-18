#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPANY_SER_SZ (2 + 1)
//#define MAX_SERIALNUM (26*26)
#define PROD_SER_SZ (COMPANY_SER_SZ + 4 + 1)
//(AB)DP84, 67600 diffrnt products for each company

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

s_productInfo productInfo[TOT_PROD_UNQ]; // Each type

int productIndex;

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

//main function..
int main()
{
    // default example products..

    strcpy(productInfo[0].productName, "LG Laptop");

    strcpy(productInfo[0].productCompany.companyName, "Pvt. LG Limited");

    strcpy(productInfo[0].productCompany.companySeries, "AA");

    strcpy(productInfo[0].productSeries[0], uniqueProductSerialAssign(0));

    productInfo[0].productCompany.companyRating = 7;

    productInfo[0].productPrice = 34000;
    // productInfo[0].productQuantity.quantityIndex ;
    productInfo[0].productRating = 4;

    productInfo[0].manufactureDate.dd = 2;
    productInfo[0].manufactureDate.mm = 4;
    productInfo[0].manufactureDate.yy = 2022;

    //strcpy(productInfo[1].productCompany.companySeries, "AB");
    // strcpy(productInfo[0].productSeries[1], uniqueProductSerialAssign(0));
    // strcpy( productInfo[1].productSeries[1] , uniqueProductSerialAssign(1));

    // printf("\nprice:%d, \n quantity=%d, \n " , productInfo[0].productPrice ,productInfo[0].productQuantity );

    // printf("\nprice:%d, \n quantity=%d, \n date=%d,%d,%d ,rat=%d, series=%s,,%s \n company name=%s,\n", productInfo[0].productPrice, productInfo[0].productQuantity, productInfo[0].manufactureDate.dd, productInfo[0].manufactureDate.mm, productInfo[0].manufactureDate.yy, productInfo[0].productCompany.companyRating, productInfo[0].productCompany.companySeries,productInfo[1].productSeries , productInfo[0].productCompany.companyName);

    // printf("\n%s\n%s\n", productInfo[0].productSeries[0], productInfo[0].productSeries[1]);

    return 0;
}

// Functions

char *uniqueCompanySerialAssign(int index)
{
    static char tempSer[3];
    
}

char *uniqueProductSerialAssign(int index)
{
    static char tempSerial[7];
    char v4 = 'A';
    static int v3, v2, v1;

    if (productInfo[index].productQuantity.quantityIndex <= TOT_PROD_QUANT)
    {
        sprintf(tempSerial, "%s%c%d%d%d", productInfo[index].productCompany.companySeries, v4, v3, v2, v1);

        // Requirements for next serial assignments...UPDATING!

        productInfo[index].productQuantity.quantityIndex += 1;

        if (v1 < 9)
            v1++;
        else
        {
            if ((v1 == 9) && (v2 < 9))
            {
                v2++;
                v1 = 0;
            }
            if ((v2 == 9) && (v3 < 9))
            {
                v3++;
                v2 = 0;
                v1 = 0;
            }
            if ((v3 == 9) && (v4 < 90))
            {
                v1++;
                v2 = 0;
                v3 = 0;
                v1 = 0;
            }
            if ((v1 == 9) && (v2 == 9) && (v3 == 9) && (v4 == 90))
            {
                printf("Series Assignment is Full, Cannot Assign more!...Aborting");
                exit(10);
            }
        }
    }

    return tempSerial;
}
