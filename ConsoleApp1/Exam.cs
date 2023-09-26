using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Exam
    {
        public string Name { get; set; }
        public int Mark { get; set; }
        public DateTime Date { get; set; }

        internal Exam(string _Name, int _Mark, DateTime _Date)
        {
            Name = _Name;
            Mark = _Mark;
            Date = _Date;
        }
        internal Exam()
        {
            Name = "Math";
            Mark = 1;
            Date = DateTime.Now;
        }

        public override string ToString()
        {
            return $"{Name} {Mark} {Date}";
        }


    }
}
