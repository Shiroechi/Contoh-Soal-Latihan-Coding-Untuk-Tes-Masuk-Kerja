#include<stdio.h>
#include<math.h>
#include<conio.h>

void main()
{
	int jam, gaji, pajak, asuransi, gajikotor, sisa, jam1, jam2, jamsisa
		, pajak1, pajak2, pajak3, pajak4, gajibersih;
	float bunga1, bunga2, bunga3, bunga4, bunga5, minggu, lembur;

	jam1 = 40;
	jam2 = 20;
	minggu = 1.5;
	lembur = 1.8;
	pajak = 0;
	pajak1 = 100000; bunga1 = 0.05;
	pajak2 = 200000; bunga2 = 0.1;
	pajak3 = 300000; bunga3 = 0.2;
	pajak4 = 600000; bunga4 = 0.3;
					 bunga5 = 0.07;

	printf("penghitungan gaji per minggu\n");

	printf("jumlah jam kerja :");
	scanf("%d", &jam);

	printf("gaji perjam :");
	scanf("%d", &gaji);

	if (jam > 84 && gaji < 0)
	{
		printf("data tidak valid");
		printf("jam kerja melebihi syarat maksimum ");
		printf("gaji tidak boleh minus (negatif)");
	}
	else if (jam <= 84 && gaji < 0)
	{
		printf("data tidak valid");
		printf("gaji tidak boleh minus (negatif)");
	}
	else if (jam > 84 && gaji < 0)
	{
		printf("data tidak valid");
		printf("jam kerja melebihi syarat maksimum ");
	}
	else
	{
		if (jam < 40)
		{
			printf("gaji kotor :\n");
			printf("%d ", jam);
			printf("x ");
			printf("%d ", gaji);
			printf("= ");
			printf("%d\n", jam*gaji);
			gajikotor = jam*gaji;
			printf("gaji kotor = %d\n\n", gajikotor);
		}
		else if (jam > 40 && jam < 60)
		{
			jamsisa = jam - jam1;
			printf("gaji kotor :\n");
			printf("%d ", jam1);
			printf("x ");
			printf("%d ", gaji);
			printf("= ");
			printf("%d\n", jam1*gaji);

			printf("%d ", jamsisa);
			printf("x ");
			printf("%d ", gaji);
			printf("x ");
			printf("%.2f ", minggu);
			printf("= ");
			printf("%.2f\n", jamsisa*gaji*minggu);
			gajikotor = (jam1*gaji) + (jamsisa*gaji*minggu);
			printf("gaji kotor = %d\n\n", gajikotor);
		}
		else if (jam > 40 && jam <= 84)
		{
			jamsisa = jam - jam1 - jam2;
			printf("gaji kotor :\n");
			printf("%d ", jam1);
			printf("x ");
			printf("%d ", gaji);
			printf("= ");
			printf("%d\n", jam1*gaji);

			printf("%d ", jam2);
			printf("x ");
			printf("%d ", gaji);
			printf("x ");
			printf("%.2f ", minggu);
			printf("= ");
			printf("%.2f\n", jam2*gaji*minggu);

			printf("%d ", jamsisa);
			printf("x ");
			printf("%d ", gaji);
			printf("x ");
			printf("%.2f ", lembur);
			printf("= ");
			printf("%.2f\n ", jam2*gaji*lembur);
			gajikotor = (jam1*gaji) + (jam2*gaji*minggu) + (jamsisa*gaji*lembur);
			printf("gaji kotor = %d\n\n", gajikotor);
		}

		if (gajikotor <= 100000)
		{
			printf("penghitungan pajak :\n");
			printf("%d",gajikotor);
			printf(" ");
			printf("tidak kena pajak\n\n");

			printf("biaya asuransi :\n");
			printf("%d ", gajikotor);
			printf("x ");
			printf("%.2f ", bunga5);
			printf("= ");
			asuransi = gajikotor*bunga5;
			printf("%d\n\n", asuransi);

			printf("gaji bersih =");
			printf("%d ", gajikotor);
			printf("- ");
			printf("%d ", pajak);
			printf("- ");
			printf("%d ", asuransi);
			printf("= ");
			gajibersih = gajikotor - pajak - asuransi;
			printf("%d\n", gajibersih);
		}
		else if (gajikotor <= 200000)
		{
			printf("penghitungan pajak :\n");
			sisa = gajikotor - 100000;
			printf("%d", pajak1);
			printf(" ");
			printf("tidak kena pajak\n");
			printf("%d ", sisa);
			printf("x ");
			printf("%.2f ", bunga1);
			printf("= ");
			printf("%.2f ", sisa * bunga1);
			pajak = sisa * bunga1;
			printf("total pajak = %d\n\n", pajak);

			printf("biaya asuransi :\n");
			printf("%.2f ", gajikotor);
			printf("x ");
			printf("%.2f ", bunga5);
			printf("= ");
			asuransi = gajikotor*bunga5;
			printf("%d\n\n", asuransi);

			printf("gaji bersih =");
			printf("%d ", gajikotor);
			printf("- ");
			printf("%d ", pajak);
			printf("- ");
			printf("%d ", asuransi);
			printf("= ");
			gajibersih = gajikotor - pajak - asuransi;
			printf("%d\n", gajibersih);
		}
		else if (gajikotor <= 300000)
		{
			printf("penghitungan pajak :\n");
			sisa = gajikotor - 100000 - 200000;
			printf("%d", pajak1);
			printf(" ");
			printf("tidak kena pajak\n");
			printf("%d ", pajak2);
			printf("x ");
			printf("%.2f ", bunga1);
			printf("= ");
			printf("%.2f\n", pajak2 * bunga1);
			printf("%d ", sisa);
			printf("x ");
			printf("%.2f ", bunga2);
			printf("= ");
			printf("%.2f\n", sisa * bunga2);
			pajak = (pajak2 * bunga1) + (sisa * bunga2);
			printf("total pajak = %d\n\n", pajak);

			printf("biaya asuransi :\n");
			printf("%d ", gajikotor);
			printf("x ");
			printf("%.2f ", bunga5);
			printf("= ");
			asuransi = gajikotor*bunga5;
			printf("%d\n\n", asuransi);

			printf("gaji bersih =");
			printf("%d ", gajikotor);
			printf("- ");
			printf("%d ", pajak);
			printf("- ");
			printf("%d ", asuransi);
			printf("= ");
			gajibersih = gajikotor - pajak - asuransi;
			printf("%d\n", gajibersih);
		}
		else if (gajikotor <= 600000 || gajikotor < 1200000)
		{
			printf("penghitungan pajak :\n");
			sisa = gajikotor - 100000 - 200000 - 300000;
			printf("%d", pajak1);
			printf(" ");
			printf("tidak kena pajak\n");
			printf("%d ", pajak2);
			printf("x ");
			printf("%.2f ", bunga1);
			printf("= ");
			printf("%.2f\n", pajak2 * bunga1);
			printf("%d ", pajak3);
			printf("x ");
			printf("%.2f ", bunga2);
			printf("= ");
			printf("%.2f\n", pajak3 * bunga2);
			printf("%d", sisa);
			printf("x");
			printf("%.2f ", bunga3);
			printf("= ");
			printf("%.2f\n", sisa * bunga3);
			pajak = (pajak2 * bunga1) + (pajak3 * bunga2) + (sisa * bunga3);
			printf("total pajak = %d\n\n", pajak);

			printf("biaya asuransi :\n");
			printf("%d ", gajikotor);
			printf("x ");
			printf("%d ", bunga5);
			printf("= ");
			asuransi = gajikotor*bunga5;
			printf("%d\n\n", asuransi);

			printf("gaji bersih =");
			printf("%d ", gajikotor);
			printf("- ");
			printf("%d ", pajak);
			printf("- ");
			printf("%d ", asuransi);
			printf("= ");
			gajibersih = gajikotor - pajak - asuransi;
			printf("%d\n\n", gajibersih);
		}
		else if (gajikotor > 1200000)
		{
			printf("penghitungan pajak :\n");
			sisa = gajikotor - 100000 - 200000 - 300000 - 600000;
			printf("%d ", pajak1);
			printf(" ");
			printf("tidak kena pajak\n");
			printf("%d ", pajak2);
			printf("x ");
			printf("%.2f ", bunga1);
			printf("= ");
			printf("%.2f\n", pajak2 * bunga1);
			printf("%d ", pajak3);
			printf("x ");
			printf("%.2f ", bunga2);
			printf("= ");
			printf("%.2f\n", pajak3 * bunga2);
			printf("%d ", pajak4);
			printf("x ");
			printf("%.2f ", bunga3);
			printf("= ");
			printf("%.2f\n", pajak4 * bunga3);
			printf("%d ", sisa);
			printf("x ");
			printf("%.2f ", bunga4);
			printf("= ");
			printf("%.2f\n", sisa * bunga4);
			pajak = (pajak2 * bunga1) + (pajak3 * bunga2) + (pajak4 * bunga3) + (sisa * bunga4);
			printf("total pajak = %d\n\n", pajak);

			printf("biaya asuransi :\n");
			printf("%d ", gajikotor);
			printf("x ");
			printf("%.2f ", bunga5);
			printf("= ");
			asuransi = gajikotor*bunga5;
			printf("%d\n\n", asuransi);

			printf("gaji bersih =");
			printf("%d ", gajikotor);
			printf("- ");
			printf("%d ", pajak);
			printf("- ");
			printf("%d ", asuransi);
			printf("= ");
			gajibersih = gajikotor - pajak - asuransi;
			printf("%d\n", gajibersih);
		}
	}
	getch();
	
}
