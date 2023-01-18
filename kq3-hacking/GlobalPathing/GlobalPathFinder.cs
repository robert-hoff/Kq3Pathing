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
        public const int GOAL_KEY_AND_MAP = 5;
        public const int GOAL_ESSENCE = 6;
        public const int GOAL_FLY = 7;
        public const int GOAL_WIZ_BEDROOM= 8;
        public const int GOAL_TOWER = 9;
        public const int GOAL_WAND = 10;
        public const int GOAL_TRAPDOOR = 11;
        public const int GOAL_BASEMENT = 12;
        public const int GOAL_EXIT_HOUSE = 13;

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

                case GOAL_ESSENCE:
                    currentTraverser.SetGoalEssence();
                    break;

                case GOAL_KEY_AND_MAP:
                    currentTraverser.SetGoalMapKey();
                    break;

                case GOAL_WIZ_BEDROOM:
                    currentTraverser.SetGoalWizBedroom();
                    break;

                case GOAL_TOWER:
                    currentTraverser.SetGoalTower();
                    break;

                case GOAL_WAND:
                    currentTraverser.SetGoalWand();
                    break;

                case GOAL_TRAPDOOR:
                    currentTraverser.SetGoalTrapdoor();
                    break;

                case GOAL_BASEMENT:
                    currentTraverser.SetGoalBasement();
                    break;

                case GOAL_EXIT_HOUSE:
                    currentTraverser.SetGoalExitHouse();
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

        public void ShowTraverserPaths()
        {
            for (int i = 0; i < traversers.Count; i++)
            {
                GlobalTraverser traverser = traversers[i];

                List<Traversal> pathSequence = traverser.FindPathSequence();
                string enumTitle = $"{traverser.pathDescription} [{pathSequence.Count-1}]";
                Debug.WriteLine($"{enumTitle}");
                Debug.WriteLine($"{new string('-', enumTitle.Length)}");

                int lastMapId = 0;
                int stepCount = 0;
                Traversal t0 = pathSequence[0];
                Debug.WriteLine($"start ({t0.X()},{t0.Y()})({t0.RNr()})");

                for (int j = 1; j < pathSequence.Count; j++)
                {
                    Traversal t = pathSequence[j];
                    Debug.Write($"{MapTraversal.actionNames[t.action]} ");
                    stepCount++;
                    if (t.mapStateId != lastMapId)
                    {
                        string goalDesc = traverser.pathDescriptions[lastMapId].ToLower();
                        Debug.WriteLine($"[{stepCount}] {goalDesc} ({t.X()},{t.Y()})({t.RNr()})");
                        stepCount = 0;
                        lastMapId = t.mapStateId;
                    }
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


