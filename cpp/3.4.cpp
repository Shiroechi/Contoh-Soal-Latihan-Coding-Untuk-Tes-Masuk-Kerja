#include<stdio.h>

int main()
{
	int n;
	printf("n: ");
	scanf("%d", &n);

	int middle_index = n;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n - k; i++)
		{
			// print persegi
			for (int j = 0; j < n - k; j++)
			{
				printf("*");
			}

			printf(" ");

			// print segitiga
			for (int j = 0; j < n - k - i; j++)
			{
				printf("*");
			}

			printf("\n");
		}
		printf("\n");
	}

	return 0;
}