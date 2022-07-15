#include <stdio.h>
void fibonacci();

int main()
{
	int num;
	printf("Enter number to print Fibonacci seq. upto.. :");
	scanf("%d", &num);

	printf("Fibonacci Series is: \n 1, ");
	fibonacci(num);
	return 0;
}

void fibonacci(int n)
{
	for (int i = 1, a = 0, b = 1, c = 0; i < n; i++)
	{
		c = a + b;
		printf("%d, ", c);
		a = b;
		b = c;
	}
	printf("\n");
}