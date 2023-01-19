using System.Diagnostics;
using static kq3_hacking.MemoryRW.Kq3AddressPointers;
using static kq3_hacking.MemoryRW.MemoryReadWrite;

namespace kq3_hacking.MemoryRW
{
    internal class TestMemoryOperations
    {

        public static void RunTrials()
        {
            ShowRandomSeed();
        }


        public static void ShowRandomSeed()
        {
            Kq3ReadWrite kq3RW = new Kq3ReadWrite();
            Debug.WriteLine($"{kq3RW.ReadTwoByte(RANDOM_SEED_PTR)}");
        }


        public static void ShowKq1BaseAddress()
        {
            MemoryInterface.Initialize("DOSBox");
            Int4Byte Kq1BaseAddress = MemoryInterface.ReadMemory<Int4Byte>(KQ3_BASE_POINTER);
            Debug.WriteLine($"0x{Kq1BaseAddress.int0:X}");
        }

        public static void ShowDosboxWindowTitle()
        {
            // title looks like this
            // DOSBox ECE r4319, CPU speed:    60001 cycles, Frameskip  0, Program: KQ1
            // DOSBox ECE r4319, CPU speed:        1 cycles, Frameskip  0, Program: KQ1
            Process dosboxProcess = Process.GetProcessesByName("DOSBox")[0];
            int cycles = int.Parse(dosboxProcess.MainWindowTitle.Substring(30, 8));
            Debug.WriteLine($"Full title: {dosboxProcess.MainWindowTitle}");
            Debug.WriteLine($"showing cycles {cycles}");
        }

        public static void ShowDosboxProcess()
        {
            // Process dosboxProcess = Process.GetProcessById(0x00230E20);
            Process dosboxProcess = Process.GetProcessesByName("DOSBox")[0];
            Debug.WriteLine($"{dosboxProcess}");
        }

        public static void ShowAllProcesses()
        {
            Process[] processCollection = Process.GetProcesses();
            foreach (Process p in processCollection)
            {
                Debug.WriteLine(p.ProcessName);
            }
        }
    }
}


