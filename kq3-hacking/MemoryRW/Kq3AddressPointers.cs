using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kq3_hacking.MemoryRW
{
    class Kq3AddressPointers
    {
        public static int DOSBOX_ADDRESS = 0x400000;
        // may be used to change the Dosbox cycles
        public static int DOSBOX_CYCLES_OFFSET = 0x3FE090;

        public static int KQ3_BASE_OFFSET = 0x1B58E20; // KQ1 base offset for Dosbox ECE r4319
        public static int KQ3_BASE_POINTER = DOSBOX_ADDRESS + KQ3_BASE_OFFSET;

        public static int PLAYER_XPOS_PTR = 0xC7B1;
        public static int PLAYER_YPOS_PTR = 0xC7B2;
        public static int RANDOM_SEED_PTR = 0xDE91;
    }
}

