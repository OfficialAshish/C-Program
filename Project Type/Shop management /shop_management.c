#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMP_SER_S (2+1)
//#define MAX_SERIALNUM (26*26)
#define PROD_SER_S (COMP_SER_S + 4 +1)
//(AB)DP84, 67600 diffrnt products for each company
#define TOT_PROD (676) //676*6bytes

#define TOT_COMP_SER (676) //676*2bytes

// structures

typedef struct company
{
    char companyName;
    // char companySeries[TOT_COMP_SER][COMP_SER_S]; // ex. (AA)2bytes
    char companySeries[COMP_SER_S]; // ex. (AA)2bytes
    short int companyRating;

} s_company;

typedef struct productInfo
{
    char productName[30];
    s_company productCompany;       // its caste & series it belongs
    char productSeries[TOT_PROD][PROD_SER_S]; // 6bytes total(AA)(BD89)
    unsigned int productPrice;
    s_date manufactureDate;
    s_date expiryDate;
    unsigned int productQuantity;
    short int productRating;
} s_productInfo;

typedef struct date
{
    unsigned short int dd;
    unsigned short int mm;
    unsigned short int yy;
} s_date;



/* //not required ,this way
typedef struct serialNumber
{
    //char series[MAX_SERIALNUM][SERIALNUM_SIZE];
}s_serialNum;
*/

//Global Declaration..
s_productInfo totalProducts[TOT_PROD];


// FUNCTIONS...
int serialNumber(int);

int main()
{
    //default example products..

    strcpy(totalProducts[0].productName , "LG Laptop");
    strcpy(totalProducts[0].productCompany.companyName , "Pvt. LG Limited" );
    strcpy(totalProducts[0].productCompany.companySeries , "AA");
    totalProducts[0].productCompany.companyRating = 7;
    totalProducts[0].productPrice = 34000;
    totalProducts[0].productQuantity = 29;
    totalProducts[0].manufactureDate.dd = 2;
    totalProducts[0].manufactureDate.mm = 4;
    totalProducts[0].manufactureDate.yy = 2022;

}