using System.Diagnostics;

namespace kq3_hacking.DataFilesIO
{
    class CreateCheatEngineConfigs
    {

        public static void RunTrials()
        {
            WriteVarEntries();
            WriteFlagEntries();
        }

        const string INPUT_FOLDER = "../../../../input-samples/";


        /*
         * CheatEngine vars
         * -----------------
         *
         * <CheatEntry>
         *   <ID>7</ID>
         *   <Description>"v000 - current room"</Description>
         *   <ShowAsSigned>0</ShowAsSigned>
         *   <VariableType>Byte</VariableType>
         *   <Address>Dosbox.exe + 0x1B58E20</Address>
         *   <Offsets>
         *     <Offset>0xC789</Offset>
         *   </Offsets>
         * </CheatEntry>
         *
         */
        public static void WriteVarEntries()
        {
            string inputFile = INPUT_FOLDER + "var-definitions.txt";
            const int baseConfigId = 7;
            string baseAddress = "Dosbox.exe + 0x1B58E20";
            const int VARS_BASE_OFFSET = 0xC789;

            List<string> lines = ReadDataFromFile.ReadFileAsStringList(inputFile, omitEmptyLines: true);
            foreach (var varDefinition in lines)
            {
                (int varId, string desc) var = ParseLine(varDefinition);
                int offset = VARS_BASE_OFFSET + var.varId;
                int configId = baseConfigId + var.varId;
                string varName = $"v{var.varId:000}{var.desc}";

                Debug.WriteLine($"<CheatEntry>");
                Debug.WriteLine($"  <ID>{configId}</ID>");
                Debug.WriteLine($"  <Description>{varName}</Description>");
                Debug.WriteLine($"  <ShowAsSigned>0</ShowAsSigned>");
                Debug.WriteLine($"  <VariableType>Byte</VariableType>");
                Debug.WriteLine($"  <Address>{baseAddress}</Address>");
                Debug.WriteLine($"  <Offsets>");
                Debug.WriteLine($"    <Offset>0x{offset:X}</Offset>");
                Debug.WriteLine($"  </Offsets>");
                Debug.WriteLine($"</CheatEntry>");
            }
        }

        /*
         *
         * CheatEngine flags
         * -----------------
         *
         * flag000 has offset 0xC889
         * flag000 is in bitposition 7 (bitstart) and flag007 in bitposition 0
         *
         *  <CheatEntry>
         *    <ID>295</ID>
         *    <Description>"flag090 near.mud"</Description>
         *    <VariableType>Binary</VariableType>
         *    <BitStart>5</BitStart>
         *    <BitLength>1</BitLength>
         *    <ShowAsBinary>0</ShowAsBinary>
         *    <Address>Dosbox.exe + 0x1B58E20</Address>
         *    <Offsets>
         *      <Offset>0xC894</Offset>
         *    </Offsets>
         *  </CheatEntry>
         *
         */
        public static void WriteFlagEntries()
        {
            const int FLAGS_BASE_OFFSET = 0xC889;
            const string inputFile = INPUT_FOLDER + "flag-definitions.txt";
            const int FLAGS_BASE_CONFIG = 263;
            const string BASE_ADDRESS = "Dosbox.exe + 0x1B58E20";
            // ShowFlagDefinitions(inputFile);
            WriteFlagDefinitionsAsCheatEngineConfigs(inputFile, FLAGS_BASE_CONFIG, BASE_ADDRESS, FLAGS_BASE_OFFSET);
        }

        public static void WriteFlagDefinitionsAsCheatEngineConfigs(string filenamepath,
            int baseConfigId, string baseAddress, int flagsBaseOffset)
        {
            List<string> lines = ReadDataFromFile.ReadFileAsStringList(filenamepath, omitEmptyLines: true);
            foreach (var line in lines)
            {
                (int flagId, string desc) flag = ParseLine(line);
                (int offset, int bitPos) flagAddress = FindAddress(flag.flagId, flagsBaseOffset);
                int configId = baseConfigId + flag.flagId;
                string flagName = $"f{flag.flagId:000}{flag.desc}";
                Debug.WriteLine($"<CheatEntry>");
                Debug.WriteLine($"  <ID>{configId}</ID>");
                Debug.WriteLine($"  <Description>{flagName}</Description>");
                Debug.WriteLine($"  <VariableType>Binary</VariableType>");
                Debug.WriteLine($"  <BitStart>{flagAddress.bitPos}</BitStart>");
                Debug.WriteLine($"  <BitLength>1</BitLength>");
                Debug.WriteLine($"  <ShowAsBinary>0</ShowAsBinary>");
                Debug.WriteLine($"  <Address>{baseAddress}</Address>");
                Debug.WriteLine($"  <Offsets>");
                Debug.WriteLine($"    <Offset>0x{flagAddress.offset:X}</Offset>");
                Debug.WriteLine($"  </Offsets>");
                Debug.WriteLine($"</CheatEntry>");
            }
        }

        // -- entries of the form
        // ParseAndShowLine("0");
        // ParseAndShowLine("56");
        // ParseAndShowLine("near.mud    90");
        public static void ShowFlagDefinitions(string filenamepath)
        {
            const int FLAGS_BASE_OFFSET = 0xC889;
            List<string> lines = ReadDataFromFile.ReadFileAsStringList(filenamepath, omitEmptyLines: true);
            foreach (var line in lines)
            {
                ParseAndShowLine(line, FLAGS_BASE_OFFSET);
            }
        }

        public static void  ParseAndShowLine(string flagDefinition, int flagsBaseOffset)
        {
            (int flagId, string desc) flag = ParseLine(flagDefinition);
            (int offset, int bitPos) flagAddress = FindAddress(flag.flagId, flagsBaseOffset);

            string flagName = $"flag{flag.flagId:000}{flag.desc}";
            Debug.WriteLine($"{flagName,-30} offset=0x{flagAddress.offset:X} bitPos={flagAddress.bitPos}");
        }

        public static (int, string) ParseLine(string line)
        {
            string[] tokens = line.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            if (tokens.Length == 1)
            {
                int flagId = int.Parse(tokens[0]);
                return (flagId, "");
            }
            if (tokens.Length == 2)
            {
                int flagId = int.Parse(tokens[1]);
                return (flagId, $" - {tokens[0]}");
            }
            throw new Exception($"Wrong format for flag definition line={line}");
        }


        public static (int, int) FindAddress(int flagId, int baseOffset)
        {
            int bitPos = 7 - flagId % 8;
            int offset = baseOffset + flagId / 8;
            return (offset, bitPos);
        }
    }
}

