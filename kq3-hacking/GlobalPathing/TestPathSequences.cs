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
            // DogPercent();

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
         * W N NW SW S NE N NE N NE S NW SW W NE S NE
         *
         * this is also the fastest wiz-bedroom [15]
         * W N NW SW S NE N NE N NE S NW SW W NE
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
         * CUP SPN BWL TWR ESS MAP WND TPD BSM   68 +6
         * CUP SPN BWL TWR MAP ESS WND TPD BSM   69 +6        MAP before ESS adds 1
         * SPN BWL CUP TWR ESS MAP WND TPD BSM   69 +4
         * CUP SPN BWL ESS MAP TWR WND TPD BSM   70 +6        TWR after ESS/MAP adds 2
         *
         * TWR ESS MAP CUP SPN BWL WND TPD BSM   68 +6        TWR first is just as good as CUP first
         * TWR ESS MAP SPN BWL CUP WND TPD BSM   68 +6        order of SPN/CUP doesn't matter if going up first
         *
         * ESS MAP TWR CUP SPN BWL WND TPD BSM   70 +2        putting ESS first adds minimum of 2
         * MAP ESS TWR SPN BWL CUP WND TPD BSM   71 +0        putting MAP first adds minimum of 3
         *
         *
         * trapdoor before wand adds 2 if routing kitchen last
         * TWR ESS MAP SPN BWL CUP TPD WND BSM   70
         * trapdoor before wand adds 1 if routing kitchen firt
         * CUP SPN BWL TWR ESS MAP TPD WND BSM   69
         *
         *
         *
         *
         *
         *
         */
        public static void Enumeration1()
        {
            GlobalPathFinder pathFinder = new GlobalPathFinder();
            pathFinder.NextGoal(GlobalPathFinder.GOAL_SPOON);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_BOWL);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_CUP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_TOWER);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_ESSENCE);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_KEY_AND_MAP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_WAND);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_TRAPDOOR);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_BASEMENT);
            // pathFinder.FindPathLengths();
            // pathFinder.ShowPathLengths();
            pathFinder.ShowTraverserPaths();
        }


        // get the map and exit
        public static void DogPercent()
        {
            GlobalPathFinder pathFinder = new GlobalPathFinder();
            pathFinder.NextGoal(GlobalPathFinder.GOAL_KEY_AND_MAP);
            pathFinder.NextGoal(GlobalPathFinder.GOAL_EXIT_HOUSE);
            // pathFinder.FindPathLengths();
            // pathFinder.ShowPathLengths();
            pathFinder.ShowTraverserPaths();
        }


    }
}
