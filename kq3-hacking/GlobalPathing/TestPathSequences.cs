namespace kq3_hacking.GlobalPathing
{
    class TestPathSequences
    {

        public static void RunTrials()
        {
            // PathsDetailsForCupBowlSpoon();
            PathsDetailsForCupSpoonBowl();
            // PathsDetailsForSpoonBowlCup();
            // PathsDetailsForBowlSpoonCup();
        }


        /*
         * Best path [20]
         * SE N SE NE               get cup
         * E S NW E NW W S NW N     get bowl
         * SE N                     get spoon
         * SE SW W SW NW            back to hallway
         *
         */
        public static void PathsDetailsForCupBowlSpoon()
        {
            GlobalPathFinder pathFinder = new GlobalPathFinder();
            pathFinder.NextGoal(GlobalPathFinder.GOAL_CUP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_BOWL);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_SPOON);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_EXIT_KITCHEN);
            pathFinder.FindPathLengths(); // full details
            // pathFinder.ShowPathLengths();
        }

        /*
         * Best path [18]
         * SE N SE NE               get cup
         * E S NW E NW              get spoon
         * E SW NW                  get bowl
         * E NW S W SW NW           back to hallway
         *
         */
        public static void PathsDetailsForCupSpoonBowl()
        {
            GlobalPathFinder pathFinder = new GlobalPathFinder();
            pathFinder.NextGoal(GlobalPathFinder.GOAL_CUP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_SPOON);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_BOWL);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_EXIT_KITCHEN);
            pathFinder.FindPathLengths(); // full details
            // pathFinder.ShowPathLengths();
        }


        /*
         * Best path [19]
         * E N SW N E NW          get spoon
         * E SW NW                get bowl
         * E NW S W SW NW SE NE   get cup
         * SW NW                  back to hallway
         *
         */
        public static void PathsDetailsForSpoonBowlCup()
        {
            GlobalPathFinder pathFinder = new GlobalPathFinder();
            pathFinder.NextGoal(GlobalPathFinder.GOAL_SPOON);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_BOWL);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_CUP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_EXIT_KITCHEN);
            pathFinder.FindPathLengths(); // full details
            // pathFinder.ShowPathLengths();
        }

        /*
         * Best path [19]
         * E N SW E NW NE W NE    get bowl
         * SW SE NE               get spoon
         * SE SW NW SW NW         get cup
         * W SE W                 back to hallway
         *
         */
        public static void PathsDetailsForBowlSpoonCup()
        {
            GlobalPathFinder pathFinder = new GlobalPathFinder();
            pathFinder.NextGoal(GlobalPathFinder.GOAL_BOWL);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_SPOON);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_CUP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_EXIT_KITCHEN);
            pathFinder.FindPathLengths(); // full details
            // pathFinder.ShowPathLengths();
        }

    }
}
