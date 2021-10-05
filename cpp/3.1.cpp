#include<stdio.h>

// n: 5
// abcdefghij
// klmnopqrst
// uvwxyzabcd
// efghijklmn
// opqrstuvwx

int main()
{
	int n;
	printf("Masukan ukuran n: ");
	scanf("%d", &n);

	char character = 'a';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%c", character);

			// Karakter berikutnya
			character = character + 1;

			if (character > 'z')
			{
				character = 'a';
			}
		}
		printf("\n");
	}

	return 0;
}
