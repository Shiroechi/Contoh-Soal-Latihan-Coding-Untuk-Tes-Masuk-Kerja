#include <stdio.h>

int main()
{
    int n;
	printf("n: ");
	scanf("%d", &n);

    int bonus = n / 5.0;

    int temp_bonus = bonus;
    int bonus_tambahan = 0;
    while (temp_bonus > 4)
    {
        bonus_tambahan = bonus_tambahan + temp_bonus / 5.0;
        temp_bonus = temp_bonus / 5.0;
    }

    printf("Bonus permen yang didapat: %d", bonus + bonus_tambahan);

    return 0;
}
