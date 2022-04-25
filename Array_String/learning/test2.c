#include <stdio.h>
#include <string.h>
int main()
{
    char r3[9], r1[9], r2[9], r4[20];
    scanf("%s%s%s", r1, r2, r3);

    printf("\nr1 : %s \nr2 : %s \nr3 :%s", r1, r2, r3);

    strcpy(r4, r2);

    printf("\n r4: %s ", r4);
}
