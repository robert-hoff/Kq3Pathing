using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kq3_hacking.DataFilesIO
{
    class ReadDataFromFile
    {

        public static List<string> ReadFileAsStringList(string filenamepath, bool omitEmptyLines = false)
        {
            List<string> data = new();
            string[] lines = File.ReadAllLines($"{filenamepath}");
            foreach (var line in lines)
            {
                if (omitEmptyLines && line.Trim().Equals(""))
                {

                } else
                {
                    data.Add(line);
                }
            }
            return data;
        }


    }
}
