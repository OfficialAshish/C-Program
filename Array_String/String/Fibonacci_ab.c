#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40

void fib(char *a, char *b, int n);

int main()
{
    int n;
    printf("Enter n");
    scanf("%d", &n);

    char a[SIZE] = "a", b[SIZE] = "b";
    if (n == 0)
    {
        printf("f(0) : %c", a[0]);
    }
    else if (n == 1)
    {
        printf("f(1) : %c", b[0]);
    }
    else if (n == 2)
    {
        printf("f(0) : %c\nf(1) : %c", a[0], b[0]);
    }
    else if (n>2) {
        printf("f(0) : %c\nf(1) : %c", a[0], b[0]);
        fib(a, b, n);
    }
    
    return 0;
}

void fib(char *a, char *b, int n)
{
    char c[SIZE];
    for (int i = 0; i < n && n > 2; i++)
    {
        *c = '\0';
        strcat(c, b);
        strcat(b, a);
        //printf("\nlen:  %d ", strlen(p));
        printf("\nf(%d) : %s", i + 2, b);
        *a = '\0';
        //printf("\n null a str %s\n", a);
        strcat(a, c);
        //printf("\na str %s\n", a);
    }
}

/*

//mistakes
    char *p = malloc(strlen(b));
    strcat(p,a);
    
    for (int i = 3; i <= n; i++)
    {
        b = strcat(b , p);
        printf("\nlen:  %d ",strlen(p));
        printf("\n%d : %s\n", i , b);
        free(p);
        printf("\np str %s\n" , p);
        char *p = (char *) malloc(strlen(b));
        strcat( p ,b);
    }
    free(p);
    
    
    */