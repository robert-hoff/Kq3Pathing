using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using kq3_hacking.DataFilesIO;

namespace kq3_hacking.RoomPathing
{
    class PrintRoomControlData
    {

        public static void RunTrials()
        {
            // ShowRoomControlData(3);
            ShowRoomAreaTriggers(10);
            // SaveRoomControlData(1, "testfile.txt");
            // SaveAllControlData();

        }


        public static void ShowRoomControlData(int roomNr)
        {
            RoomControl roomControl = new(roomNr);
            roomControl.ShowControlData();
        }


        static string OUTPUT_FOLDER = "../../../../output/";

        public static void ShowRoomAreaTriggers(int roomNr)
        {
            RoomControl roomControl = new(roomNr);
            roomControl.ShowWaterAreaTriggers();
        }


        public static void SaveRoomControlData(int roomNr, string filename)
        {
            FileWriter sw = new(OUTPUT_FOLDER + filename);
            RoomControl roomControl = new(roomNr);
            roomControl.ShowControlData(sw.Write);
            sw.CloseStreamWriter();
        }

        public static void SaveAllControlData()
        {
            for (int i = 1; i < 200; i++)
            {
                RoomDefinition roomDef = RoomDefinition.GetRoomDefinition(i);
                if (roomDef != null)
                {
                    SaveRoomControlData(i, $"room{i:000}.txt");
                }
            }
        }


    }
}
