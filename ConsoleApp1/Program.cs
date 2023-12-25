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
        static void Main()
        {
            //* Testing
            /*
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

            /* Lab2 Program
            // 1 Создать два объекта типа Person с совпадающими данными и
            // проверить, что ссылки на объекты не равны, а объекты равны, вывести
            // значения хэш-кодов для объектов.
            Console.WriteLine("N1");

            Person FirstPerson = new Person();
            Person SecondPerson = new Person();
            Console.WriteLine(FirstPerson.ToString());
            Console.WriteLine(SecondPerson.ToString());

            Console.WriteLine(FirstPerson == SecondPerson);
            Console.WriteLine(FirstPerson.GetHashCode() + " " + SecondPerson.GetHashCode());

            Console.WriteLine();
            Console.WriteLine();
            // 2 Создать объект типа Student, добавить элементы в список экзаменов и
            // зачетов, вывести данные объекта Student.
            Console.WriteLine("N2");

            Student FirstStudent = new Student();

            Exam[] exams = { new Exam("IT", 4, DateTime.Now), new Exam("Math", 1, DateTime.Now), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Now) };
            Test[] tests = { new Test("Art", false) , new Test("PE", true), new Test("IT", false), new Test("Math", true)};
            FirstStudent.AddExams(exams);
            FirstStudent.AddTests(tests);
            
            Console.WriteLine(FirstStudent.ToString());

            Console.WriteLine();
            Console.WriteLine();
            // 3 Вывести значение свойства типа Person для объекта типа Student.
            Console.WriteLine("N3");
            Console.WriteLine(FirstStudent.Person);

            Console.WriteLine();
            Console.WriteLine();
            // 4 С помощью метода DeepCopy() создать полную копию объекта Student.
            // Изменить данные в исходном объекте Student и вывести копию и
            // исходный объект, полная копия исходного объекта должна остаться
            // без изменений.
            Console.WriteLine("N4");

            Student SecondStudent = FirstStudent.DeepCopy() as Student;
            FirstStudent.Name = "Peter";
            //FirstStudent.exam[0].name = "NEWNAME";
            exams[0].Name = "NEWNAMEeeee";
            Console.WriteLine(FirstStudent.ToString() + "\n\n" + SecondStudent.ToString());

            Console.WriteLine();
            Console.WriteLine();
            // 5 В блоке try/catch присвоить свойству с номером группы некорректное
            // значение, в обработчике исключения вывести сообщение, переданное
            // через объект - исключение
            Console.WriteLine("N5");
            try
            {
                FirstStudent.Group = 1;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Console.WriteLine();
            Console.WriteLine();
            // 6 С помощью оператора foreach для итератора, определенного в классе
            // Student, вывести список всех зачетов и экзаменов
            Console.WriteLine("N6");

            foreach(var i in FirstStudent)
            {
                Console.WriteLine(i.ToString());
            }

            Console.WriteLine();
            Console.WriteLine();
            // 7 С помощью оператора foreach для итератора с параметром
            // определенного в классе Student, вывести список всех экзаменов с
            // оценкой выше 3.
            Console.WriteLine("N7");

            Console.WriteLine("Все экзы 4+");
            foreach (var i in FirstStudent.GetEnumeratorWithMark(3))
            {
                Console.WriteLine(i.ToString());
            }

            Console.WriteLine();
            Console.WriteLine();
            // 8 С помощью оператора foreach для объекта типа Student вывести
            // список предметов, которые есть как в списке зачетов, так и в списке
            // экзаменов
            Console.WriteLine("N8");

            foreach(var i in FirstStudent.GetEnumeratorInExamAndTest())
            {
                Console.WriteLine(i.ToString());
            }

            Console.WriteLine();
            Console.WriteLine();
            // 9 определить итератор для перебора сданных зачетов и экзаменов
            // (объектов типа object), для этого определить метод, содержащий блок
            // итератора и использующий оператор yield; сданный экзамен -экзамен с
            // оценкой больше 2;
            Console.WriteLine("N9");

            foreach(var i in FirstStudent.GetEnumeratorPassed())
            {
                Console.WriteLine(i.ToString());
            }

            Console.WriteLine();
            Console.WriteLine();
            // 10 определить итератор для перебора всех сданных зачетов (объектов
            // типа Test), для которых сдан и экзамен, для этого определить метод,
            // содержащий блок итератора и использующий оператор yield.
            Console.WriteLine("N10");

            foreach(var i in FirstStudent.GetEnumeratorExamAndTestPassed())
            {
                Console.WriteLine(i.ToString());
            }
            */

            /* Lab3 Program
            Exam[] exams = { new Exam("Math", 1, DateTime.Today), new Exam("IT", 4, new DateTime(2023, 1, 1)), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Today) };

            //foreach (var exam in exams) { Console.WriteLine(exam.ToString()); }
            //Array.Sort(exams, Exam.SortDate());
            //Console.WriteLine();
            //foreach (var exam in exams) { Console.WriteLine(exam.ToString()); }

            Student FirstStudent = new Student();
  
            //Exam[] exams = { new Exam("IT", 4, DateTime.Now), new Exam("Math", 1, DateTime.Now), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Now) };
            Test[] tests = { new Test("Art", false), new Test("PE", true), new Test("IT", false), new Test("Math", true) };
            FirstStudent.AddExams(exams);
            FirstStudent.AddTests(tests);

            Console.WriteLine("\n============ До сортировки");
            Console.WriteLine("A " + FirstStudent);

            FirstStudent.SortExamsName();

            Console.WriteLine();
            Console.WriteLine("\n============ Сортировка по названию");
            Console.WriteLine("B " + FirstStudent);

            FirstStudent.SortExamsMark();

            Console.WriteLine();
            Console.WriteLine("\n============ Сортировка по оценке");
            Console.WriteLine("C " + FirstStudent);

            FirstStudent.SortExamsDate();

            Console.WriteLine();
            Console.WriteLine("\n============ Сортировка по дате");
            Console.WriteLine("D " + FirstStudent + "\n");

            StudentCollection<int> coll = new StudentCollection<int>((Student student) => student.GetHashCode());
            coll.AddDefaults();

            
            //Console.WriteLine("Collection: \n" + coll.ToString());

            Student[] studs = { new Student(), new Student(), new Student() };
            studs[0].Person = new Person("FirstName", "FirstSurname", new DateTime(2004, 4, 30));
            studs[0].AddExams(exams);
            studs[0].AddTests(tests);
            studs[1].Person = new Person("SecondName", "SecondsSurname", new DateTime(2011, 10, 5));
            studs[0].Education = Education.Specialist;
            studs[2].Person = new Person("ThirdName", "ThirSurname", new DateTime(2013, 12, 25));
            studs[2].Education = Education.Specialist;
            //Console.WriteLine(studs[0].Person.Name + " " + studs[1].Person.Name);

            coll.AddStudents(studs);

            Console.WriteLine();
            Console.WriteLine("\n============ Коллекция студентов:");
            Console.WriteLine("Collection: \n" + coll.ToString());

            //Console.WriteLine();
            //Console.WriteLine("Collection 2 ToShortString: \n" + coll.ToShortString());

            Console.WriteLine();
            Console.WriteLine("\n============ Максимальное среднее значение:");
            Console.WriteLine("Max average mark: " + coll.MaxAvr);

            Console.WriteLine();
            Console.WriteLine("\n============ Группировка по специалистам:");
            Console.WriteLine("Specialists:");
            foreach (var i in coll.EducationForm(Education.Specialist))
            {
                Console.WriteLine(i.Value.ToString());
            }

            Console.WriteLine();
            Console.WriteLine("\n============ Группировка по образованиям:");
            Console.WriteLine("Grouped:");
            foreach (var i in coll.GroupedByEducation())
            {
                foreach (var j in i.ToArray())
                Console.WriteLine(j.ToString());
            }

            KeyValuePair<Person, Student> genElem(int number)
            {
                Person pers = new Person($"{number}", "", DateTime.Now);
                Student stud = new Student(pers, Education.Specialist, 0);
                return new KeyValuePair<Person, Student>(pers, stud);
            }
            //Console.WriteLine(genElem(0).Value.ToShortString());
            TestCollections<Person, Student> testcoll = new TestCollections<Person, Student> (50, genElem);
            testcoll.Search();
            */

            Journal journal = new Journal();

            Exam[] exams = { new Exam("Math", 1, DateTime.Today), new Exam("IT", 4, new DateTime(2023, 1, 1)), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Today) };

            //foreach (var exam in exams) { Console.WriteLine(exam.ToString()); }
            //Array.Sort(exams, Exam.SortDate());
            //Console.WriteLine();
            //foreach (var exam in exams) { Console.WriteLine(exam.ToString()); }

            //Exam[] exams = { new Exam("IT", 4, DateTime.Now), new Exam("Math", 1, DateTime.Now), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Now) };
            Test[] tests = { new Test("Art", false), new Test("PE", true), new Test("IT", false), new Test("Math", true) };
            StudentCollection<int> coll1 = new StudentCollection<int>((Student student) => student.GetHashCode());
            coll1.Name = "Collection1";
            coll1.AddDefaults();

            StudentCollection<int> coll2 = new StudentCollection<int>((Student student) => student.GetHashCode());
            coll2.Name = "Collection2";
            coll2.AddDefaults();


            //Console.WriteLine("Collection: \n" + coll.ToString());

            Student[] studs = { new Student(), new Student(), new Student() };
            studs[0].Person = new Person("FirstName", "FirstSurname", new DateTime(2004, 4, 30));
            studs[0].AddExams(exams);
            studs[0].AddTests(tests);
            studs[1].Person = new Person("SecondName", "SecondsSurname", new DateTime(2011, 10, 5));
            studs[0].Education = Education.Specialist;
            studs[2].Person = new Person("ThirdName", "ThirSurname", new DateTime(2013, 12, 25));
            studs[2].Education = Education.Specialist;
            //Console.WriteLine(studs[0].Person.Name + " " + studs[1].Person.Name);

            coll1.AddStudents(studs[2]);
            coll2.AddStudents(studs[0]);
            coll2.AddStudents(studs[1]);

            Console.WriteLine();
            Console.WriteLine("\n============ Коллекция студентов 1:\n");
            Console.WriteLine(coll1.ToString());

            Console.WriteLine();
            Console.WriteLine("\n============ Коллекция студентов 2:\n");
            Console.WriteLine(coll2.ToString());

            //Console.WriteLine();
            //Console.WriteLine("Collection 2 ToShortString: \n" + coll.ToShortString());
            studs[0].Group = 120;
            studs[1].Education = Education.Specialist;

            coll1.Remove(studs[2]);

            Console.WriteLine("Journal entries one:\n");
            Console.WriteLine(Journal.ToString());
            Console.WriteLine();
            Console.WriteLine();

            coll2.Remove(studs[0]);

            Console.WriteLine("Journal entries two:\n");
            Console.WriteLine(Journal.ToString());
            Console.ReadKey();
        }
    }
}