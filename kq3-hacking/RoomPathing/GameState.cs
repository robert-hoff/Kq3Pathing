using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kq3_hacking.RoomPathing
{
    class GameState
    {
        public static readonly int[] WHOLE_ROOM = { 0, 0, 159, 167 };
        public static readonly int[] FLY_INTERACTION_AREA = { 0, 0, 0, 0 };
        public static readonly int[] CUP_PICKUP_AREA = { 62, 126, 80, 150 };
        public static readonly int[] FOOD_PICKUP_AREA = { 111, 124, 159, 150 };
        public static readonly int[] KNIFE_SPOON_PICKUP_AREA = { 55, 123, 70, 133 };
        public static readonly int[] BOWL_PICKUP_AREA = { 10, 123, 54, 133 };

        public const int START_ROOM = 7;
        public static readonly (int x, int y, int roomNr) START_POS = (96, 137, 7);



        public const int FOOTPRINT_WIDTH_NORMAL = 7;
        public int footprintWidth;

        private bool[] stateDescription = new bool[2];
        public const int TRAPDOOR_OPEN = 1;


        public GameState(int footprintWidth = FOOTPRINT_WIDTH_NORMAL)
        {
            this.footprintWidth = footprintWidth;
            stateDescription[TRAPDOOR_OPEN] = false;
        }

        public void SetTrapDoorOpen(bool trapDoorOpen)
        {
            stateDescription[TRAPDOOR_OPEN] = trapDoorOpen;
        }
        public bool IsTrapDoorOpen()
        {
            return stateDescription[TRAPDOOR_OPEN];
        }

        public GameState CloneState()
        {
            GameState gameState = new GameState();
            gameState.footprintWidth = footprintWidth;
            for (int i = 0; i < stateDescription.Length; i++)
            {
                gameState.stateDescription[i] = stateDescription[i];
            }
            return gameState;
        }
    }
}


