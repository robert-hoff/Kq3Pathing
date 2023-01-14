using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kq3_hacking.RoomPathing
{
    class RoomDefinition
    {
        static public bool reportEdgeGlitches = true;
        static Dictionary<(int, int, int, int), int> knownEdgeGlitches = new();
        public const int GLITCH_PERMITTED = 0;
        public const int GLITCH_NOT_PERMITTED = 1;

        // returns true if permitted
        public static bool checkEdgeGlitch(int roomNr, int x, int y, int DIR, int eval)
        {
            if (knownEdgeGlitches.Count == 0)
            {
            }

            if (knownEdgeGlitches.ContainsKey((roomNr, x, y, DIR)))
            {
                return knownEdgeGlitches[(roomNr, x, y, DIR)] == GLITCH_PERMITTED;
            }
            Debug.WriteLine($"unknown edge glitch room{roomNr}" +
                $"{RoomControl.directionNames[DIR]}({x},{y}) eval = {eval}");

            return false;
        }



        public int roomNr;

        public const int DEFAULT_FOOTPRINT = 6;
        private const int DEFAULT_LOWER_LIMIT = 36;
        public const int ROOM_WIDTH = 160;
        public const int ROOM_HEIGHT = 168;

        // if dark-green pixels are found and behaviour is undefined, throw an exception
        public const int ACTION_TILE_UNDEFINED = 1;
        public const int ACTION_TILE_IGNORED = 2;
        public const int ACTION_TILE_DEATH_TRIGGER = 3;
        public const int ACTION_TILE_WATER_TRIGGER = 4;
        public const int ACTION_TILE_ROOM_TRIGGER = 5;
        public const int ACTION_TILE_SPECIAL = 6;

        public const int BLOCKS_UNDEFINED = 1;
        public const int BLOCKS_IGNORED = 2;
        public const int BLOCKS_OBSERVED = 3;

        public const int WATER_TILES_IGNORED = 1;
        public const int WATER_TILES_OBSERVED = 2;
        public const int WATER_TILES_ROOM_TRIGGER = 3;

        public int useActionControl = ACTION_TILE_UNDEFINED;
        public int useBlockControl = BLOCKS_UNDEFINED;
        public int useWaterControl = WATER_TILES_OBSERVED;

        public int roomNorth;
        public int roomEast;
        public int roomSouth;
        public int roomWest;
        public int edgeNorth = int.MinValue;
        public int edgeEast = int.MaxValue;
        public int edgeSouth = int.MaxValue;
        public int edgeWest = int.MinValue;

        public List<int[]> specialBarriers = new();

        // the only time we want variable barriers is for objects
        public int[] objectFootprint = new int[4];

        // if true observe object footprint as a barrier and observe edge rewriting
        // hasObject will be used as the default reference for observing the footprint as
        // a barrier, this can be overriden by the MapTraversal to enable modelling of the key
        public bool hasObject = false;
        public int[] objectPickupArea = new int[4]; // ONLY used for AQ/DIR-AQ actions

        // Definte *additional* objects for the object rewriting
        // write the strips as rectangles, e.g. the castle door
        public List<int[]> objectsEdgeRewriting = new();
        // where true objects are written in as UNCONDITIONAL barriers,
        // otherwise objects are only used for rewriting
        public List<bool> observeObjectBarrier = new();

        // actionTriggerRoom is the room number where the action tiles are used for room change
        public int actionTriggerRoom;

        // rectangular action areas that trigger a room change
        public List<int> actionAreasRoomNumbers = new();
        public List<int[]> actionAreasRoomChange = new();

        // rectangular action areas that sends Graham into the water
        public List<int[]> actionAreasWater = new();




        private RoomDefinition(int roomNr)
        {
            this.roomNr = roomNr;
        }

        public delegate (int, int) RewriteRule(int previousRoom, int x, int y, int footprintWidth);
        public RewriteRule rewriteRule = (int previousRoom, int x, int y, int footprintWidth) =>
        {
            return (x, y);
        };

        public Dictionary<(int, int), bool> stopPoints = new();

        private int NorthBoundary = DEFAULT_LOWER_LIMIT;
        // the edge is not considered a boundary (should really fix these names though
        // they are confusing as hell)
        public int GetNorthBoundary()
        {
            return edgeNorth >= NorthBoundary ? int.MinValue : NorthBoundary;
        }
        public int GetWestBoundary()
        {
            return edgeWest >= 0 ? int.MinValue : 0;
        }
        public int GetEastBoundary()
        {
            return edgeEast <= ROOM_WIDTH ? int.MaxValue : ROOM_WIDTH;
        }
        public int GetSouthBoundary()
        {
            return edgeSouth <= ROOM_HEIGHT ? int.MaxValue : ROOM_HEIGHT;
        }

        public int MinTraversableY()
        {
            return Math.Max(edgeNorth, NorthBoundary);
        }

        // horizon must be supplied for the north edge
        public void SetNorthRoom(int roomNorth, int horizon)
        {
            this.roomNorth = roomNorth;
            this.edgeNorth = horizon;
        }

        public void SetEastRoom(int roomEast, int edgeEast = ROOM_WIDTH)
        {
            this.roomEast = roomEast;
            this.edgeEast = edgeEast;
        }
        public void SetSouthRoom(int roomSouth, int edgeSouth = ROOM_HEIGHT)
        {
            this.roomSouth = roomSouth;
            this.edgeSouth = edgeSouth;
        }
        public void SetWestRoom(int roomWest, int edgeWest = -1)
        {
            this.roomWest = roomWest;
            this.edgeWest = edgeWest;
        }

        public void AddSpecialBarrier(int x0, int y0, int x1, int y1)
        {
            CheckRectangleBounds(x0, y0, x1, y1);
            int[] rect = { x0, y0, x1, y1 };
            specialBarriers.Add(rect);
        }

        /*
         * Having more than one room trigger is rare, the only known instances are rooms 54 and 69
         */
        public void AddRoomTrigger(int roomNr, int x0, int y0, int x1, int y1)
        {
            CheckRectangleBounds(x0, y0, x1, y1);
            int[] rect = { x0, y0, x1, y1 };
            CheckActionAreaOverlaps(rect);
            actionAreasRoomNumbers.Add(roomNr);
            actionAreasRoomChange.Add(rect);
        }

        public void SetWaterControlAsRoomTrigger(int roomNr)
        {
            if (actionTriggerRoom > 0)
            {
                throw new Exception("cannot have both water and action tiles as room trigger");
            }
            actionTriggerRoom = roomNr;
            useWaterControl = WATER_TILES_ROOM_TRIGGER;
        }

        public void AddWaterTrigger(int x0, int y0, int x1, int y1)
        {
            CheckRectangleBounds(x0, y0, x1, y1);
            int[] rect = { x0, y0, x1, y1 };
            actionAreasWater.Add(rect);
        }

        public void IgnoreWaterTiles()
        {
            useWaterControl = WATER_TILES_IGNORED;
        }

        public void AddObjectEdgeRewrite(int x0, int y0, int x1, int y1, bool observeBarrier)
        {
            int[] rect = { x0, y0, x1, y1 };
            objectsEdgeRewriting.Add(rect);
            observeObjectBarrier.Add(observeBarrier);
        }

        public static void CheckRectangleBounds(int x0, int y0, int x1, int y1)
        {
            if (x0 > x1)
            {
                throw new Exception($"error - x0({x0}) is greater than x1({x1}), (x0,y0) should be the top-left edge");
            }
            if (y0 > y1)
            {
                throw new Exception($"error - y0({y0}) is greater than y1({y1}), (x0,y0) should be the top-left edge");
            }
            if (x0 < 0 || x0 >= ROOM_WIDTH || x1 < 0 || x1 >= ROOM_WIDTH)
            {
                throw new Exception($"rectangle bounds exceeds room dimensions ({x0},{y0})-({x1},{y1})");
            }
            if (y0 < 0 || y0 >= ROOM_HEIGHT || y1 < 0 || y1 >= ROOM_HEIGHT)
            {
                throw new Exception($"rectangle bounds exceeds room dimensions ({x0},{y0})-({x1},{y1})");
            }
        }

        private void CheckActionAreaOverlaps(int[] rect)
        {
            foreach (var actionArea in actionAreasRoomChange)
            {
                // Debug.WriteLine($"({actionArea[0]},{actionArea[1]})-({actionArea[2]},{actionArea[3]})");
                if (RoomControl.CheckPixelContained(rect[0], rect[1], actionArea) ||
                    RoomControl.CheckPixelContained(rect[2], rect[3], actionArea))
                {
                    throw new Exception($"A supplied action area overlaps with an existing one");
                }
            }
            foreach (var actionArea in actionAreasWater)
            {
                if (RoomControl.CheckPixelContained(rect[0], rect[1], actionArea) ||
                    RoomControl.CheckPixelContained(rect[2], rect[3], actionArea))
                {
                    throw new Exception($"A supplied action area overlaps with an existing one");
                }
            }
        }

        public static RoomDefinition GetRoomDefinition(int roomNr)
        {
            return GetRoomDefinition(roomNr, new GameState());
        }

        public static RoomDefinition GetRoomDefinition(int roomNr, GameState gameState)
        {
            RoomDefinition roomDefinition = new(roomNr);
            switch (roomNr)
            {
                default:
                    //throw new Exception($"room {roomNr} not implemented!");
                    return null;

                case 1:
                    roomDefinition.useBlockControl = BLOCKS_IGNORED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 2:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;

                    // near closet
                    roomDefinition.AddWaterTrigger(95, 127, 112, 131);

                    // near dresser
                    roomDefinition.AddWaterTrigger(102, 134, 117, 153);
                    // in way of drawer
                    roomDefinition.AddWaterTrigger(108, 144, 112, 146);

                    // near mirror
                    roomDefinition.AddWaterTrigger(58, 132, 70, 142);


                    break;

                case 3:
                    roomDefinition.useActionControl = ACTION_TILE_IGNORED;

                    // bedroom
                    roomDefinition.AddWaterTrigger(38, 90, 53, 118);
                    // tower
                    roomDefinition.AddWaterTrigger(120, 50, 139, 52);
                    // bedroom
                    roomDefinition.AddWaterTrigger(139, 133, 159, 166);

                    break;

                case 4:
                    roomDefinition.useBlockControl = BLOCKS_IGNORED;
                    roomDefinition.useActionControl = ACTION_TILE_IGNORED;
                    roomDefinition.actionTriggerRoom = 3;
                    // to hallway
                    roomDefinition.AddWaterTrigger(11, 131, 12, 165);
                    // to tower
                    roomDefinition.AddWaterTrigger(47, 0, 69, 43);
                    break;

                case 5:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useWaterControl = WATER_TILES_IGNORED;
                    // wand pickup
                    roomDefinition.AddWaterTrigger(23, 155, 32, 166);

                    // trapdoor lever
                    roomDefinition.AddWaterTrigger(113, 125, 121, 140);
                    break;

                case 6:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useWaterControl = WATER_TILES_IGNORED;
                    roomDefinition.rewriteRule = (int previousRoom, int x, int y, int footprintWidth) =>
                    {
                        if (previousRoom == 8)
                        {
                            return (104, 166);
                        }
                        throw new Exception($"unknown room {previousRoom}");
                    };
                    break;

                case 7:
                    roomDefinition.SetSouthRoom(34);
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_IGNORED;
                    roomDefinition.AddRoomTrigger(5, 93, 116, 110, 118); // office
                    roomDefinition.AddRoomTrigger(8, 131, 134, 140, 144); // dining room
                    roomDefinition.AddRoomTrigger(3, 93, 42, 109, 44); // upstairs hallway
                    break;

                case 8:
                    roomDefinition.useActionControl = ACTION_TILE_IGNORED;
                    roomDefinition.AddRoomTrigger(7, 21, 132, 25, 144); // hallway
                    roomDefinition.AddRoomTrigger(6, 101, 110, 115, 120); // kitchen
                    roomDefinition.rewriteRule = (int previousRoom, int x, int y, int footprintWidth) =>
                    {
                        if (previousRoom == 7)
                        {
                            return (26, 138);
                        }
                        if (previousRoom == 6)
                        {
                            return (104, 121);
                        }
                        throw new Exception($"unknown room {previousRoom}");
                    };
                    break;

                case 9:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    roomDefinition.useWaterControl = WATER_TILES_IGNORED;
                    break;

                case 10:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    // shelves
                    roomDefinition.AddWaterTrigger(58, 90, 96, 109);
                    // spell book
                    roomDefinition.AddWaterTrigger(92, 139, 119, 139);
                    break;

                case 11:
                    break;

                case 12:
                    break;

                case 13:
                    break;

                case 14:
                    roomDefinition.useActionControl = ACTION_TILE_ROOM_TRIGGER;
                    break;

                case 15:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 16:
                    break;

                case 17:
                    break;

                case 18:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 19:
                    break;

                case 20:
                    roomDefinition.useBlockControl = BLOCKS_IGNORED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 21:
                    break;

                case 22:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    break;

                case 23:
                    break;

                case 24:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 25:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 26:
                    break;

                case 27:
                    break;

                case 28:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 29:
                    roomDefinition.useBlockControl = BLOCKS_IGNORED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 30:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    break;

                case 33:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    roomDefinition.AddWaterTrigger(9, 60, 18, 78);
                    roomDefinition.AddWaterTrigger(0, 0, 21, 59);
                    roomDefinition.AddWaterTrigger(0, 60, 8, 68 );
                    roomDefinition.AddWaterTrigger(7, 79, 31, 87);
                    roomDefinition.AddWaterTrigger(0, 89, 53, 100);
                    roomDefinition.AddWaterTrigger(47, 75, 72, 80);
                    roomDefinition.AddWaterTrigger(46, 81, 56, 88);
                    roomDefinition.AddWaterTrigger(54, 65, 59, 74);
                    roomDefinition.AddWaterTrigger(140, 64, 154, 71);
                    roomDefinition.AddWaterTrigger(62, 84, 115, 89);
                    roomDefinition.AddWaterTrigger(54, 87, 62, 130);
                    roomDefinition.AddWaterTrigger(77, 95, 132, 131);
                    roomDefinition.AddWaterTrigger(65, 132, 123, 157);
                    roomDefinition.AddWaterTrigger(29, 153, 65, 167);
                    roomDefinition.AddWaterTrigger(12, 145, 29, 167);
                    roomDefinition.AddWaterTrigger(29, 141, 49, 147);
                    roomDefinition.AddWaterTrigger(49, 130, 63, 146);
                    roomDefinition.AddWaterTrigger(32, 65, 120, 74);
                    break;

                case 34:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 36:
                    break;

                case 37:
                    roomDefinition.useBlockControl = BLOCKS_IGNORED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 38:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    break;

                case 39:
                    roomDefinition.useActionControl = ACTION_TILE_ROOM_TRIGGER;
                    roomDefinition.actionTriggerRoom = 24;
                    break;

                case 40:
                    roomDefinition.useBlockControl = BLOCKS_IGNORED;
                    break;

                case 41:
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 42:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 48:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 49:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 50:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 51:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 52:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 53:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 54:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    break;

                case 55:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    break;

                case 56:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 57:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 58:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 59:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 60:
                    roomDefinition.useBlockControl = BLOCKS_IGNORED;
                    break;

                case 61:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 62:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 63:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 64:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 65:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 66:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 67:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 68:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 69:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 71:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 72:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 73:
                    break;

                case 74:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    break;

                case 75:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 76:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 78:
                    roomDefinition.useActionControl = ACTION_TILE_DEATH_TRIGGER;
                    break;

                case 79:
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 80:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 81:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 82:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 83:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 84:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 85:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 86:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 88:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 125:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 148:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 166:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 175:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

                case 176:
                    roomDefinition.useBlockControl = BLOCKS_OBSERVED;
                    roomDefinition.useActionControl = ACTION_TILE_SPECIAL;
                    break;

            }
            return roomDefinition;
        }


    }
}

