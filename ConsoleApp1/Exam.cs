using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace ConsoleApp1
{
    internal class Exam
    {
        public string name { get; set; }
        public int mark { get; set; }
        public DateTime date { get; set; }

        internal Exam(string _name, int _mark, DateTime _date)
        {
            name = _name;
            mark = _mark;
            date = _date;
        }
        internal Exam()
        {
            name = "Math";
            mark = 1;
            date = DateTime.Now;
        }

        public override string ToString()
        {
            return $"{name} {mark} {date}";
        }

        public override bool Equals(object obj)
        {
            return Equal(obj as Exam);
        }

        private bool Equal(Exam ex)
        {
            if (name == ex.name && mark == ex.mark && date == ex.date) { return true; }
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
            return name.GetHashCode() + mark.GetHashCode() + date.GetHashCode();
        }

        public object DeepCopy()
        {
            return new Exam(name, mark, date);
        }
    }
}
