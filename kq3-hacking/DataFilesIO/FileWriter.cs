using System.Diagnostics;

namespace kq3_hacking.DataFilesIO
{
    public class FileWriter : IDisposable
    {
        private StreamWriter sw;
        private bool writeToConsole;
        private bool writeAsHtml = false; // is set to true if html header is written
        private bool swOpen = true;

        public FileWriter(string outputFilenamepath, bool showOutputToConsole = false)
        {
            Debug.WriteLine($"Writing to {outputFilenamepath}");
            sw = new StreamWriter(outputFilenamepath);
            this.writeToConsole = showOutputToConsole;
        }
        public void CloseStreamWriter()
        {
            if (writeAsHtml)
            {
                WriteHtmlFooter();
            }
            sw.Close();
            swOpen = false;
        }
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        protected virtual void Dispose(bool disposing)
        {
            if (disposing && sw != null)
            {
                if (swOpen)
                {
                    CloseStreamWriter();
                }
                sw.Dispose();
                sw = null;
            }
        }

        public void Write(string text)
        {
            sw.Write(text);
            if (writeToConsole)
            {
                Debug.Write($"{text}");
            }
        }

        public void WriteLine(string text)
        {
            sw.WriteLine(text);
            if (writeToConsole)
            {
                Debug.WriteLine($"{text}");
            }
        }

        public void WriteHtmlHeader(string browserTitle, string pageHeader)
        {
            writeAsHtml = true;
            string html_header = "" +
                $"<!DOCTYPE html>\n<html>\n<head>\n  <title>{browserTitle}</title>\n" +
                $"  <link href='/includes/styles.css' rel='stylesheet' type='text/css' />\n" +
                $"</head>\n<body>\n<b>{pageHeader}</b>\n<pre>";
            sw.WriteLine(html_header);
        }

        private void WriteHtmlFooter()
        {
            sw.WriteLine("</pre>\n</html>");
        }


        public static void SaveStringsToFile(List<string> lines, string filenamepath)
        {
            FileWriter fw = new(filenamepath);
            foreach (string line in lines)
            {
                fw.WriteLine(line);
            }
            fw.CloseStreamWriter();
        }

        public static void SaveStringToFile(string src, string filenamepath)
        {
            FileWriter fw = new(filenamepath);
            fw.Write(src);
            fw.CloseStreamWriter();
        }
    }
}




