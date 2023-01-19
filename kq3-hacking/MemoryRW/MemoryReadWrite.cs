

namespace kq3_hacking.MemoryRW
{

    class MemoryReadWrite
    {
        public struct OneByte
        {
            public byte byte0;
        }
        public struct TwoByte
        {
            public byte byte0;
            public byte byte1;
        }
        public struct Int4Byte
        {
            public int int0;
        }

        public static int ReadByte(int address)
        {
            OneByte data = MemoryInterface.ReadMemory<OneByte>(address);
            return OneByteToInt(data);
        }

        public static int ReadTwoByte(int address)
        {
            TwoByte data = MemoryInterface.ReadMemory<TwoByte>(address);
            return TwoByteToInt(data);
        }

        public static int ReadInt(int address)
        {
            Int4Byte data = MemoryInterface.ReadMemory<Int4Byte>(address);
            return data.int0;
        }

        public static void WriteByte(int val, int address)
        {
            OneByte valOneByte = IntToOneByte(val);
            MemoryInterface.WriteMemory<OneByte>(valOneByte, address);
        }

        public static void WriteTwoByte(int val, int address)
        {
            TwoByte valTwoByte = IntToTwoByte(val);
            MemoryInterface.WriteMemory<TwoByte>(valTwoByte, address);
        }

        public static void WriteInt(int val, int address)
        {
            MemoryInterface.WriteMemory<MemoryReadWrite.Int4Byte>(val, address);
        }

        private static OneByte IntToOneByte(int val)
        {
            OneByte value = new();
            value.byte0 = (byte) (val & 0xFF);
            return value;
        }
        private static int OneByteToInt(OneByte data)
        {
            return (int) data.byte0;
        }

        private static TwoByte IntToTwoByte(int val)
        {
            TwoByte value = new();
            value.byte0 = (byte) (val & 0xFF);
            value.byte1 = (byte) ((val >> 8) & 0xFF);
            return value;
        }

        private static int TwoByteToInt(TwoByte data)
        {
            int b0 = data.byte0;
            int b1 = data.byte1;
            return (b1 << 8) + b0;
        }

        /*
         * TwoByte as signed int, if needed
         *
         */
        private static int TwoByteToSignedInt(TwoByte data)
        {
            int b0 = data.byte0;
            int b1 = data.byte1;
            short res = (short) ((b1 << 8) + b0);
            return (int) res;
        }
    }


}


