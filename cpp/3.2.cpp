
#include<stdio.h>
#include<math.h>
#include<conio.h>

void main()
{
	int n, x, y, counter, bintang;
	bool lagi = true;
	counter = 0;
	x = 0;
	y = 0;
	bintang = 1;

	while (lagi == true)
	{
		printf("masukan angka :");
		scanf("%d", &n);

		if (n % 2 == 1) // angka ganjil 
		{
			while (counter <= (n + 1) / 2)// bagian atas
			{
				while (bintang < counter)
				{
					printf("*");
					bintang++;
				}
				printf("\n");
				bintang = 0;
				counter++;
			}
			/*printf ("counter atas = %d\n", counter );*/

			while (counter - 1 > 0) // bagian bawah 
			{
				while (bintang < counter - 2)
				{
					printf("*");
					bintang++;
				}
				printf("\n");
				bintang = 0;
				counter--;
			}


		}
		else if (n % 2 == 0)
		{
			while (counter <= (n + 1) / 2) // bagian atas
			{
				while (bintang < counter)
				{
					printf("*");
					bintang++;
				}
				printf("\n");
				bintang = 0;
				counter++;
			}
			/*printf ("counter atas = %d\n", counter );*/

			while (counter - 1 > 0) // bagian bawah 
			{
				while (bintang < counter - 1)
				{
					printf("*");
					bintang++;
				}
				printf("\n");
				bintang = 0;
				counter--;
			}
		}
		else
		{
			lagi = false;
		}
		getch();
	}
}