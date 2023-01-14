using System.Diagnostics;
using static kq3_hacking.RoomPathing.MapTraversal;

namespace kq3_hacking.RoomPathing
{
    class TestMapTraversals
    {

        public static void RunTrials()
        {
            // MapTraversalShowAvailableActions();
            MapTraversals1();

        }

        public static void MapTraversalShowAvailableActions()
        {
            MapTraversal mapTraversal = new();
            ShowPathActions(mapTraversal, 2, 139, 69);
        }


        public static void MapTraversals1()
        {
            MapTraversal mapTraversal = new();
            // ShowTraversal(mapTraversal, GameState.START_POS, RoomControl.DIR_NW); // expected (82,123)(7)
            // ShowTraversal(mapTraversal, GameState.START_POS, RoomControl.DIR_E); // expected (48,138)(8)
            // ShowTraversal(mapTraversal, 8, 48, 138, RoomControl.DIR_NW); // expected (40,130)(8)
            // ShowTraversal(mapTraversal, 8, 40, 130, RoomControl.DIR_S); // expected (40,136)(8)
            // ShowTraversal(mapTraversal, 6, 62, 124, RoomControl.DIR_SE); // expected (137,154)(8)
            // ShowTraversal(mapTraversal, 8, 48, 138, RoomControl.DIR_W); // expected (77,140)(7)


            // ShowTraversal(mapTraversal, 35, 50, 99, RoomControl.DIR_N); // expected (50,96)(35)
            // ShowTraversal(mapTraversal, 35, 50, 96, RoomControl.DIR_SW); // expected (25,121)(35)
            // ShowTraversal(mapTraversal, 7, 46, 85, RoomControl.DIR_SW); // expected (24,107)(35)
            // ShowTraversal(mapTraversal, 7, 39, 101, RoomControl.DIR_SE); // expected (46,106)(35)
            // ShowTraversal(mapTraversal, 7, 40, 101, RoomControl.DIR_SE); // expected (45,106)(35)
            // ShowTraversal(mapTraversal, 35, 20, 112, RoomControl.DIR_NE); // expected (47,85)(7)
            // ShowTraversal(mapTraversal, 35, 92, 47, RoomControl.DIR_NE); // expected (124,133)(3)
            // ShowTraversal(mapTraversal, 3, 124, 133, RoomControl.DIR_SW); // expected (79,62)(35)
            // ShowTraversal(mapTraversal, 3, 124, 133, RoomControl.DIR_SE); // expected (29,163)(4)
            // ShowTraversal(mapTraversal, 4, 29, 163, RoomControl.DIR_W); // expected (90,163)(4)
            // ShowTraversal(mapTraversal, 4, 29, 163, RoomControl.DIR_NW); // expected (122,135)(4)
            // ShowTraversal(mapTraversal, 4, 13, 131, RoomControl.DIR_SW); // expected (79,62)(35)
            // ShowTraversal(mapTraversal, 4, 13, 132, RoomControl.DIR_NW); // expected (133,133)(3)
            // ShowTraversal(mapTraversal, 4, 13, 132, RoomControl.DIR_W); // expected (122,133)(3)
            // ShowTraversal(mapTraversal, 3, 18, 142, RoomControl.DIR_NE); // expected (88,120)(2)
            // ShowTraversal(mapTraversal, 2, 43, 134, RoomControl.DIR_S); //
            // ShowTraversal(mapTraversal, 3, 102, 85, RoomControl.DIR_NE); // expected (76,120)(1)
            // ShowTraversal(mapTraversal, 1, 76, 120, RoomControl.DIR_SW); // expected (102,85)(3)
            // ShowTraversal(mapTraversal, 7, 124, 135, RoomControl.DIR_SE); // expected (51,163)(8)
            // ShowTraversal(mapTraversal, 7, 124, 165, RoomControl.DIR_E); // expected (137,165)(8)

            // from the starting position to upstairs
            ShowTraversal(mapTraversal, 7, 96, 137, RoomControl.DIR_W); // expected (75,137)(7)
            ShowTraversal(mapTraversal, 7, 75, 137, RoomControl.DIR_N); // expected (75,123)(7)
            ShowTraversal(mapTraversal, 7, 75, 123, RoomControl.DIR_NW); // expected (40,88)(7)
            ShowTraversal(mapTraversal, 7, 40, 88, RoomControl.DIR_S); // expected (40,98)(7)
            ShowTraversal(mapTraversal, 7, 40, 98, RoomControl.DIR_SW); // expected (40,98)(7)




            // ShowTraversal(mapTraversal, roomNr: 35, 79, 68, RoomControl.DIR_SW); // expected (26,121)(35)


        }

        private static void ShowTraversal(MapTraversal mapTraversal, (int x, int y, int roomNr) pos, int DIR)
        {
            Traversal traversal = mapTraversal.EvaluateMapTraversal(pos.roomNr, pos.x, pos.y, DIR);
            Debug.WriteLine($"{traversal}");
        }

        private static void ShowTraversal(MapTraversal mapTraversal, int roomNr, int x, int y, int DIR)
        {
            Traversal traversal = mapTraversal.EvaluateMapTraversal(roomNr, x, y, DIR);
            Debug.WriteLine($"{traversal}");
        }

        private static void ShowPathActions(MapTraversal mapTraversal, int roomNr, int x, int y)
        {
            Stack<Traversal> traversals = mapTraversal.GetPathActions(roomNr, x, y);
            Debug.Write($"Path actions for ({x},{y})({roomNr}) ");
            foreach (var t in traversals)
            {
                Debug.Write($"{RoomControl.directionNames[t.direction],-3}");
            }
            Debug.WriteLine($"");
        }





    }
}
