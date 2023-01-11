using System.Diagnostics;

namespace kq3_hacking.DataFilesIO
{
    class FileOperations
    {
        public static void RunTrials()
        {
            // ChangeLogicScriptFileExtensions();
            ChangeCgAndMsgExentions();
        }

        private const string SCRIPT_DIR = "../../../../agi-logic-scripts-annotated";
        private const string ORIGINAL_SOURCES_DIR = "../../../../agi-logic-scripts-source";

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


        public static void ChangeCgAndMsgExentions()
        {
            foreach (var filenamepath in Directory.GetFiles(ORIGINAL_SOURCES_DIR))
            {
                FileInfo fileInfo = new FileInfo(filenamepath);
                if (fileInfo.Extension.ToLower().Equals(".cg"))
                {
                    int logicId = int.Parse(fileInfo.Name[2..^3]);
                    string newName = $@"{fileInfo.Directory}\rm{logicId:000}.c";
                    Debug.WriteLine($"renaming {fileInfo.Name,13} to {newName}");
                    fileInfo.MoveTo(newName);
                }
                if (fileInfo.Extension.ToLower().Equals(".msg"))
                {
                    int logicId = int.Parse(fileInfo.Name[2..^4]);
                    string newName = $@"{fileInfo.Directory}\rm{logicId:000}-messages.c";
                    Debug.WriteLine($"renaming {fileInfo.Name,13} to {newName}");
                    fileInfo.MoveTo(newName);
                }
            }
        }



    }
}

