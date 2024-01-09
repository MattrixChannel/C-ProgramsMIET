using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace ConsoleApp1
{
    [Serializable]
    internal class Exam : IComparable, IComparer<Exam>
    {
        public string Name { get; set; }
        public int Mark { get; set; }
        public DateTime Date { get; set; }

        internal Exam(string _name, int _mark, DateTime _date)
        {
            Name = _name;
            Mark = _mark;
            Date = _date;
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

        public override bool Equals(object obj)
        {
            return Equal(obj as Exam);
        }

        private bool Equal(Exam ex)
        {
            if (Name == ex.Name && Mark == ex.Mark && Date == ex.Date) { return true; }
            return false;
        }

        public static bool operator ==(Exam ex1, Exam ex2)
        {
            return ex1.Equal(ex2);
        }

        public static bool operator !=(Exam ex1, Exam ex2)
        {
            return !ex1.Equal(ex2);
        }

        public override int GetHashCode()
        {
            return Name.GetHashCode() + Mark.GetHashCode() + Date.GetHashCode();
        }

        public object DeepCopy()
        {
            return new Exam(Name, Mark, Date);
        }

        public int CompareTo(object obj)
        {
            return Name.CompareTo((obj as Exam).Name);
        }

        public int Compare(Exam x, Exam y)
        {
            if (x.Mark <  y.Mark) { return -1; }
            if (x.Mark == y.Mark) { return 0; }
            else return 1;
        }


        private class ExamCompareDate : IComparer<Exam>
        {
            public int Compare(Exam x, Exam y)
            {
                return DateTime.Compare(x.Date, y.Date);
            }
        }

        public static IComparer<Exam> SortDate()
        {
            return new ExamCompareDate();
        }
    }
}
