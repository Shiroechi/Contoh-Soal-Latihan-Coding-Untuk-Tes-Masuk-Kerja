# Implementasi UUID v7 Berdasarkan RFC 9562

## Ringkasan

UUID versi 7 (UUIDv7) adalah format UUID yang menyediakan representasi berbasis timestamp yang dapat diurutkan secara kronologis. Implementasi ini mengikuti spesifikasi resmi dari [RFC 9562](https://www.rfc-editor.org/rfc/rfc9562.html).

## Struktur UUIDv7

UUIDv7 memiliki struktur 128-bit sebagai berikut:

```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                           unix_ts_ms                          |
|                             (48 bits)                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          unix_ts_ms           |  ver  |       rand_a          |
|        (12 bits)              | (4)   |       (12 bits)       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|var|                        rand_b                            |
|(2)|                        (62 bits)                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                            rand_b                            |
|                            (64 bits)                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

- `unix_ts_ms`: 48-bit Unix timestamp dalam milidetik sejak 1 Januari 1970 UTC
- `ver`: 4-bit versi (harus 0111 untuk UUIDv7)
- `rand_a`: 12-bit nilai acak
- `var`: 2-bit variant (harus 10 untuk RFC 4122)
- `rand_b`: 74-bit nilai acak tambahan

## Keunggulan UUIDv7

1. **Pengurutan Waktu**: UUIDv7 dapat diurutkan secara kronologis karena mengandung timestamp
2. **Unik**: Kombinasi timestamp dan nilai acak memastikan uniknya UUID
3. **Koleksi Efisien**: Berguna untuk database yang membutuhkan ID unik dengan kemampuan pengurutan waktu

## Implementasi dalam C#

File `UUIDv7.cs` berisi implementasi lengkap dari UUIDv7 dengan fitur:

- Pembuatan UUIDv7 dari waktu saat ini atau waktu tertentu
- Ekstraksi timestamp dari UUIDv7 yang ada
- Validasi versi UUID
- Konversi ke string dan byte array
- Fungsi perbandingan untuk pengurutan

## Contoh Penggunaan

```csharp
// Membuat UUIDv7 dari waktu saat ini
var uuid = UUIDv7.NewUUIDv7();
Console.WriteLine($"UUID: {uuid}");
Console.WriteLine($"Timestamp: {uuid.Timestamp}");
Console.WriteLine($"Versi: {uuid.Version}");

// Membuat UUIDv7 dari waktu tertentu
var pastUuid = UUIDv7.NewUUIDv7(DateTimeOffset.UtcNow.AddHours(-1));
```

## Spesifikasi RFC 9562

Spesifikasi lengkap tersedia di: https://www.rfc-editor.org/rfc/rfc9562.html

## Perbedaan dengan UUID Lainnya

- **UUIDv1**: Menggunakan MAC address yang bisa mengungkapkan identitas perangkat
- **UUIDv4**: Sepenuhnya acak, tidak memiliki informasi waktu
- **UUIDv7**: Kombinasi timestamp dan nilai acak, dapat diurutkan secara kronologis, tanpa informasi perangkat keras