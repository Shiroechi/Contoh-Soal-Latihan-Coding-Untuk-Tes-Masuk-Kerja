using System;
using System.Collections.Generic;

namespace Sample
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			Console.Write("Masukkan ukuran array: ");
			var n = int.Parse(Console.ReadLine());

			Console.Write("Masukkan M: ");
			var m = int.Parse(Console.ReadLine());

			int[] arr1 = new int[n];
			int[] arr2 = new int[n];

			// isi array
			FillArray(arr1, m);
			FillArray(arr2, m);

			// menampilkan isi array
			Console.WriteLine("Array 1:");
			Show(arr1);

			Console.WriteLine("\n");
			Console.WriteLine("Array 2:");
			Show(arr2);

			// union dari arr1 dan arr2
			// gabungkan arr1 dan arr2
			var union = new List<int>();
			union.AddRange(arr1);
			union.AddRange(arr2);

			Console.WriteLine("\n");
			Console.WriteLine("Hasil union:");
			Show(union);

			// union cara panjang
			//var union2 = new int[arr1.Length + arr2.Length];
			//for (var i = 0; i < arr1.Length; i ++)
			//{
			//	union2[i] = arr1[i];
			//	union2[i + arr1.Length] = arr2[i];
			//}

			//Console.WriteLine("\n");
			//Console.WriteLine("Hasil union:");
			//Show(union2);

			// cari irisan arr1 dan arr2
			// nilai yang sama dari arr1 dan arr2
			var irisan = new List<int>();
			for (var i = 0; i < arr1.Length; i++)
			{
				for (var j = 0; j < arr2.Length; j++)
				{
					if (arr1[i] == arr2[j])
					{
						irisan.Add(arr1[i]);
					}
				}
			}

			Console.WriteLine("\n");
			Console.WriteLine("Hasil irisan:");
			Show(irisan);

			// mengurangi union dengan irisan
			var arr3 = new List<int>();
			for (var i = 0; i < union.Count; i++)
			{
				if (irisan.Contains(union[i]) == false)
				{
					arr3.Add(union[i]);
				}
			}
			Console.WriteLine("\n");
			Console.WriteLine("Hasil union yang dikurangi irisan:");
			Show(arr3);

		}

		// menampilkan isi array
		public static void Show(int[] arr)
		{
			foreach (var item in arr)
			{
				Console.Write(item);
				Console.Write(" ");
			}
		}

		// menampilkan isi array
		public static void Show<T>(ICollection<T> arr)
		{
			foreach (var item in arr)
			{
				Console.Write(item);
				Console.Write(" ");
			}
		}

		// isi array dengan nilai acak, dan selang-seling genap ganjil
		public static void FillArray(int[] arr, int bound)
		{
			var rand = new Random();
			var dict = new List<int>();

			arr[0] = rand.Next() % bound;
			dict.Add(arr[0]);

			for (var i = 1; i < arr.Length; i++)
			{
				// cek ganjil dengan masking
				if ((arr[i - 1] & 1) == 1)
				{
					// xor bit pertama, supaya selalu genap
					arr[i] = (rand.Next() % bound) ^ 1;

					while (dict.Contains(arr[i]))
					{
						arr[i] = (rand.Next() % bound) ^ 1;
					}

					dict.Add(arr[i]);
				}
				else
				{
					// or bit pertama, semua bilangan dijadikan ganjil
					arr[i] = (rand.Next() % bound) | 1;

					while (dict.Contains(arr[i]))
					{
						arr[i] = (rand.Next() % bound) | 1;
					}

					dict.Add(arr[i]);
				}
			}
		}
	}
}
