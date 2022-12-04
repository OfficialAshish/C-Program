#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = NULL;
    printf("%u ,\n", p);
    p = (int *)malloc(8);

    p[0] = 5;
    p[1] = 6;
    printf("p[1]=%d\n", p[1]);

    printf("%u ,\n", p);
    free(p);
    printf("p[1]=%d\n", p[1]);
    printf("%u ,\n", p);

    return 0;
}