#include <stdio.h>
int main()
{
	int j = 2, num, i;
	printf("Enter num:\t");
	scanf("%d", &num);

	for (j = 2; j <= num; j++)
	{
		for (i = 2; i <= j / 2; i++)
		{
			if (j % i == 0)
			{
				break;
			}
		}
		//for 2,3 cases when i<j/2 fails, & when i gets greater then j/2 in loop i.e. it's prime
		if (i > j / 2)
		{
			printf("%d ,", j);
		}
	}

	return 0;
}