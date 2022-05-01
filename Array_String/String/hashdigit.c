#include <stdio.h>
#include <math.h>
#include <string.h>
#define SIZE 10

void hashdigit(int ndigit, int row);
void digarr(int digit);
int digitlen(int);

int digitarr[SIZE];

int main()
{
    int digit;
    printf("Enter digit : ");
    scanf("%d", &digit);
    digarr(digit);
    int len = digitlen(digit);
    //printf("%d",len);

    /*
    for (int k=0 ; k<len ; k++)
    {
        printf("\nno.: %d\n",digitarr[k]);
    }
    */
    printf("\n\n");
    for (int row = 1; row <= 8; row++)
    {
        for (int i = 0; i < len; i++)
        {
            hashdigit(digitarr[i], row);
            printf("\t");
        }
        printf("\n");
    }
    //getchar();
    return 0;
}

void hashdigit(int ndigit, int row)
{
    //printf("\nn: %d ,, row:%d",ndigit,row);

    char D1[8][5] = {"  # ", " ##", "  #", "  #", "  #", "  #", " ###"};

    char D2[8][9] = {"#####", "    #", "    #", "#####", "#    ", "#    ", "#####"};

    char D3[8][9] = {"#####", "    #", "    #", "#####", "    #", "    #", "#####"};

    char D4[8][9] = {"#     ", "#     ", "#   # ", "######", "    # ", "    # ", "    # "};

    char D5[8][9] = {" ######", " #     ", " #     ", " ######", "      #", "      #", " ######"};

    char D6[8][9] = {"######", "#     ", "#     ", "######", "#    #", "#    #", "######"};

    char D7[8][9] = {"#######", "     # ", "    #  ", "   #   ", "  #    ", " #     ", "#      "};

    char D8[8][9] = {"######", "#    #", "#    #", "######", "#    #", "#    #", "######"};

    char D9[8][9] = {"######", "#    #", "#    #", "######", "     #", "     #", "######"};

    //char D0[8][9] = { "   #   " , "  # #" , " #   # " , "#     #" , " #   # " , "  # # ", "   #   " };

    char D0[8][9] = {"######", "#    #", "#    #", "#    #", "#    #", "#    #", "######"};

    //printf("%s" , &D3[0][0]);

    if (ndigit == 0)
    {
        printf("%s", &D0[row - 1][0]);
    }
    else if (ndigit == 1)
    {
        printf("%s", &D1[row - 1][0]);
    }
    else if (ndigit == 2)
    {
        printf("%s", &D2[row - 1][0]);
    }
    else if (ndigit == 3)
    {
        printf("%s", &D3[row - 1][0]);
    }
    else if (ndigit == 4)
    {
        printf("%s", &D4[row - 1][0]);
    }
    else if (ndigit == 5)
    {
        printf("%s", &D5[row - 1][0]);
    }
    else if (ndigit == 6)
    {
        printf("%s", &D6[row - 1][0]);
    }
    else if (ndigit == 7)
    {
        printf("%s", &D7[row - 1][0]);
    }
    else if (ndigit == 8)
    {
        printf("%s", &D8[row - 1][0]);
    }
    else if (ndigit == 9)
    {
        printf("%s", &D9[row - 1][0]);
    }
}

int digitlen(int digit)
{
    //char str[] = digit + '\0';
    char str[SIZE + 1];
    sprintf(str, "%d", digit);
    //printf("\nstr:%s" , str);
    int len = strlen(str);
    return len;
}

void digarr(int digit)
{
    int len = digitlen(digit);
    //int digarr[len];

    //printf("\n%d", len);

    for (int j = pow(10, len), i = 0; j > 1; j /= 10, i++)
    {
        digitarr[i] = ((digit % j) - (digit % (j / 10))) / (j / 10);
        //printf("\n%d digit:%d", i, digitarr[i]);
    }

    //return digarr[0];
}