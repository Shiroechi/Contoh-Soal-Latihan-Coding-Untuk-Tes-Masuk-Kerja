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
			int max_column_length = n - middle_index;

			for (int i = 0; i < n; i++)
			{
				if (i < middle_index)
				{
					for (int j = 0; j < max_column_length - (i + 1); j++)
					{
						Console.Write(" ");
					}

					for (int j = 0; j < i + 1; j++)
					{
						Console.Write("*");
					}
				}
				else
				{
					int space_count;
					if (n % 2 == 0)
					{
						space_count = i;
					}
					else
					{
						space_count = i + 1;
					}

					for (int j = 0; j < space_count - max_column_length; j++)
					{
						Console.Write(" ");
					}

					for (int j = 0; j < n - i; j++)
					{
						Console.Write("*");
					}
				}
				Console.Write("\n");
			}
		}
	}
}
