using System.Diagnostics;

namespace kq3_hacking.DataFilesIO
{
    class FileOperations
    {
        public static void RunTrials()
        {
            ChangeLogicScriptFileExtensions();
        }

        private const string SCRIPT_DIR = "../../../../agi-logic-scripts-annotated";

        public static void ChangeLogicScriptFileExtensions()
        {
            foreach (var filenamepath in Directory.GetFiles(SCRIPT_DIR))
            {
                FileInfo fileInfo = new FileInfo(filenamepath);
                if (fileInfo.Extension.Equals(".lgc"))
                {
                    int logicId = int.Parse(fileInfo.Name[5..^4]);
                    string newName = $@"{fileInfo.Directory}\logic{logicId:000}.c";
                    Debug.WriteLine($"renaming {fileInfo.Name,13} to {newName}");
                    fileInfo.MoveTo(newName);
                }
            }
        }
    }
}

