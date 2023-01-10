using kq3_hacking.DataFilesIO;

namespace kq3_hacking
{
    internal static class Program
    {
        [STAThread]
        static void Main()
        {
            // RunInterface();
            RunFileOperations();
        }


        public static void RunInterface()
        {
            ApplicationConfiguration.Initialize();
            Application.Run(new TestForm());
        }

        public static void RunFileOperations()
        {
            FileOperations.RunTrials();
        }




    }
}



