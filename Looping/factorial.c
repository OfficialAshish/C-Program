#include <stdio.h>
int main()
{
	int num ;
	printf("Enter factorial upto:\t");
	scanf("%d", &num);
	printf("%d\n",  factorial(num));
	return 0;
}

int factorial(int f)
{
	int x, fact = 1;
	for (x = 1; x <= f; x++)
	{
		fact = fact * x;
	}
	return (fact);
}