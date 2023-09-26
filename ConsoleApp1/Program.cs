using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public enum Education
    {
        Specialist,
        Bachelor,
        SecondEducation
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Person a = new Person("Peter", "Brasl", DateTime.Now);
            Person b = new Person();
            Person c = b;
            Console.WriteLine(a.Equals(b));
            Console.WriteLine(a.Equals(c));
            Console.WriteLine(b.Equals(c));
        }
    }
}