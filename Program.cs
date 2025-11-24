using System;
using UUIDs;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Implementasi UUID v7 berdasarkan RFC 9562");
        Console.WriteLine();

        // Buat beberapa UUID v7
        var uuid1 = UUIDv7.NewUUIDv7();
        var uuid2 = UUIDv7.NewUUIDv7();
        var uuid3 = UUIDv7.NewUUIDv7(DateTimeOffset.UtcNow.AddMinutes(-5)); // UUID dari waktu 5 menit yang lalu

        Console.WriteLine($"UUID v7 saat ini: {uuid1}");
        Console.WriteLine($"Versi: {uuid1.Version}");
        Console.WriteLine($"Timestamp: {uuid1.Timestamp}");
        Console.WriteLine($"Valid UUIDv7: {uuid1.IsValid}");
        Console.WriteLine();

        Console.WriteLine($"UUID v7 lain: {uuid2}");
        Console.WriteLine($"Versi: {uuid2.Version}");
        Console.WriteLine($"Timestamp: {uuid2.Timestamp}");
        Console.WriteLine($"Valid UUIDv7: {uuid2.IsValid}");
        Console.WriteLine();

        Console.WriteLine($"UUID v7 5 menit lalu: {uuid3}");
        Console.WriteLine($"Versi: {uuid3.Version}");
        Console.WriteLine($"Timestamp: {uuid3.Timestamp}");
        Console.WriteLine($"Valid UUIDv7: {uuid3.IsValid}");
        Console.WriteLine();

        // Demonstrasi bahwa UUIDv7 dapat diurutkan berdasarkan waktu
        Console.WriteLine("Perbandingan dan pengurutan:");
        Console.WriteLine($"{uuid3} < {uuid1} = {uuid3 < uuid1}"); // Harus true karena uuid3 dibuat lebih awal
        Console.WriteLine($"{uuid1} < {uuid2} = {uuid1 < uuid2}"); // Harus true karena uuid1 dibuat sebelum uuid2

        // Konversi ke byte array
        Console.WriteLine();
        Console.WriteLine("Byte representation dari UUID pertama:");
        var bytes = uuid1.ToByteArray();
        Console.WriteLine(BitConverter.ToString(bytes).Replace("-", " "));
    }
}