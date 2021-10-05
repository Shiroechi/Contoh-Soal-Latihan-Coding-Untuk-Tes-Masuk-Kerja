using System;

namespace Sample
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			int Jam_Kerja_Normal = 40;
			int Jam_Kerja_Lembur = 60;
			double Bonus_Upah_Liburan = 1.5;
			double Bonus_Upah_Lembur = 1.8;

			double Asuransi_Kesehatan = 0.07;

			double Penghasilan_Tidak_Kena_Pajak = 100_000;
			double Penghasilan_Kena_Pajak_1 = 200_000;
			double Penghasilan_Kena_Pajak_2 = 300_000;
			double Penghasilan_Kena_Pajak_3 = 600_000;

			double Pajak_Penghasilan_1 = 0.05; // 5%
			double Pajak_Penghasilan_2 = 0.1; // 10%
			double Pajak_Penghasilan_3 = 0.2; // 20%
			double Pajak_Penghasilan_4 = 0.3; // 30%

			Console.Write("Total jam kerja: ");
			var Total_Jam_Kerja = int.Parse(Console.ReadLine());

			Console.Write("Upah per jam: ");
			var Upah_per_Jam = int.Parse(Console.ReadLine());

			// cek total jam dan upah per jam valid atau tidak
			// jika tidak sesuai berhentikan program
			if (Total_Jam_Kerja > 84 || Total_Jam_Kerja <= 0)
			{
				// kerja lebih dari 1 minggu
				// 1 minggu = 84 jam
				Console.WriteLine("Total jam kerja hanya boleh 1 hingga 84.");
				return;
			}

			if (Upah_per_Jam <= 0)
			{
				Console.WriteLine("Upah per jam tidak boleh kurang dari 0.");
				return;
			}

			double Gaji_Kotor = 0;

			Console.WriteLine("Gaji Kotor:");

			if (Total_Jam_Kerja > Jam_Kerja_Lembur)
			{
				// waktu kerja > 60 jam 
				Gaji_Kotor = Jam_Kerja_Normal * Upah_per_Jam; // upah normal
				Console.WriteLine($"{ Jam_Kerja_Normal } x { Upah_per_Jam } = { Gaji_Kotor }");

				Gaji_Kotor += 20 * (Upah_per_Jam * Bonus_Upah_Liburan); // upah hari libur
				Console.WriteLine($"20 x { Upah_per_Jam } x { Bonus_Upah_Liburan } = { 20 * (Upah_per_Jam * Bonus_Upah_Liburan) }");

				Gaji_Kotor += (Total_Jam_Kerja - Jam_Kerja_Lembur) * (Upah_per_Jam * Bonus_Upah_Lembur); // upah lembur
				Console.WriteLine($"{ (Total_Jam_Kerja - Jam_Kerja_Lembur) } x { Upah_per_Jam } x { Bonus_Upah_Lembur } = { (Total_Jam_Kerja - Jam_Kerja_Lembur) * (Upah_per_Jam * Bonus_Upah_Lembur) }");
			}
			else if (Total_Jam_Kerja > Jam_Kerja_Normal && Total_Jam_Kerja < Jam_Kerja_Lembur)
			{
				// waktu kerja > 40 jam dan waktu kerja < 60 jam
				Gaji_Kotor = Jam_Kerja_Normal * Upah_per_Jam; // upah normal
				Console.WriteLine($"{ Jam_Kerja_Normal } x { Upah_per_Jam } = { Gaji_Kotor }");

				Gaji_Kotor += (Total_Jam_Kerja - Jam_Kerja_Normal) * (Upah_per_Jam * Bonus_Upah_Liburan); // upah hari libur
				Console.WriteLine($"{ (Total_Jam_Kerja - Jam_Kerja_Normal) } x { Upah_per_Jam } x { Bonus_Upah_Liburan } = { (Total_Jam_Kerja - Jam_Kerja_Normal) * (Upah_per_Jam * Bonus_Upah_Liburan) }");
			}
			else
			{
				// waktu kerja <= 40 jam
				Gaji_Kotor = Total_Jam_Kerja * Upah_per_Jam; // upah normal
				Console.WriteLine($"{ Total_Jam_Kerja } x { Upah_per_Jam } = { Gaji_Kotor }");
			}

			Console.WriteLine($"Gaji kotor: { Gaji_Kotor }");
			Console.WriteLine();

			// hitung pajak
			double Pajak = 0;
			bool Kena_Pajak = true;

			Console.WriteLine("Penghitungan pajak:");

			double temp = 0;

			if (Gaji_Kotor > Penghasilan_Tidak_Kena_Pajak)
			{
				temp = Gaji_Kotor - Penghasilan_Tidak_Kena_Pajak;
				Console.WriteLine($"{ Penghasilan_Tidak_Kena_Pajak } tidak kena pajak.");
			}
			else
			{
				Kena_Pajak = false;
				Console.WriteLine($"{ Gaji_Kotor } tidak kena pajak.");
			}

			if (temp > Penghasilan_Kena_Pajak_1)
			{
				temp -= Penghasilan_Kena_Pajak_1;
				Pajak = Penghasilan_Kena_Pajak_1 * Pajak_Penghasilan_1;
				Console.WriteLine($"{ Penghasilan_Kena_Pajak_1 } x { Pajak_Penghasilan_1 } = { Pajak }");
			}
			else if (Kena_Pajak)
			{
				Pajak = temp * Pajak_Penghasilan_1;
				Console.WriteLine($"{ temp } x { Pajak_Penghasilan_1 } = { Pajak }");
			}

			if (temp > Penghasilan_Kena_Pajak_2)
			{
				temp -= Penghasilan_Kena_Pajak_2;
				Pajak += Penghasilan_Kena_Pajak_2 * Pajak_Penghasilan_2;
				Console.WriteLine($"{ Penghasilan_Kena_Pajak_2 } x { Pajak_Penghasilan_2 } = { Penghasilan_Kena_Pajak_2 * Pajak_Penghasilan_2 }");
			}
			else if (Kena_Pajak)
			{
				Pajak += temp * Pajak_Penghasilan_2;
				Console.WriteLine($"{ temp } x { Pajak_Penghasilan_2 } = { temp * Pajak_Penghasilan_2 }");
			}

			if (temp > Penghasilan_Kena_Pajak_3)
			{
				temp -= Penghasilan_Kena_Pajak_3;
				Pajak += Penghasilan_Kena_Pajak_3 * Pajak_Penghasilan_3;
				Console.WriteLine($"{ Penghasilan_Kena_Pajak_3 } x { Pajak_Penghasilan_3 } = { Penghasilan_Kena_Pajak_3 * Pajak_Penghasilan_3 }");

				// penghasilan yang kena pajak
				// jika masih ada sisa
				if (temp > 0)
				{
					Pajak += temp * Pajak_Penghasilan_4;
					Console.WriteLine($"{ temp } x { Pajak_Penghasilan_4 } = { temp * Pajak_Penghasilan_4 }");
				}
			}
			else if (Kena_Pajak)
			{
				Pajak += temp * Pajak_Penghasilan_3;
				Console.WriteLine($"{ temp } x { Pajak_Penghasilan_3 } = { temp * Pajak_Penghasilan_3 }");
			}

			Console.WriteLine($"Total pajak: {  Pajak }");
			Console.WriteLine();

			var Biaya_Asuransi = Gaji_Kotor * Asuransi_Kesehatan;
			Console.WriteLine($"Biaya asuransi: { Gaji_Kotor } x { Asuransi_Kesehatan } = { Biaya_Asuransi }");

			var Gaji_Bersih = Gaji_Kotor - Pajak - Biaya_Asuransi;
			Console.WriteLine($"Gaji bersih = { Gaji_Bersih }");
		}
	}
}
