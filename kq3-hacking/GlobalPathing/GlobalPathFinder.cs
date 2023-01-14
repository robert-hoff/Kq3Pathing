using System.Diagnostics;

using kq3_hacking.RoomPathing;
using static kq3_hacking.RoomPathing.MapTraversal;
using static kq3_hacking.RoomPathing.GameState;


namespace kq3_hacking.GlobalPathing
{
    class GlobalPathFinder
    {
        List<GlobalTraverser> traversers;
        GlobalTraverser currentTraverser;

        public const int GOAL_CUP = 1;
        public const int GOAL_SPOON = 2;
        public const int GOAL_BOWL = 3;
        public const int GOAL_EXIT_KITCHEN = 4;

        public GlobalPathFinder()
        {
            traversers = new();
            currentTraverser = new GlobalTraverser(new GameState(), START_ROOM, START_POS.x, START_POS.y);
            traversers.Add(currentTraverser);
        }

        public GlobalPathFinder(int roomNr, int startX, int startY)
        {
            traversers = new();
            currentTraverser = new GlobalTraverser(new GameState(), roomNr, startX, startY);
            traversers.Add(currentTraverser);
        }

        public void NextGoal(int goal)
        {
            switch (goal)
            {
                case GOAL_CUP:
                    currentTraverser.SetGoalCup();
                    break;

                case GOAL_SPOON:
                    currentTraverser.SetGoalSpoon();
                    break;

                case GOAL_BOWL:
                    currentTraverser.SetGoalBowl();
                    break;

                case GOAL_EXIT_KITCHEN:
                    currentTraverser.SetGoalExitKitchen();
                    break;

                default:
                    throw new Exception($"unknown goal {goal}");
            }
        }

        public void FindPathLengths()
        {
            foreach (GlobalTraverser traverser in traversers)
            {
                List<Traversal> pathSequence = traverser.FindPathSequence();
                foreach (Traversal t in pathSequence)
                {
                    Debug.WriteLine($"{t}");
                }
            }
        }

        public void ShowPathLengths(int enumerationId = 0)
        {
            int totalLen = 0;

            foreach (GlobalTraverser traverser in traversers)
            {
                traverser.DeterminePathLength();
                totalLen += traverser.pathLength;
            }
            Debug.Write($"{enumerationId,3}.   {totalLen,3}   ");
            foreach (GlobalTraverser traverser in traversers)
            {
                Debug.Write($"---- {traverser.pathLength} {traverser.pathDescription}  ");
            }
            Debug.WriteLine($"");

        }
    }
}


