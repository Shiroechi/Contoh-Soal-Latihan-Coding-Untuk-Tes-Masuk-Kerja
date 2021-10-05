using System;

namespace Sample
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			Console.Write("Masukkan jumlah permen yang dibeli: ");
			var permen = int.Parse(Console.ReadLine());

			var bonus = Math.Floor(permen / 5.0);
			var total_bonus = bonus;
			while (bonus > 0)
			{
				bonus = Math.Floor(bonus / 5.0);
				total_bonus += bonus;

				if (bonus < 4)
				{
					break;
				}
			}

			Console.WriteLine($"Bonus permen yang didapat: { total_bonus }");
		}
	}
}
