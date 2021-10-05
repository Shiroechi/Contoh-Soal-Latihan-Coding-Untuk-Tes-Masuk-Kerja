using System;

namespace Sample
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			Console.Write("Masukan n = ");
			var n = int.Parse(Console.ReadLine());

			int middle_index = n / 2;
			for (var i = 0; i < n; i++)
			{
				if (i < middle_index)
				{
					for (int j = 0; j < i + 1; j++)
					{
						Console.Write("*");
					}
				}
				else
				{
					for (int j = 0; j < n - i; j++)
					{
						Console.Write("*");
					}
				}
				Console.WriteLine();
			}
		}
	}
}
