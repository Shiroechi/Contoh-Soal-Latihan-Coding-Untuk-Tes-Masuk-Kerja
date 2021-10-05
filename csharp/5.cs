using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Noveldex.Core.Consoles
{
	internal class Program1
	{
		private static void Main(string[] args)
		{
			Console.Write("Masukkan kalimat: ");
			string kalimat = Console.ReadLine();

			// Huruf selain yang pertama dalam kalimat adalah huruf kecil.
			string clean = kalimat.ToLower();

			// hapus spasi di awal dan akhir kalimat
			clean = clean.Trim();

			var sb = new Stack<char>();

			// huruf pertama dalam kalimat, huruf kapital
			sb.Push(char.ToUpper(clean[0]));

			for (var i = 1; i < clean.Length; i++)
			{
				// gabungkang huruf menjadi kata
				if (char.IsLetter(clean[i]) && char.IsLetter(sb.Peek()))
				{
					sb.Push(clean[i]);
				}

				// kasi 1 spasi untuk tiap kata
				else if (char.IsWhiteSpace(clean[i]) && char.IsLetter(sb.Peek()))
				{
					sb.Push(clean[i]);
				}

				// kata baru
				else if (char.IsLetter(clean[i]) && char.IsWhiteSpace(sb.Peek()))
				{
					sb.Push(clean[i]);
				}

				// huruf besar jika sebelumnya simbol . ? !
				else if (char.IsLetter(clean[i]) && char.IsSymbol(sb.Peek()))
				{
					if (sb.Peek() != ',')
					{
						sb.Push(char.ToUpper(clean[i]));
					}
					else
					{
						sb.Push(clean[i]);
					}
				}

				// tambahkan simbol pada akhir kata
				else if (char.IsPunctuation(clean[i]) && char.IsLetter(sb.Peek()))
				{
					sb.Push(clean[i]);
					sb.Push(' '); // tambah spasi tiap akhit tanda baca
				}

				// simbol tapi sebelumnya adalah spasi
				else if (char.IsPunctuation(clean[i]) && char.IsWhiteSpace(sb.Peek()))
				{
					sb.Pop();
					sb.Push(clean[i]);
					sb.Push(' '); // tambah spasi tiap akhit tanda baca
				}
			}

			var builder = new StringBuilder();
			foreach (var item in sb)
			{
				builder.Append(item);
			}
			foreach (var item in builder.ToString().Reverse())
			{
				Console.Write(item);
			}
		}
	}
}
