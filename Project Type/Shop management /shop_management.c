

#define COMP_SER_S 2
//#define MAX_SERIALNUM (26*26)
#define PROD_SER_S (COMP_SER_S + 4)
//(AB)DP84, 67600 diffrnt products for each company
//#define SERIALNUM_SIZE 6
//AA(E899), prod_series len>26k 

//structures 

typedef struct date
{
    short unsigned int dd;
    short unsigned int mm;
    short unsigned int yy;
} date;

typedef struct productInfo
{
    char productName[30];
    company productCompany;//its caste & series it belongs
    char productSeries[PROD_SER_S];//6bytes total(AA)(BD89)
    unsigned int productPrice;
    date manufactureDate;
    date expiryDate;
    unsigned int productQuantity;
    short int  productRating =4 ; //default
} productInfo;

/* //not required ,this way
typedef struct serialNumber
{
    //char series[MAX_SERIALNUM][SERIALNUM_SIZE];    
}s_serialNum;
*/

typedef struct company
{
    char companyName;
    char companySeries[COMP_SER_S];//ex. (AA)2bytes
    short int companyRating =4;
    
    //serialNumber companySeries;
    
}s_company;
