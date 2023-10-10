using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace ConsoleApp1
{
    internal class Student : Person
    {
        private Person _person;
        private Education _education;
        private int _group;
        private Exam[] _exam;

        internal Student( Person person, Education education, int group )
        {
            _person = person;
            _education = education;
            _group = group;
            _exam = new Exam[1];
            _exam[0] = new Exam("Example", 0, DateTime.Now);
        }

        internal Student()
        {
            _person = new Person();
            _education = Education.Bachelor;
            _group = 0;
            _exam = new Exam[1];
            _exam[0] = new Exam("Example", 0, DateTime.Now);
        }
        
        public Person person { get { return _person; } set { _person = value; } }
        public Education education { get { return _education; } set { _education = value; } }
        public int group { get { return _group;} set { _group = value; } }
        public Exam[] exam { get { return _exam; } set { _exam = value; } }

        public double avrMark
        {
            get
            {
                int marksCount = 0;
                double marksSum = 0;
                for (int i = 0; i < _exam.Length; i++)
                {
                    marksCount++;
                    marksSum += exam[i].mark;
                }
                return marksSum / marksCount;
            }
        }
        public bool this[Education educ]
        {
            get
            {
                if (educ == education) return true;
                else return false;
            }
        }

        public void AddExams( params Exam[] exams)
        {
            if (exam[0].name == "Example")
            {
                Array.Resize(ref _exam, exams.Length);
            }
            else Array.Resize(ref _exam, _exam.Length + exams.Length);

            for (int i = 0; i < exams.Length;i++)
            {
                exam[i + (exam.Length - exams.Length)] = exams[i].DeepCopy() as Exam;
            }
        }

        public override string ToString()
        {
            string res = $"{person.ToString()}\n{education}\n{group}";
            for (int i = 0; i < exam.Length; i++)
            {
                res += $"\n{exam[i].ToString()}" ;
            }
            return res;
        }

        public override string ToShortString()
        {
            return $"{person.ToString()}\n{education}\n{group}\n{avrMark}";
        }
        public override bool Equals(object obj)
        {
            return Equal(obj as Student);
        }

        private bool Equal(Student stud)
        {
            if (person != stud.person || education != stud.education || group != stud.group || exam.Length != stud.exam.Length)
            {
                return false;
            }
            for (int i = 0; i < exam.Length; i++)
            {
                if (exam[i] != stud.exam[i])
                {
                    return false;
                }
            }

            return true;
        }

        public static bool operator ==(Student stud1, Student stud2)
        {
            return stud1.Equal(stud2);
        }

        public static bool operator !=(Student ex1, Student ex2)
        {
            return !ex1.Equal(ex2);
        }

        public override int GetHashCode()
        {
            int res = person.GetHashCode() + group.GetHashCode() + education.GetHashCode();
            for (int i = 0;i < exam.Length; i++)
            {
                res += exam[i].GetHashCode();
            }
            return res;
        }

        public override object DeepCopy()
        {
            Student newStud = new Student(person.DeepCopy() as Person, education, group);
            newStud.AddExams(exam);
            return newStud;
        }
        //public DateTime Date { get { return person.birthday; } set { person.birthday = value; } }
    }

}
