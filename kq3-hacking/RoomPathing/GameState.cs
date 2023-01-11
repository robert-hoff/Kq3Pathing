using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kq3_hacking.RoomPathing
{
    class GameState
    {
        public static readonly int[] FLY_INTERACTION_AREA = { 0, 0, 0, 0 };
        // ...

        public static readonly (int x, int y) START_POS = (96, 137);

        public int footprintWidth;
        public const int FOOTPRINT_WIDTH_NORMAL = 6;

        public GameState(int footprintWidth = FOOTPRINT_WIDTH_NORMAL)
        {
            this.footprintWidth = footprintWidth;


        }
    }
}


