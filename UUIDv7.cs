using System;
using System.Buffers.Binary;
using System.Runtime.InteropServices;
using System.Security.Cryptography;

namespace UUIDs
{
    /// <summary>
    /// Implementation of UUID version 7 based on RFC 9562
    /// </summary>
    public readonly struct UUIDv7 : IEquatable<UUIDv7>, IComparable<UUIDv7>
    {
        private readonly ulong _low;
        private readonly ulong _high;

        /// <summary>
        /// Creates a new UUIDv7 with the current timestamp
        /// </summary>
        public static UUIDv7 NewUUIDv7()
        {
            return NewUUIDv7(DateTimeOffset.UtcNow);
        }

        /// <summary>
        /// Creates a new UUIDv7 with the specified timestamp
        /// </summary>
        /// <param name="timestamp">The timestamp to use (in UTC)</param>
        public static UUIDv7 NewUUIDv7(DateTimeOffset timestamp)
        {
            // Convert timestamp to milliseconds since Unix epoch (48 bits)
            var timestampMs = (ulong)(timestamp.ToUnixTimeMilliseconds() & 0x0000FFFFFFFFFFFF);

            // Generate random bits (74 bits after accounting for version and variant bits)
            Span<byte> randomBytes = stackalloc byte[16];
            RandomNumberGenerator.Fill(randomBytes);

            // Pack the UUIDv7 structure according to RFC 9562:
            // - Bytes 0-5 (bits 0-47): 48-bit Unix timestamp in milliseconds
            // - Bytes 6-7 (bits 48-63): Version (4 bits) and random (12 bits)
            //   - Bits 48-51: Version = 0111 (7)
            //   - Bits 52-63: Random
            // - Bytes 8-15 (bits 64-127): Variant and random
            //   - Bits 64-65: Variant = 10
            //   - Bits 66-127: Random
            
            Span<byte> bytes = stackalloc byte[16];
            
            // First 6 bytes: timestamp (48 bits)
            bytes[0] = (byte)((timestampMs >> 40) & 0xFF);
            bytes[1] = (byte)((timestampMs >> 32) & 0xFF);
            bytes[2] = (byte)((timestampMs >> 24) & 0xFF);
            bytes[3] = (byte)((timestampMs >> 16) & 0xFF);
            bytes[4] = (byte)((timestampMs >> 8) & 0xFF);
            bytes[5] = (byte)(timestampMs & 0xFF);

            // Byte 6: high 4 bits = version (0111), low 4 bits = high 4 bits of random
            bytes[6] = (byte)(0x70 | (randomBytes[0] & 0x0F)); // Version 7

            // Byte 7: all 8 bits = low 8 bits of random
            bytes[7] = randomBytes[1];

            // Byte 8: high 2 bits = variant (10), remaining 6 bits = random
            bytes[8] = (byte)(0x80 | (randomBytes[2] & 0x3F)); // RFC 4122 variant

            // Bytes 9-15: remaining random bits
            for (int i = 0; i < 7; i++)
            {
                bytes[9 + i] = randomBytes[3 + i];
            }

            return new UUIDv7(bytes);
        }

        private UUIDv7(ReadOnlySpan<byte> bytes)
        {
            if (bytes.Length != 16)
                throw new ArgumentException("UUID must be 16 bytes", nameof(bytes));

            // Store as two 64-bit values for efficient comparison and operations
            _high = BinaryPrimitives.ReadUInt64BigEndian(bytes);
            _low = BinaryPrimitives.ReadUInt64BigEndian(bytes[8..]);
        }

        /// <summary>
        /// Creates a UUIDv7 from bytes
        /// </summary>
        public static UUIDv7 FromBytes(ReadOnlySpan<byte> bytes)
        {
            return new UUIDv7(bytes);
        }

        /// <summary>
        /// Gets the timestamp component of this UUIDv7
        /// </summary>
        public DateTimeOffset Timestamp
        {
            get
            {
                // Extract the timestamp from the first 6 bytes
                Span<byte> temp = stackalloc byte[8];
                BinaryPrimitives.WriteUInt64BigEndian(temp, _high);
                
                // Clear the version bits and extract timestamp
                temp[6] = (byte)(temp[6] & 0x0F);
                temp[7] = (byte)0x00;
                
                var timestampMs = BinaryPrimitives.ReadUInt64BigEndian(temp) >> 16;
                return DateTimeOffset.FromUnixTimeMilliseconds((long)timestampMs);
            }
        }

        /// <summary>
        /// Gets the version of this UUID (should be 7 for UUIDv7)
        /// </summary>
        public int Version
        {
            get
            {
                Span<byte> temp = stackalloc byte[8];
                BinaryPrimitives.WriteUInt64BigEndian(temp, _high);
                return (temp[6] >> 4) & 0x0F;
            }
        }

        /// <summary>
        /// Checks if this UUID is a valid UUIDv7
        /// </summary>
        public bool IsValid => Version == 7;

        /// <summary>
        /// Converts this UUIDv7 to a byte array
        /// </summary>
        public byte[] ToByteArray()
        {
            var bytes = new byte[16];
            BinaryPrimitives.WriteUInt64BigEndian(bytes, _high);
            BinaryPrimitives.WriteUInt64BigEndian(bytes[8..], _low);
            return bytes;
        }

        /// <summary>
        /// Returns a string representation of this UUIDv7 in canonical format
        /// </summary>
        public override string ToString()
        {
            var bytes = new byte[16];
            BinaryPrimitives.WriteUInt64BigEndian(bytes, _high);
            BinaryPrimitives.WriteUInt64BigEndian(bytes[8..], _low);

            // Format as standard UUID string: xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
            return $"{bytes[0]:x2}{bytes[1]:x2}{bytes[2]:x2}{bytes[3]:x2}-" +
                   $"{bytes[4]:x2}{bytes[5]:x2}-" +
                   $"{bytes[6]:x2}{bytes[7]:x2}-" +
                   $"{bytes[8]:x2}{bytes[9]:x2}-" +
                   $"{bytes[10]:x2}{bytes[11]:x2}{bytes[12]:x2}{bytes[13]:x2}{bytes[14]:x2}{bytes[15]:x2}";
        }

        public bool Equals(UUIDv7 other)
        {
            return _high == other._high && _low == other._low;
        }

        public override bool Equals(object obj)
        {
            return obj is UUIDv7 other && Equals(other);
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(_high, _low);
        }

        public int CompareTo(UUIDv7 other)
        {
            var cmp = _high.CompareTo(other._high);
            return cmp != 0 ? cmp : _low.CompareTo(other._low);
        }

        public static bool operator ==(UUIDv7 left, UUIDv7 right) => left.Equals(right);
        public static bool operator !=(UUIDv7 left, UUIDv7 right) => !left.Equals(right);
        public static bool operator <(UUIDv7 left, UUIDv7 right) => left.CompareTo(right) < 0;
        public static bool operator >(UUIDv7 left, UUIDv7 right) => left.CompareTo(right) > 0;
    }
}