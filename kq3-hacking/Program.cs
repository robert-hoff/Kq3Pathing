using kq3_hacking.DataFilesIO;
using kq3_hacking.RoomPathing;

namespace kq3_hacking
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {
            // RunInterface();
            // RunFileOperations();
            Pathing();
        }


        public static void RunInterface()
        {
            ApplicationConfiguration.Initialize();
            Application.Run(new TestForm());
        }

        public static void RunFileOperations()
        {
            // FileOperations.RunTrials();
            CreateCheatEngineConfigs.RunTrials();
        }

        public static void Pathing()
        {
            PrintRoomControlData.RunTrials();
        }


    }
}



