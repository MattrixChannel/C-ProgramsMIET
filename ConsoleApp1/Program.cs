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
            /*
            ===Testing Program===

            Student a = new Student();

            Exam[] exams = { new Exam("1", 2, DateTime.Now), new Exam("2", 5, DateTime.Now) };

            a.person = new Person("Peter", "Braslavskii", DateTime.Now);
            Console.WriteLine($"{a.person}");
            //Console.WriteLine($"{a.exam[0].ToString()}");
            //Console.WriteLine($"{a.avrMark}");
            Console.WriteLine($"{a[Education.Bachelor]}");
            a.AddExams( exams );
            a.AddExams( exams );
            a.AddExams( new Exam("Math", 100, DateTime.Now));
            Console.WriteLine($"{a.avrMark}, {a.exam[1]}, {a.exam.Length}");
            Console.WriteLine($"{a.ToString()}");
            Console.WriteLine($"{a.ToShortString()}");
            //Console.ReadKey();
            */
            Student stud = new Student();
            Console.WriteLine(stud.ToShortString());
            Console.WriteLine();
            Console.WriteLine(stud[Education.Bachelor]);
            Console.WriteLine(stud[Education.Specialist]);
            Console.WriteLine(stud[Education.SecondEducation]);
            Console.WriteLine();
            Console.WriteLine();

            

            stud.person = new Person("Petr", "Braslavskii", new DateTime(2004, 4, 30));
            stud.education = Education.Specialist;
            stud.group = 26;
            Exam[] exams = { new Exam("IT", 4, DateTime.Now), new Exam("Math", 5, DateTime.Now), new Exam("PE", 5, DateTime.Now), new Exam("Physics", 3, DateTime.Now), };
            stud.AddExams(exams);
            Console.WriteLine(stud.ToString());
            Console.WriteLine();
            Console.WriteLine();

            Stopwatch stopWatch1 = new Stopwatch();
            Stopwatch stopWatch2 = new Stopwatch();
            Stopwatch stopWatch3 = new Stopwatch();

            Exam exm = new Exam();
            int nrows, ncolumns, total;
            Console.WriteLine("Input: <Amount of Rows><devider><Amount of Columns>\nDeviders: /, |");
            string _answ = Console.ReadLine();
            string[] answ = _answ.Split(new char[] { '/', '|' });

            nrows = Int32.Parse(answ[0]);
            ncolumns = Int32.Parse(answ[1]);
            total = nrows * ncolumns;

            Console.WriteLine($"{nrows} {ncolumns}");


            Exam[] exms1 = new Exam[total];
            for (int i = 0; i < total; i++) {
                exms1[i] = exm;
                Console.Write("+ "); }
            Console.Write("\n\n");



            Exam[,] exms2 = new Exam[nrows, ncolumns];
            for (int i = 0; i < nrows; i++)
            {
                for (int j = 0; j < ncolumns; j++)
                {
                    exms2[i, j] = exm;
                    Console.Write("+ ");
                }
                Console.WriteLine();
            }


            int mas3Rows, mas3LastRow, count = total;

            for (int i = 1; ;i++)
            {
                if (count <= i)
                {
                    mas3Rows = i;
                    mas3LastRow = count;
                    break;
                }
                if (count > i)
                {
                    count -= i;
                }
            }
            Console.WriteLine();
            Exam[][] exms3 = new Exam[mas3Rows][];

            for (int i = 0; i < mas3Rows; i++)
            {
                if(i == mas3Rows-1)
                {
                    exms3[i] = new Exam[mas3LastRow];
                    for (int j = 0; j < mas3LastRow; j++)
                    {
                        exms3[i][j] = exm;
                        Console.Write("+ ");
                    }
                    break;
                }

                exms3[i] = new Exam[i + 1];
                for ( int j = 0; j < i+1; j++)
                {
                    exms3[i][j] = exm;
                    Console.Write("+ ");
                    //Console.Write(exms3[i][j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine("\n");
            stopWatch1.Start();
            for (int i = 0; i < total; i++)
            {
                exms1[i].Name = "NewName";
                //Console.Write("+ ");
            }
            stopWatch1.Stop();
            //Console.WriteLine(exms1[0].Name);
            //Console.WriteLine();
            //Console.WriteLine();
            stopWatch2.Start();
            for (int i = 0; i < nrows; i++)
            {
                for (int j = 0; j < ncolumns; j++)
                {
                    exms2[i, j].Name = "NewName";
                    //Console.Write("+ ");
                }
                //Console.WriteLine();
            }
            //Console.WriteLine();
            //Console.WriteLine();
            //Console.WriteLine(exms2[0, 0].Name);
            stopWatch2.Stop();


            int rowLen;
            stopWatch3.Start();
            for (int i = 0; i < mas3Rows; i++)
            {
                rowLen = exms3[i].Length;
                for (int j = 0; j < rowLen; j++)
                {
                    exms3[i][j].Name = "NewName";
                    //Console.Write("+ ");
                }
                //Console.WriteLine();
            }
            //Console.WriteLine(exms2[0, 1].Name);
            stopWatch3.Stop();

            Console.WriteLine($"\nTime for Mas:\n1: {stopWatch1.Elapsed}\n2: {stopWatch2.Elapsed}\n3: {stopWatch3.Elapsed}");

            //Console.ReadKey();
        }
    }
}