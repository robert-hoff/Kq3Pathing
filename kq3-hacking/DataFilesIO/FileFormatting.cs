using System.Diagnostics;

namespace kq3_hacking.DataFilesIO
{
    class FileFormatting
    {

        const string SOURCE_DIR = "../../../../agi-logic-scripts-source/";

        public static void RunTrials()
        {
            // FormatAllFiles(SOURCE_DIR);
            // AutoformatFile($"{SOURCE_DIR}rm002.c", "mod");
        }

        public static void FormatAllFiles(string dir)
        {
            foreach (FileInfo file in new DirectoryInfo(dir).GetFiles())
            {
                Debug.WriteLine($"formatting {file}");
                AutoformatFile(file.FullName);
            }
        }


        private const int TRAIL_COMMENTS_ALIGN_INDEX = 60;

        public static void AutoformatFile(string filenamepath, string useSuffix = "")
        {
            List<string> lines = ReadDataFromFile.ReadFileAsStringList(filenamepath);
            lines = TokenReplacement(lines, "[", "// [");
            lines = TokenReplacement(lines, "// // [", "// [");
            lines = TokenReplacement(lines, "\t", "  ");
            lines = TokenReplacement(lines, "% include", "#include");
            lines = TokenReplacement(lines, "% view", "#view");
            lines = TokenReplacement(lines, "% define", "#define");
            lines = TokenReplacement(lines, "%message", "#message");
            lines = StringLeadsReplacement(lines, ":", "// :");
            lines = RemoveDoubleBlankLines(lines);
            lines = RemoveLeadingSpacesOnComments(lines);
            lines = AlignTrailingComments(lines, TRAIL_COMMENTS_ALIGN_INDEX);

            string newName = GetNewName(filenamepath, useSuffix);
            FileWriter.SaveStringsToFile(lines, newName);
        }

        public static List<string> TokenReplacement(List<string> lines, string stringTarget, string stringReplacement)
        {
            List<string> modifiedLines = new();
            foreach (string line in lines)
            {
                string modifiedLine = line;
                if (line.IndexOf(stringTarget) >= 0)
                {
                    modifiedLine = line.Replace(stringTarget, stringReplacement);
                }
                modifiedLines.Add(modifiedLine);
            }
            return modifiedLines;
        }

        public static List<string> StringLeadsReplacement(List<string> lines, string stringTarget, string stringReplacement)
        {
            List<string> modifiedLines = new();
            foreach (string line in lines)
            {
                string modifiedLine = line;
                if (line.IndexOf(stringTarget) == 0)
                {
                    modifiedLine = $"{stringReplacement}{line[stringTarget.Length]}";
                }
                modifiedLines.Add(modifiedLine);
            }
            return modifiedLines;
        }



        public static List<string> AlignTrailingComments(List<string> lines, int alignIndex)
        {
            List<string> modifiedLines = new();
            foreach (string line in lines)
            {
                modifiedLines.Add(AlignTrailingCommentsSingleLine(line, alignIndex));
            }
            return modifiedLines;
        }

        public static string AlignTrailingCommentsSingleLine(string line, int alignIndex)
        {
            int commentPos = line.IndexOf("//");
            if (commentPos > 0 && commentPos < alignIndex)
            {
                string str1 = line.Substring(0, commentPos);
                string str2 = line.Substring(commentPos);
                string strSpacing = new string(' ', alignIndex - commentPos);
                return $"{str1}{strSpacing}{str2}";
            }
            else
            {
                return line;
            }
        }


        public static List<string> RemoveLeadingSpacesOnComments(List<string> lines)
        {
            List<string> modifiedLines = new();
            foreach (string line in lines)
            {
                string modifiedLine = line;
                if (line.Trim().Length >= 2 && line.Trim().Substring(0, 2).Equals("//"))
                {
                    modifiedLine = line.Trim();
                }
                modifiedLines.Add(modifiedLine);
            }
            return modifiedLines;
        }

        /*
         * removes double blanks and leading blank lines
         *
         */
        public static List<string> RemoveDoubleBlankLines(List<string> lines)
        {
            bool[] removeLines = new bool[lines.Count];
            int prevBlank = -1;
            for (int i = 0; i < lines.Count; i++)
            {
                if (lines[i].Trim().Equals(""))
                {
                    if (i - 1 == prevBlank)
                    {
                        removeLines[i] = true;
                    }
                    prevBlank = i;
                }
            }
            List<string> modifiedLines = new();
            for (int i = 0; i < removeLines.Length; i++)
            {
                if (!removeLines[i])
                {
                    modifiedLines.Add(lines[i]);
                }
            }
            return modifiedLines;
        }


        public static string GetNewName(string filenamepath, string suffix = "")
        {
            string filenameNew = Path.GetFileName(filenamepath);
            string dir = Path.GetDirectoryName(filenamepath);
            if (suffix.Length > 0)
            {
                int extIndex = filenameNew.LastIndexOf('.');
                filenameNew = $"{filenameNew[..extIndex]}-{suffix}{filenameNew[extIndex..]}";

            }
            return $"{dir}/{filenameNew}";
        }




    }
}



