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
            ShowTraversal(mapTraversal, 8, 48, 138, RoomControl.DIR_W); // expected (77,140)(7)


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
