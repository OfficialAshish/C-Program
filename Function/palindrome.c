#include <stdio.h>
#include <string.h>

void main()
{
	int n;
	char str[20] ;
	printf("\nEnter string to check weather it\'s palindrom or not : ");
	scanf("%s", str);
	n=strlen(str)  ;
	//printf("l:%d \n" , n);
	
	int i;
	int v = (n / 2) - 1; //-1 to manage i index of arr

	for (i = 0; i <= v; i++)
	{
		//printf("%c", str[i]);
		//printf("\ni:%d\n", i);

		if (str[i] != str[n - 1 - i]) //-1 to manage index
		{
			break;
		}
	}
	//printf("\ni:%d\n",i);
	//i gets increm for failing loop condn
	if (i - 1 == v)
	{
		printf("It\'s Palindrom. ");
	}
	else
	{
		printf("It\'s not Palindrom. ");
	}
}
