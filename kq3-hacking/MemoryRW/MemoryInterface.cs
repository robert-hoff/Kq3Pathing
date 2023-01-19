using System.Diagnostics;
using System.Runtime.InteropServices;

namespace kq3_hacking.MemoryRW
{
    public class MemoryInterface
    {
        private const int PROCESS_VM_OPERATION = 0x0008;
        private const int PROCESS_VM_READ = 0x0010;
        private const int PROCESS_VM_WRITE = 0x0020;

        [DllImport("kernel32.dll")]
        private static extern IntPtr OpenProcess(int dwDesiredAccess, bool bInheritHandle, int dwProcessId);

        [DllImport("kernel32.dll")]
        private static extern bool ReadProcessMemory(int hProcess, int lpBaseAddress, byte[] buffer, int size, ref int lpNumberOfBytesRead);

        [DllImport("kernel32.dll")]
        private static extern bool WriteProcessMemory(int hProcess, int lpBaseAddress, byte[] buffer, int size, out int lpNumberOfBytesWritten);


        private static Process process;
        private static IntPtr processPointer;
        private static int bytesRead = 0;
        private static int bytesWritten = 0;

        public static void Initialize(string processName)
        {
            // check if named process exists
            if (Process.GetProcessesByName(processName).Length > 0)
                process = Process.GetProcessesByName(processName)[0];
            else
            {
                Debug.WriteLine($"MemoryInterface.Initialize: Couldn't find process {processName}");
                Environment.Exit(1);
            }
            processPointer = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, false, process.Id);
            Debug.WriteLine($"Opened prcoess {processName}");
        }

        public static T ReadMemory<T>(int address) where T : struct
        {
            int ByteSize = Marshal.SizeOf(typeof(T));
            byte[] buffer = new byte[ByteSize];
            ReadProcessMemory((int) processPointer, address, buffer, buffer.Length, ref bytesRead);
            return ConvertToStructure<T>(buffer);
        }

        public static void WriteMemory<T>(object val, int address)
        {
            byte[] buffer = StructureToByteArray(val);
            WriteProcessMemory((int) processPointer, address, buffer, buffer.Length, out bytesWritten);
        }

        private static T ConvertToStructure<T>(byte[] bytes) where T : struct
        {
            var handle = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            try
            {
                return (T) Marshal.PtrToStructure(handle.AddrOfPinnedObject(), typeof(T));
            }
            finally
            {
                handle.Free();
            }
        }

        private static byte[] StructureToByteArray(object structObj)
        {
            int len = Marshal.SizeOf(structObj);
            byte[] arr = new byte[len];
            IntPtr ptr = Marshal.AllocHGlobal(len);
            Marshal.StructureToPtr(structObj, ptr, true);
            Marshal.Copy(ptr, arr, 0, len);
            Marshal.FreeHGlobal(ptr);
            return arr;
        }
    }
}

