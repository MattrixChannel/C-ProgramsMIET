using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using System.Xml.Schema;

namespace ConsoleApp1
{
    internal class Student : Person, IEnumerable
    {
        private Education _education;
        private int _group;
        private List<Exam> _exam;
        private List<Test> _test;

        internal Student(Person person, Education education, int group) : base(person.name, person.surname, person.birthday)
        {
            _education = education;
            _group = group;
            _exam = new List<Exam>();
            _test = new List<Test>();
        }

        internal Student()
        {
            _education = Education.Bachelor;
            _group = 0;
            _exam = new List<Exam>();
            _test = new List<Test>();
        }

        public Person person
        {
            get { return base.DeepCopy() as Person; }
            set
            {

                if (value.GetType() == typeof(Person))
                {
                    name = (value as Person).name; // !!!!!!!!!!
                    surname = (value as Person).surname;
                    birthday = (value as Person).birthday;
                }

                else
                {
                    name = base.name;
                    surname = base.surname;
                    birthday = base.birthday;
                }
            }
        }
        public Education education { get { return _education; } set { _education = value; } }
        public int group
        {
            get { return _group; }
            set
            {
                try
                {
                    if (value <= 100 || value > 599)
                    {
                        throw new Exception("Group number must be between 100 and 600");
                    }
                    else
                    {
                        _group = value;
                    }
                }
                catch (Exception e)
                {
                    throw;
                }
            }
        }
        public List<Exam> exam { get { return _exam; } set { _exam = value; } }
        public List<Test> test { get { return _test; } set { _test = value; } }

        public double avrMark
        {
            get
            {
                int marksCount = 0;
                double marksSum = 0;
                for (int i = 0; i < _exam.Count; i++)
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

        public void AddExams(Exam[] exams)
        {
            for (int i = 0; i < exams.Length; i++)
            {
                exam.Add(exams[i].DeepCopy() as Exam);
            }
        }
        public void AddTests(Test[] tests)
        {
            for (int i = 0; i < tests.Length; i++)
            {
                test.Add(tests[i].DeepCopy() as Test);
            }
        }

        public override string ToString()
        {
            string res = $"{person.ToString()}\n{education}\n{group}";

            for (int i = 0; i < exam.Count; i++)
            {
                res += $"\n{exam[i].ToString()}";
            }

            for (int i = 0; i < test.Count; i++)
            {
                res += $"\n{test[i].ToString()}";
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
            if (person != stud.person || education != stud.education || group != stud.group || exam.Count != stud.exam.Count)
            {
                return false;
            }
            for (int i = 0; i < exam.Count; i++)
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
            for (int i = 0; i < exam.Count; i++)
            {
                res += exam[i].GetHashCode();
            }
            return res;
        }

        public override object DeepCopy()
        {
            Student newStud = new Student(person.DeepCopy() as Person, education, group);
            newStud.AddExams(exam.ToArray());
            newStud.AddTests(test.ToArray());
            return newStud;
        }
        //public DateTime Date { get { return person.birthday; } set { person.birthday = value; } }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator)GetEnumerator();
        }

        public IEnumerator GetEnumerator()
        {
            return new StudentEnum(_exam, _test);
        }

        public IEnumerable<Exam> GetEnumeratorWithMark(int mark)
        {
            for (int i = 0; i < exam.Count; i++)
            {
                if (exam[i].mark > mark)
                {
                    yield return exam[i];
                }
            }
        }

        public IEnumerable GetEnumeratorInExamAndTest()
        {
            foreach(var i in exam)
            {
                foreach(var j in test)
                {
                    if (i.name == j.name)
                    yield return i;
                }
            }
        }

        public IEnumerable GetEnumeratorPassed()
        {
            foreach (var i in GetEnumeratorWithMark(2))
            {
                yield return i;
            }

            foreach(var i in test)
            {
                if (i.pass)
                {
                    yield return i;
                }
            }
        }

        public IEnumerable GetEnumeratorExamAndTestPassed()
        {
            foreach (var j in test)
            {
                foreach (var i in exam)
                {
                    if (i.name == j.name && i.mark > 2 && j.pass)
                        yield return j;
                }
            }
        }

        public IEnumerator GetPassed()
        {
            return new StudentEnum(_exam, _test);
        }
    }

}
