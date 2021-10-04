#include<stdio.h>
#include<math.h>
#include<conio.h>

void main()
{
	int n, x, y, counter, bintang, spasi, batas;
	bool lagi = true;

	spasi = 0;
	counter = 0;
	x = 0;
	y = 0;
	bintang = 1;

	while (lagi == true)
	{
		printf("masukan angka :");
		scanf("%d", &n);

		batas = (n + 1) / 2;

		if (n % 2 == 1) // angka ganjil 
		{
			while (counter <= (n + 1) / 2) // bagian atas
			{
				while (spasi <= batas - 1) // spasi atas
				{
					printf(" ");
					spasi++;
				}
				batas--;
				spasi = 0;

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

			batas = 1;
			while (counter - 1 > 0)// bagian bawah 
			{
				while (spasi < batas) // spasi bawah
				{
					printf(" ");
					spasi++;
				}
				batas++;
				spasi = 0;

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
		else if (n % 2 == 0) // angka genap 
		{
			while (counter <= (n + 1) / 2) // bagian atas
			{
				while (spasi <= batas - 1) // spasi atas
				{
					printf(" ");
					spasi++;
				}
				batas--;
				spasi = 0;

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

			batas = 1;
			while (counter - 1 > 0) // bagian bawah 
			{
				while (spasi < batas) // spasi bawah
				{
					printf(" ");
					spasi++;
				}
				batas++;
				spasi = 0;

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