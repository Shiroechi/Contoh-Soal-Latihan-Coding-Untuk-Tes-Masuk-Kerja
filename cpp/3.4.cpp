#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<windows.h>

void main()
{
	int n, counter;
	bool lagi = true;

	while (lagi == true)
	{
		counter = 1;
		printf("masukan n:");
		scanf("%d", &n);

		//persegi
		for (int i = n; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				for (int k = 0; k < i; k++)
				{
					printf("*");
				}

				printf("\n");
			}

			printf("\n");
		}

		//segitiga
		for (int i = n; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				for (int k = i; k > 0 + j; k--)
				{
					printf("*");
				}

				printf("\n");
			}

			printf("\n");
		}

		getch();
	}
}