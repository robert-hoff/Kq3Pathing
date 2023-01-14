using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kq3_hacking.RoomPathing
{
    class TestPathFinder
    {

        public static void RunTrials()
        {
            // StartToCupPickup();
            // StartToSpoonPickup();
            // StartToBowlPickup();
            CupToSpoon();
        }

        public static void StartToCupPickup()
        {
            PathFinder pathFinder = new();
            pathFinder.SetGoalRegion(8, GameState.CUP_PICKUP_AREA);
            pathFinder.FindPathsFrom(roomNr: 7, 96, 137, MAXDEPTH: 8, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: true);
        }

        public static void StartToSpoonPickup()
        {
            PathFinder pathFinder = new();
            pathFinder.SetGoalRegion(6, GameState.KNIFE_SPOON_PICKUP_AREA);
            pathFinder.FindPathsFrom(roomNr: 7, 96, 137, MAXDEPTH: 8, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: true);
        }

        public static void StartToBowlPickup()
        {
            PathFinder pathFinder = new();
            pathFinder.SetGoalRegion(6, GameState.BOWL_PICKUP_AREA);
            pathFinder.FindPathsFrom(roomNr: 7, 96, 137, MAXDEPTH: 10, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: true);
        }

        /*
         * E  S NW  E NW arriving at (62,124)(6)
         *
         */
        public static void CupToSpoon()
        {
            PathFinder pathFinder = new();
            pathFinder.SetGoalRegion(6, GameState.KNIFE_SPOON_PICKUP_AREA);
            pathFinder.FindPathsFrom(roomNr: 8, 66, 148, MAXDEPTH: 8, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: true);
        }


    }
}
