using System.Diagnostics;
using kq3_hacking.DataFilesIO;
using kq3_hacking.GlobalPathing;
using kq3_hacking.MemoryRW;
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
            // Pathing();
            MemoryRW();
        }


        public static void RunInterface()
        {
            ApplicationConfiguration.Initialize();
            Application.Run(new TestForm());
        }

        public static void RunFileOperations()
        {
            // CreateCheatEngineConfigs.RunTrials();
            // FileOperations.RunTrials();
            // FileFormatting.RunTrials();
            FileFormattingWriteInMessages.Go();
        }

        public static void Pathing()
        {
            // PrintRoomControlData.RunTrials();
            // TestMapTraversals.RunTrials();
           TestPathFinder.RunTrials();
            // TestPathSequences.RunTrials();
        }

        public static void MemoryRW()
        {
            // TestMemoryOperations.RunTrials();
            RunMonitorVariable();
        }

        public static void RunMonitorVariable()
        {
            ApplicationConfiguration.Initialize();
            Application.Run(new MonitorVariable());
        }



    }
}



