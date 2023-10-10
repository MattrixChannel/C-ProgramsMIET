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
            Console.WriteLine(stud.ToString());
            Console.WriteLine();
            Console.WriteLine();
            stud.person = new Person("Petr", "Braslavskii", new DateTime(2004, 4, 30));
            stud.education = Education.Specialist;
            stud.group = 430;
            Exam[] examss = { new Exam("IT", 4, DateTime.Now), new Exam("Math", 5, DateTime.Now), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Now) };
            List<Exam> exams = new List<Exam>( examss);
            Test[] testss = { new Test("Art", false) };
            Console.WriteLine(testss[0].ToString());
            List<Test> tests = new List<Test>(testss);
            stud.AddExams(exams);
            stud.AddTests(tests);
            Console.WriteLine(stud.ToString());
            Student a2 = stud.DeepCopy() as Student;

            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine(stud != a2);

            stud.exam[0].name = "Not IT";
            stud.name = "Mr Walter";
            stud.education = Education.Bachelor;
            stud.birthday = new DateTime(2003, 3, 29);
            stud.group = 160;
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine(stud.ToString());
            Console.WriteLine();
            Console.WriteLine(a2.ToString());
            Console.WriteLine();
            Console.WriteLine(stud != a2);

            Console.WriteLine();
            Console.WriteLine();

            Test theTest = new Test();
            Console.WriteLine(theTest.ToString());

            Console.WriteLine();
            Console.WriteLine();

            Console.WriteLine(stud.name + ' ' + stud.person.name);
            stud.person.name = "123";
            Console.WriteLine(stud.name + ' ' + stud.person.name);

            Console.WriteLine();
            Console.WriteLine();

            Console.WriteLine("Все предметы");
            foreach(object i in stud)
            {
                Console.WriteLine(i.ToString());
            }

            Console.WriteLine();
            Console.WriteLine();

            Console.WriteLine("Все экзы 4+");
            foreach (Exam i in stud.GetEnumeratorWithMark(3))
            {
                Console.WriteLine(i.ToString());
            }
            Console.ReadKey();
            //*/
        }
    }
}