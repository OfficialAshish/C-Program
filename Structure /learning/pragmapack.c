#include <stdio.h>
#pragma pack(1)
//boundary gaf btw struct elem address
//pack(0) is default for 4bytes
struct emp
{
    int a;
    char ch;
    float s;
    float ss;
};

int main()
{
    struct emp e;
    printf("%u\n%u\n%u\n%u\n%u\n", &e ,&e.a, &e.ch, &e.s, &e.ss);
    
    e.ch="ndjnfkdkdjdjdjdijddhg";
    e.ss=4.55;
    //struct emp e;
    printf("\n\n");
    printf("%u\n%u\n%u\n%u\n%u\n", &e ,&e.a, &e.ch, &e.s, &e.ss);
    printf("str:: %s\n",&e.ch);//not working
    
    printf("%f",e.ss);
    
    printf("\n\n");
    
    struct emp f;
    printf("%u\n%u\n%u\n%u\n%u\n", &f ,&f.a, &f.ch, &f.s, &f.ss);
    
    return 0;
}