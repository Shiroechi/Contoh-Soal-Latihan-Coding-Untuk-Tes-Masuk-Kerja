#include<stdio.h>
#include<math.h>
#include<conio.h> 
#include<stdlib.h> 
#include<time.h>	
#include<string.h>
#include<ctype.h> 

void main()
{
	char kalimat[100], kalimat1[50];
	int index, counter;
	int huruf;
	index = 0; counter = 0;

	//printf("masukan kalimat :");
	//gets(kalimat);

	strcpy(kalimat, "    kuliah  Algoritma  Pemograman  .   Saya   lapar   !");
	puts(kalimat);
	strlwr(kalimat);
	printf("\n");

	printf("panjang kalimat : %d \n", strlen(kalimat));

	//rapikan kalimat dengan space tidak beraturan.
	for (int i = 0; i <= strlen(kalimat); i++)
	{
		if (isspace(kalimat[i]) && isalpha(kalimat[i + 1]) && counter == 0)
		{
			huruf = kalimat[i + 1];
			kalimat1[index] = huruf;
			index++;
			i++;
			counter++;
			//printf("%c \n", kalimat[i]);
			//printf("%c \n", kalimat1[index]);
		}
		else if (isspace(kalimat[i]) && isalpha(kalimat[i + 1]))
		{
			huruf = ' ';
			kalimat1[index] = huruf;
			index++;
			huruf = kalimat[i + 1];
			kalimat1[index] = huruf;
			index++;
			i++;
			//printf("%c \n", kalimat[i]);
			//printf("%c \n", kalimat1[index]);
		}
		/*else if (isspace(kalimat[i]) && isspace(kalimat[i + 1]))
		{
			i++;
		}*/
		else if (isalpha(kalimat[i]))
		{
			/*if (kalimat[i - 1] == ' ')
			{
				huruf = ' ';
				kalimat1[index] = huruf;
				index++;
			}*/
			huruf = kalimat[i];
			kalimat1[index] = huruf;
			index++;
			//printf("%c \n", kalimat[i]);
			//printf("%c \n", kalimat1[index]);
		}
		else if (kalimat[i] == '!' || kalimat[i] == '.' || kalimat[i] == ',' || kalimat[i] == '?')
		{
			huruf = kalimat[i];
			kalimat1[index] = huruf;
			index++;
		}
		/*else if (isalpha(kalimat[i]) && isspace(kalimat[i + 1]) && (kalimat[i + 1] == '!' || kalimat[i + 1] == '.' || kalimat[i + 1] == ',' || kalimat[i + 1] == '?'))
		{
			huruf = kalimat[i + 1];
			kalimat1[index] = huruf;
			index++;
		}
		else if (isspace(kalimat[i]) && isalpha(kalimat[i + 1]) && (kalimat[i - 1] == '!' || kalimat[i - 1] == '.' || kalimat[i - 1] == ',' || kalimat[i - 1] == '?'))
		{
			huruf = ' ';
			kalimat1[index] = huruf;
			index++;
			huruf = kalimat[i + 1];
			kalimat1[index] = huruf;
			index++;
			i++;
		}*/
		else if (i == strlen(kalimat))
		{
			//huruf = kalimat[i];
			//kalimat1[index] = huruf;
			//index++;
			huruf = '\0';
			kalimat1[index] = huruf;
		}
	}
	printf("Hasil 1 = \n");
	puts(kalimat1);
	printf("\n");

	printf("hasil akhir = \n");
	for (int i = 0; i <= strlen(kalimat1); i++)
	{
		if (i == 0)
		{
			printf("%c", toupper(kalimat1[i]));
		}
		/*else if (kalimat[i] == '?' || kalimat[i] == '.' || kalimat[i] == ',' || kalimat[i] == '!')
		{
			if (kalimat[i] == '!' || kalimat[i] == '?' || kalimat[i] == '.')
			{
				printf("%c", kalimat1[i]);
				printf("%c", kalimat1[i + 1]);
				i++;
				i++;
				printf("%c", toupper(kalimat1[i]));
			}
			else
			{
				printf("%c", kalimat1[i]);
			}
		}*/
		else if (isalpha(kalimat[i]) && isspace(kalimat[i - 1]) && (kalimat[i - 2] == '?' || kalimat[i - 2] == '.' || kalimat[i - 2] == '!'))
		{
			printf("%c", toupper(kalimat[i]));
		}
		else if (i > 0)
		{
			printf("%c", kalimat1[i]);
		}
	}


	getch();
}