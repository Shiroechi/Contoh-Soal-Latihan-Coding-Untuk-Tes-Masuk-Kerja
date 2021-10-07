using System;

namespace Sample
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			Console.Write("Masukan n = ");
			var n = int.Parse(Console.ReadLine());

			char ascii = 'a';
			for (var i = 0; i < n; i++)
			{
				for (var j = 0; j < 10; j++)
				{
					Console.Write(ascii);
					ascii++;

					if (ascii > 'z')
					{
						ascii = 'a';
					}
				}
				Console.WriteLine();
			}
		}
	}
}
