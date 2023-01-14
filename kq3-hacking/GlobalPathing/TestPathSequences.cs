namespace kq3_hacking.GlobalPathing
{
    class TestPathSequences
    {

        public static void RunTrials()
        {
            // PathsDetailsForCupBowlSpoon();
            // PathsDetailsForCupSpoonBowl();
            // PathsDetailsForSpoonBowlCup();
            // PathsDetailsForBowlSpoonCup();
            // PathsEssencePickup();
            Enumeration1();

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

        /*
         * fastest essence [17]
         * this is also the fastest wiz-bedroom [15]
         *  W N NW SW S NE N NE N NE S NW SW W NE S NE
         *
         *
         */
        public static void PathsEssencePickup()
        {
            GlobalPathFinder pathFinder = new GlobalPathFinder();
            pathFinder.NextGoal(GlobalPathFinder.GOAL_WIZ_BEDROOM);
            // pathFinder.NextGoal(GlobalPathFinder.GOAL_ESSENCE);
            pathFinder.FindPathLengths();
        }


        /*
         *
         * CUP SPN BWL TWR ESS MAP WND TPD   67 +6
         * CUP SPN BWL TWR MAP ESS WND TPD   68 +6        MAP before ESS adds 1
         * SPN BWL CUP TWR ESS MAP WND TPD   68 +4
         * CUP SPN BWL ESS MAP TWR WND TPD   69 +6        TWR after ESS/MAP adds 2
         *
         * TWR ESS MAP CUP SPN BWL WND TPD   67 +6        TWR first is just as good as CUP first
         * ESS MAP TWR CUP SPN BWL WND TPD   69 +2
         * TWR ESS MAP SPN BWL CUP WND TPD   67 +6        order of SPN/CUP doesn't matter if going up first
         *
         * MAP ESS TWR SPN BWL CUP WND TPD   70 +0        leading with map is 3 longer but saves several keys
         *
         *
         *
         */
        public static void Enumeration1()
        {
            GlobalPathFinder pathFinder = new GlobalPathFinder();
            pathFinder.NextGoal(GlobalPathFinder.GOAL_CUP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_SPOON);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_BOWL);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_TOWER);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_ESSENCE);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_KEY_AND_MAP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_WAND);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_TRAPDOOR);
            // pathFinder.FindPathLengths(); // full details
            pathFinder.ShowPathLengths();
        }


    }
}
