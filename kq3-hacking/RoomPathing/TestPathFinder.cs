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
            // TopOfStairsToExit();
            BedroomExitToDownstairs();
            // BedroomEntryToMapPickup();
            // UpstairsToWizBedroom();
            // StartToUpstairs();
            // StartToCupPickup();
            // StartToSpoonPickup();
            // StartToBowlPickup();
            // CupToSpoon();
        }


        public static void TopOfStairsToExit()
        {
            PathFinder pathFinder = new();
            // pathFinder.SetGoalRegion(34, GameState.WHOLE_ROOM);
            // south-exit (which is the only viable one)
            pathFinder.SetGoalTargetPosition(34, 39, 152);

            // there are 9-length solutions from here
            // pathFinder.FindPathsFrom(roomNr: 35, 79, 62, MAXDEPTH: 10, stopPathOnSolution: true);

            // only 10-length from here
            // pathFinder.FindPathsFrom(roomNr: 35, 95, 50, MAXDEPTH: 10, stopPathOnSolution: true);

            // and only 10-length from here
            // pathFinder.FindPathsFrom(roomNr: 35, 97, 48, MAXDEPTH: 10, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: false);
        }


        public static void BedroomExitToDownstairs()
        {
            PathFinder pathFinder = new();
            pathFinder.SetGoalRegion(35, GameState.WHOLE_ROOM);
            // pathFinder.FindPathsFrom(roomNr: 3, 40, 163, MAXDEPTH: 8, stopPathOnSolution: true);
            pathFinder.FindPathsFrom(roomNr: 3, 18, 142, MAXDEPTH: 5, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: false);
        }


        public static void BedroomEntryToMapPickup()
        {
            PathFinder pathFinder = new();
            pathFinder.SetGoalRegion(2, GameState.WIZBEDROOM_NEAR_CLOSET);
            // pathFinder.FindPathsFrom(roomNr: 2, 88, 120, MAXDEPTH: 4, stopPathOnSolution: true);
            pathFinder.FindPathsFrom(roomNr: 2, 41, 133, MAXDEPTH: 4, stopPathOnSolution: true);
            // pathFinder.FindPathsFrom(roomNr: 2, 39, 165, MAXDEPTH: 4, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: false);
        }


        public static void UpstairsToWizBedroom()
        {
            PathFinder pathFinder = new();
            pathFinder.SetGoalRegion(2, GameState.WHOLE_ROOM);
            // 5 length solutions to (88,120)(2) and 6-length solutions to (41,133)(2)
            pathFinder.FindPathsFrom(roomNr: 3, 124, 133, MAXDEPTH: 6, stopPathOnSolution: true);
            // 6 length solutions to (88,120)(2) and (41,133)(2)
            // pathFinder.FindPathsFrom(roomNr: 3, 90, 163, MAXDEPTH: 6, stopPathOnSolution: true);
            // 5 length solution to (88,120)(2) and 6-length solutions to (41,133)(2)
            // pathFinder.FindPathsFrom(roomNr: 3, 88, 165, MAXDEPTH: 6, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: false);
        }


        public static void StartToUpstairs()
        {
            PathFinder pathFinder = new();
            pathFinder.SetGoalRegion(3, GameState.WHOLE_ROOM);
            pathFinder.FindPathsFrom(roomNr: 7, 96, 137, MAXDEPTH: 11, stopPathOnSolution: true);
            pathFinder.ShowSolutions(omitPositionsSeen: false);
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
