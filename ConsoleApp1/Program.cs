using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    interface IDateAndCopy
    {
        object DeepCopy();
        DateTime Date { get; set; }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            //* Testing
              
            Person a = new Person("Peter", "Brasl", DateTime.Now);
            Person b = a.DeepCopy() as Person;
            Console.WriteLine(a.ToString());
            Console.WriteLine(b.ToString());
            Console.WriteLine();
            Console.WriteLine();
            a.name = "123";
            Console.WriteLine(a.ToString());
            Console.WriteLine(b.ToString());

            Console.WriteLine();
            Console.WriteLine();

            Student stud = new Student();
            stud.person = new Person("Petr", "Braslavskii", new DateTime(2004, 4, 30));
            stud.education = Education.Specialist;
            stud.group = 26;
            Exam[] exams = { new Exam("IT", 4, DateTime.Now), new Exam("Math", 5, DateTime.Now), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Now), };
            stud.AddExams(exams);
            Console.WriteLine(stud.ToString());
            Student a2 = stud.DeepCopy() as Student;

            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine(stud != a2);

            stud.exam[0].name = "Not IT";
            stud.person.name = "Mr Walter";
            stud.education = Education.Bachelor;
            stud.person.birthday = new DateTime(2003, 3, 29);
            stud.group = 16;
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine(stud.ToString());
            Console.WriteLine();
            Console.WriteLine(a2.ToString());
            Console.WriteLine();
            Console.WriteLine(stud != a2);

            //*/
        }
    }
}