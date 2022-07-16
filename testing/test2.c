#include<stdio.h>

void func1();
int func2(int);

static int a;
//int a;

int main()
{

    printf("\nInside main1, a=%d ,", a);
    func1();
    printf("\nInside main2, a=%d ,", a);
    int c = func2(a);
    func1();
    func2(a);
    printf("\nInside main3, a=%d ,\n", a);
    printf("\nInside main3, c=%d ,\n", c);
    return 0;

}

void func1()
{
    int a;
    //static int a;
    a++;a++;
    printf("\nInside func1, a=%d ," , a);
    printf("\nInside func1, b=%d ,\n", a);


}

int func2(int a)
{
    return (++a);
}
