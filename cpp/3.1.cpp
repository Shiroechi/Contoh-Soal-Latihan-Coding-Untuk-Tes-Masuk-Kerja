
#include<stdio.h>
#include<math.h>
#include<conio.h>


void main ()
{
	int n, counter, x, y;
	counter = 1;
	x = 0; y = 0;
	char a;
	a = 97;

	printf ("masukan ukuran :");
	scanf("%d", &n);

	while (counter <= (n * (n*2)))
	{
		if (a >= 123)
		{
			a = 97;
		}
		if (counter % (n * 2) == 0)
		{
			printf("%c", a);
			a++;
			printf("\n");
		}
		else 
		{
			printf("%c", a);
			a++;
		}
		counter++;	
	}

	printf("\n\n\n");
	a = 97;
	for (int i = 0; i < n * 2; i++)
	{
		for (int j = 0; j < n * 2; j++)
		{
			printf("%c ", a);
			a++;

			if (a >= 123)
			{
				a = 97;
			}
		}
		printf("\n");
	}

	getch();
}