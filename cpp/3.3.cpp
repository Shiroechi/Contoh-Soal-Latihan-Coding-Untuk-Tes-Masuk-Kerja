#include<stdio.h>

// n = 5       n = 6 
//   *           *
//  **          **
// ***         ***
//  **         ***
//   *          **
//               *

int main()
{
	int n;
	printf("n: ");
	scanf("%d", &n);

	int middle_index = n / 2;
	int max_column_length = n - middle_index;

	for (int i = 0; i < n; i++)
	{
		if (i < middle_index)
		{
			for (int j = 0; j < max_column_length - (i + 1); j++)
			{
				printf(" ");
			}

			for (int j = 0; j < i + 1; j++)
			{
				printf("*");
			}
		}
		else 
		{
			int space_count;
			if (n % 2 == 0)
			{
				space_count = i;
			}
			else
			{
				space_count = i + 1;
			}
			
			for (int j = 0; j < space_count - max_column_length; j++)
			{
				printf(" ");
			}

			for (int j = 0; j < n - i; j++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
