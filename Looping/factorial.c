#include <stdio.h>
int main()
{
	int num ;
	printf("Enter factorial upto:\t");
	scanf("%d", &num);
	printf("%d\n",  factorial(num));
	return 0;
}

<<<<<<< HEAD
    int num,ans;
    printf("Enter num. to get it\'s factorial:  ");
    scanf("%d",&num);
    ans=factorial(num);
    printf("%d\n",ans);
    return 0;

} 
=======
int factorial(int f)
{
	int x, fact = 1;
	for (x = 1; x <= f; x++)
	{
		fact = fact * x;
	}
	return (fact);
}
>>>>>>> 2f840c785fb0772d4b63130d66a3ec9d1b37a82b
