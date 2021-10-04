#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void main ()
{
	int data[10], n, m, ganjil, genap;
	bool a=true;

	ganjil = 0; genap = 0;

	while (true)
	{
		printf("masukan n :");
		scanf("%d", &n);
		
		printf("masukan m :");
		scanf("%d", &m);

		if (n<=m)
		{
			break;
		}
	}
	
	srand (time(NULL));

	for (int i = 0 ; i < n ; i++)
	{
		if (i==0)
		{
			data[i] = rand () % m ;

			if (data[i] % 2 == 0)
			{
				genap++;
			}
			else if (data[i] % 2 == 1)
			{
				ganjil++;
			}
		}

		if (ganjil > 0)
		{
			data[i] = rand () % m;
			if (data[i] % 2 == 1)
			{
				ganjil--;
				genap++;
			}
			else 
			{
				while (data[i] % 2 == 1)
				{
					data[i] = rand () % m;

					if (data[i] % 2 == 1)
					{
					ganjil--;
					genap++;
					}
				}
			}
		}
		else if (genap > 0)
		{
			data [i] = rand () % m;
			if (data[i] % 2 == 0 )
			{
				genap--;
				ganjil++;
			}
			else 
			{
				while(data[i] % 2 == 0)
				{
					data[i] = rand() % m;

					if (data[i] % 2 == 0 )
					{
						genap--;
						ganjil++;
					}
				}
			}
		}
		//cek kembar atau tidak 
		/*bool kmbr = false;
		do {
			data[i] = rand() % m;
			kmbr = false;
			for (int j = 0; j < i; j++)
			{
				if (data[i] == data[j])
				{
					kmbr = true;
				}
				
			}

		} while (kmbr || genapganjiltidakcocok);*/
	}

	//menampilkan data
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d", data[i]);
		printf(" ");
	}



	getch();
}