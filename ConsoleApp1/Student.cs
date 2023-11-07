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

        internal Student(Person person, Education education, int group) : base(person.Name, person.Surname, person.Birthday)
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

        public Person Person
        {
            get { return base.DeepCopy() as Person; }
            set
            {

                if (value.GetType() == typeof(Person))
                {
                    Name = (value as Person).Name; // !!!!!!!!!!
                    Surname = (value as Person).Surname;
                    Birthday = (value as Person).Birthday;
                }

                else
                {
                    Name = base.Name;
                    Surname = base.Surname;
                    Birthday = base.Birthday;
                }
            }
        }
        public Education Education { get { return _education; } set { _education = value; } }
        public int Group
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
        public List<Exam> _Exam { get { return _exam; } set { _exam = value; } }
        public List<Test> _Test { get { return _test; } set { _test = value; } }

        public double AvrMark
        {
            get
            {
                if (_exam.Count == 0)
                {
                    return 0;
                }
                int marksCount = 0;
                double marksSum = 0;
                for (int i = 0; i < _exam.Count; i++)
                {
                    marksCount++;
                    marksSum += _Exam[i].Mark;
                }
                return marksSum / marksCount;
            }
        }
        public bool this[Education educ]
        {
            get
            {
                if (educ == Education) return true;
                else return false;
            }
        }

        public void AddExams(Exam[] exams)
        {
            for (int i = 0; i < exams.Length; i++)
            {
                _Exam.Add(exams[i].DeepCopy() as Exam);
            }
        }
        public void AddTests(Test[] tests)
        {
            for (int i = 0; i < tests.Length; i++)
            {
                _Test.Add(tests[i].DeepCopy() as Test);
            }
        }

        public override string ToString()
        {
            string res = $"{Person}\n{Education}\n{Group}";

            for (int i = 0; i < _Exam.Count; i++)
            {
                res += $"\n{_Exam[i]}";
            }

            for (int i = 0; i < _Test.Count; i++)
            {
                res += $"\n{_Test[i]}";
            }
            return res;
        }

        public override string ToShortString()
        {
            return $"{Person}\n{Education}\n{Group}\n{AvrMark}\n{_Exam.Count}\n{_Test.Count}";
        }
        public override bool Equals(object obj)
        {
            return Equal(obj as Student);
        }

        private bool Equal(Student stud)
        {
            if (Person != stud.Person || Education != stud.Education || Group != stud.Group || _Exam.Count != stud._Exam.Count)
            {
                return false;
            }
            for (int i = 0; i < _Exam.Count; i++)
            {
                if (_Exam[i] != stud._Exam[i])
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
            int res = Person.GetHashCode() + Group.GetHashCode() + Education.GetHashCode();
            for (int i = 0; i < _Exam.Count; i++)
            {
                res += _Exam[i].GetHashCode();
            }
            for (int i = 0; i < _Test.Count; i++)
            {
                res += _Test[i].GetHashCode();
            }
            return res;
        }

        public override object DeepCopy()
        {
            Student newStud = new Student(Person.DeepCopy() as Person, Education, Group);
            newStud.AddExams(_Exam.ToArray());
            newStud.AddTests(_Test.ToArray());
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
            for (int i = 0; i < _Exam.Count; i++)
            {
                if (_Exam[i].Mark > mark)
                {
                    yield return _Exam[i];
                }
            }
        }

        public IEnumerable GetEnumeratorInExamAndTest()
        {
            foreach (var i in _Exam)
            {
                foreach (var j in _Test)
                {
                    if (i.Name == j.Name)
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

            foreach (var i in _Test)
            {
                if (i.Pass)
                {
                    yield return i;
                }
            }
        }

        public IEnumerable GetEnumeratorExamAndTestPassed()
        {
            foreach (var j in _Test)
            {
                foreach (var i in _Exam)
                {
                    if (i.Name == j.Name && i.Mark > 2 && j.Pass)
                        yield return j;
                }
            }
        }

        public IEnumerator GetPassed()
        {
            return new StudentEnum(_exam, _test);
        }

        public void SortExamsName()
        {
            _exam.Sort((x1, x2) => x1.CompareTo(x2));
        }

        public void SortExamsMark()
        {
            _exam.Sort((x1, x2) => x1.Mark.CompareTo(x2.Mark));
        }

        public void SortExamsDate()
        {
            _exam.Sort(Exam.SortDate());
        }


    }

}
