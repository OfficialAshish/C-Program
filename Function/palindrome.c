
#include <stdio.h>

void main()
{
	int n;
	printf("Enter size(no. of char) of string: ");
	scanf("%d", &n);
	char str[n + 1];
	printf("\nEnter string to check weather it\'s palindrome or not : ");
	scanf("%s", str);
	int l = (sizeof(str) - 1), ch = 0, i;
	int v = (l / 2 - 1);
	for (i = 0; i <= v; i++)
	{
		//printf("%c", str[i]);
		//printf("\ni:%d\n", i);

		if (str[i] != str[l - 1 - i])
		{
			break;
		}
	}
	//printf("%d",i);
	//i gets increm for failing loop condn
	if (i -1 == v)
	{
		printf("It\'s Palindrome. ");
	}
	else
	{
		printf("It\'s not Palindrome. ");
	}
}
