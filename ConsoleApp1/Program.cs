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
            Person b = a.DeepCopy() as Person;
            Person c = b;
            Console.WriteLine(a.ToString());
            Console.WriteLine(b.ToString());
            //Console.WriteLine(b.GetHashCode());
            //Console.WriteLine(c.GetHashCode());

        }
    }
}