#include <stdio.h>
#include <string.h>
#define DEBUG 1
#define COL 3
#define ROW 8

void selectionSortStr(char *, int, int);
void swapstr(char *a, char *b);

int main()
{
    char str[ROW][COL] = {"cb", "ca", "ab", "aa", "ba", "bc", "bb", "ac"};

    selectionSortStr(&str[0][0], ROW, COL);

    // Printing
    printf("\nSorted Array: \n { ");
    for (int j = 0; j < ROW; j++)
    {
        printf(" %s ,", str[j]);
    }

    printf("  } \n");
    return 0;
}

// for 2D arrays_strings
void selectionSortStr(char *strPoint, int row, int col)
{
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = i + 1; j < row; j++)
        // j<col for compairing from other remain elem
        {
            // printf(" \n(><ONLY)\n i=%d  : %s  , > j=%d : %s , \n", i, (strPoint + (col * i)), j, (strPoint  + (col * j)));

            if (*(strPoint + (col * i)) > *(strPoint + (col * j)))
            {
                swapstr((strPoint + (col * i)), (strPoint + (col * j)));
            }
        }

        // loop for equal char
        for (int j = i + 1, k = 0; j < row && k < col - 1; j++)
        {
            if (*(strPoint + k + (col * i)) == *(strPoint + k + (col * j)))
            {
                // printf(" \n (EQUAL FOUND)\n i=%d : %s , k=%d ,= j= %d : %s, \n", i, (strPoint + k + (col * i)), k, j, (strPoint + k + (col * j)));

                k++;

                if (*(strPoint + k + (col * i)) > *(strPoint + k + (col * j)))
                {
                    swapstr((strPoint + (col * i)), (strPoint + (col * j)));
                    k = 0;
                    continue;
                }
                // printf("\nj: %d @ %d\n", j, i);
                j--;
            }
        }

        // to print all sorting steps
        if (DEBUG == 1)
        {
            printf("\n {{");
            for (int i = 0; i < row; i++)
            {
                printf(" %s ,", (strPoint + (col * i)));
            }
            printf("  }}\n");
        }
    }
}

void swapstr(char *a, char *b)
{
    char t[COL];

    // printf("\nswapping:  s(i) = %s ; s(j) = %s\n", a, b);
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}