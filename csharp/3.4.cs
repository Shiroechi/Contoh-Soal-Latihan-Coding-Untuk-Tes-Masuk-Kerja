using System;

namespace Sample
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			Console.Write("Masukan n = ");
			var n = int.Parse(Console.ReadLine());

			int middle_index = n;
			for (int k = 0; k < n; k++)
			{
				for (int i = 0; i < n - k; i++)
				{
					// print persegi
					for (int j = 0; j < n - k; j++)
					{
						Console.Write("*");
					}

					Console.Write(" ");

					// print segitiga
					for (int j = 0; j < n - k - i; j++)
					{
						Console.Write("*");
					}

					Console.Write("\n");
				}
				Console.Write("\n");
			}
		}
	}
}
