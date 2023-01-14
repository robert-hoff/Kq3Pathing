
using kq3_hacking.RoomPathing;
using static kq3_hacking.RoomPathing.GameState;
using static kq3_hacking.RoomPathing.MapTraversal;


namespace kq3_hacking.GlobalPathing
{
    class GlobalTraverser
    {
        private GameState currentGameState = null;
        private GameState nextGameState;
        private StateTraversal traverser;
        private int startRoomNr;
        private int startX;
        private int startY;
        public int pathLength = 0;
        public string pathDescription = "";

        public GlobalTraverser(GameState gameState, int startRoomNr, int startX, int startY)
        {
            nextGameState = gameState;
            traverser = new();
            this.startRoomNr = startRoomNr;
            this.startX = startX;
            this.startY = startY;
        }

        public GameState GetNextGameState()
        {
            return nextGameState;
        }

        public void SetGoalCup()
        {
            pathDescription += "CUP ";
            currentGameState = nextGameState;
            nextGameState = currentGameState.CloneState();
            GoalState goalState = new();
            goalState.SetGoalRegion(goalRoomNr: 8, CUP_PICKUP_AREA);
            traverser.RegisterPathingComponents(currentGameState, goalState);
        }

        public void SetGoalBowl()
        {
            pathDescription += "BWL ";
            currentGameState = nextGameState;
            nextGameState = currentGameState.CloneState();
            GoalState goalState = new();
            goalState.SetGoalRegion(goalRoomNr: 6, BOWL_PICKUP_AREA);
            traverser.RegisterPathingComponents(currentGameState, goalState);
        }

        public void SetGoalSpoon()
        {
            pathDescription += "SPN ";
            currentGameState = nextGameState;
            nextGameState = currentGameState.CloneState();
            GoalState goalState = new();
            goalState.SetGoalRegion(goalRoomNr: 6, KNIFE_SPOON_PICKUP_AREA);
            traverser.RegisterPathingComponents(currentGameState, goalState);
        }

        public void SetGoalExitKitchen()
        {
            pathDescription += "EXT ";
            currentGameState = nextGameState;
            nextGameState = currentGameState.CloneState();
            GoalState goalState = new GoalState();
            goalState.SetGoalRegion(goalRoomNr: 7, WHOLE_ROOM);
            traverser.RegisterPathingComponents(currentGameState, goalState);
        }

        public void DeterminePathLength()
        {
            pathDescription = pathDescription.Trim();
            pathLength = traverser.FindPaths(startRoomNr, startX, startY).Last().pathLength;
        }


        public List<Traversal> FindPathSequence()
        {
            return traverser.FindPaths(startRoomNr, startX, startY);
        }



    }
}
