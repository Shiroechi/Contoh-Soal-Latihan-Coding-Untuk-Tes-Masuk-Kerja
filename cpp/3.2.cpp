#include<stdio.h>

// n = 5    n = 6 
// *        *
// **       **
// ***      ***
// **       ***
// *        **
//          *

int main()
{
	int n;
	printf("n: ");
	scanf("%d", &n);

	int middle_index = n / 2;
	for(int i = 0; i < n; i++)
	{
		if (i < middle_index)
		{
			for (int j = 0; j < i + 1; j++)
			{
				printf("*");
			}
		}
		else 
		{
			for (int j = 0; j < n - i; j++)
			{
				printf("*");
			}
		}
		printf("\n");
	}

	return 0;
}