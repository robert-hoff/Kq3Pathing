using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace kq3_hacking.DataFilesIO
{
    class FileFormattingWriteInMessages
    {
        const string SOURCE_DIR = "../../../../agi-logic-scripts-source/";

        public static void Go()
        {
            // string filenamepath = $"{SOURCE_DIR}/rm000.c";
            // WriteInMessagesForSource(filenamepath);

            WriteInMessagesAllFiles();
        }

        public static void WriteInMessagesAllFiles()
        {
            foreach (FileInfo file in new DirectoryInfo(SOURCE_DIR).GetFiles())
            {
                WriteInMessagesForSource(file.FullName);
            }
        }

        public static void WriteInMessagesForSource(string filenamepath)
        {
            WriteMessagesToLogicSource logicMessages = new WriteMessagesToLogicSource(filenamepath);
            logicMessages.SaveCombinedSource("rewrite");
        }

        class WriteMessagesToLogicSource
        {
            string logicFilenamepath;
            string logicFilename;
            string logicDir;
            string logicSource;
            string msgFilenamepath;
            string msgSource;
            // messages won't exceed 200
            string[] messages = new string[200];
            string combinedSource;

            public WriteMessagesToLogicSource(string srcFilenamepath)
            {
                logicFilenamepath = srcFilenamepath;
                logicSource = File.ReadAllText(logicFilenamepath);

                logicFilename = Path.GetFileName(srcFilenamepath);
                logicDir = $"{Path.GetDirectoryName(logicFilenamepath)}/";
                string messagesDir = $"{logicDir}/messages/";
                string messagesFilename = $"{logicFilename[..^2]}-messages.c";

                msgFilenamepath = $"{messagesDir}{messagesFilename}";

                if (File.Exists(msgFilenamepath))
                {
                    msgSource = File.ReadAllText(msgFilenamepath);
                } else
                {
                    msgSource = "";
                }
                ExtractMessages(msgSource);
                WriteInMessages(logicSource);
            }

            public void WriteInMessages(string logicSource)
            {
                Regex rx = new Regex(@"print\((\d+)\)", RegexOptions.Compiled | RegexOptions.IgnoreCase);
                MatchEvaluator myEvaluator = new(MessageLookup);
                combinedSource = rx.Replace(logicSource, myEvaluator);
            }

            private string MessageLookup(Match m)
            {
                GroupCollection groups = m.Groups;
                string msgStatement = groups[0].ToString();

                int messageId = int.Parse(groups[1].ToString());
                if (messages[messageId] == null)
                {
                    Debug.WriteLine($"WARN - message not defined {messageId}");
                    return $"#message {messageId} \"NOT FOUND or parser error\"";
                }

                return $"#message {messageId}  \"{messages[messageId]}\"";
            }

            public void ExtractMessages(string messagesSrc)
            {
                Regex rx = new("#message\\s+(\\d+)\\s+\\\"([ a-z0-9,;<>\\-\\.\\:\\`\\(\\)\\?\\!\\&\\n\\%\\'\\/\\\\|\\\\\\\"]*)\\\"",
                    RegexOptions.Compiled | RegexOptions.IgnoreCase);
                MatchCollection matches = rx.Matches(messagesSrc);
                foreach (Match m in matches)
                {
                    GroupCollection groups = m.Groups;
                    int messageId = int.Parse(groups[1].ToString());
                    this.messages[messageId] = groups[2].ToString();
                }
            }

            public void ShowParsedResult()
            {
                Debug.WriteLine($"{combinedSource}");
            }

            public void SaveCombinedSource(string subdir = "")
            {
                if (subdir.Length > 0)
                {
                    string filenamepath = $"{logicDir}/{subdir}/{logicFilename}";
                    FileWriter.SaveStringToFile(combinedSource, filenamepath);
                } else
                {
                    // overwrite file
                }

            }
        }
    }
}





