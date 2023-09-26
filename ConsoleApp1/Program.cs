using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    

    internal class Program
    {
        static void Main(string[] args)
        {
            //Person a = new Person("Peter", "Brasl", DateTime.Now);
            //Student a1 = new Student(a, Education.Bachelor, 26);
            //Person b = a.DeepCopy() as Person;
            //Person c = new Person();
            Student stud = new Student();
            stud.person = new Person("Petr", "Braslavskii", new DateTime(2004, 4, 30));
            stud.education = Education.Specialist;
            stud.group = 26;
            Exam[] exams = { new Exam("IT", 4, DateTime.Now), new Exam("Math", 5, DateTime.Now), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Now), };
            stud.AddExams(exams);
            Console.WriteLine(stud.ToString());
            Student a2 = stud.DeepCopy() as Student;
            Console.WriteLine();
            Console.WriteLine(a2.ToString());
            Console.WriteLine();
            a2.education = Education.SecondEducation;
            Console.WriteLine(stud.GetHashCode());
            Console.WriteLine(a2.GetHashCode());
        }
    }
}