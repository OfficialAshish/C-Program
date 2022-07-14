#include <stdio.h>

int main()
{
    char str[][6] = {"hhhgh", "agyhx", "bgfhh"};
    char *strp = &str;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("\ni=%d,j=%d,%u, %c\n", i, j, &str[j][i], (str[j][i]));
            
            printf("\n%c, \n", *((strp + (j * 6) + i)));
            
            //printf("\ni=%d,j=%d,%u, %c\n", i, j, &str[j][i], *(str + (j * 6) + i));//error
        }
    }
    return 0;
}

//(strp + (j * 6) + i)