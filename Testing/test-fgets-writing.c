#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
int main(void)
{
    FILE *fp;
    char s[50];
    fp = fopen("POEM TXT", "w");
    if (fp == NULL)
    {
        puts("Cannot open file! \n");
        exit(1);
    }

    printf("\nEnter a few lines of text:\n");
    while (strlen(fgets(s , 50 , stdin)) > 0)
    {
        fputs(s, fp);
        fputs("\n", fp);
    }
    
    fclose(fp);
    return 0;
}