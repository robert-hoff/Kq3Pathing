using static kq3_hacking.MemoryRW.Kq3AddressPointers;

namespace kq3_hacking.MemoryRW
{
    class Kq3ReadWrite
    {
        private int KQ3_BASE_ADDRESS;

        public Kq3ReadWrite()
        {
            MemoryInterface.Initialize("DOSBox");
            KQ3_BASE_ADDRESS = MemoryReadWrite.ReadInt(KQ3_BASE_POINTER);
        }

        public int ReadByte(int ptr)
        {
            return MemoryReadWrite.ReadByte(KQ3_BASE_ADDRESS + ptr);
        }

        public int ReadTwoByte(int ptr)
        {
            return MemoryReadWrite.ReadTwoByte(KQ3_BASE_ADDRESS + ptr);
        }

        public void WriteByte(int val, int ptr)
        {
            MemoryReadWrite.WriteByte(val, KQ3_BASE_ADDRESS + ptr);
        }

        public void WriteTwoByte(int val, int ptr)
        {
            MemoryReadWrite.WriteTwoByte(val, KQ3_BASE_ADDRESS + ptr);
        }

        public void SetRandomSeed(int val)
        {
            MemoryReadWrite.WriteTwoByte(val, KQ3_BASE_ADDRESS + RANDOM_SEED_PTR);
        }
        public int ReadDosboxCycles()
        {
            return MemoryReadWrite.ReadInt(DOSBOX_ADDRESS + DOSBOX_CYCLES_OFFSET);
        }

        public void SetDosboxCycles(int val)
        {
            MemoryReadWrite.WriteInt(val, DOSBOX_ADDRESS + DOSBOX_CYCLES_OFFSET);
        }

    }
}
