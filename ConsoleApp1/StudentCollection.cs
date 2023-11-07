using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    delegate TKey KeySelector<TKey>(Student st);
    internal class StudentCollection<TKey>
    {
        private Dictionary<TKey, Student> dict;
        private KeySelector<TKey> keySelector;

        internal StudentCollection(KeySelector<TKey> keySelector)
        {
            this.keySelector = keySelector;
            dict = new Dictionary<TKey, Student>();
        }

        public void AddDefaults()
        {
            Student stud = new Student();
            dict.Add(keySelector(stud), stud);
        }
        public void AddStudents(params Student[] students)
        {
            foreach (Student student in students)
            {
                dict.Add(keySelector(student), student);
            }
        }

        public IEnumerable<KeyValuePair<TKey, Student>> EducationForm(Education value)
        {
            Dictionary<TKey, Student>  res = new Dictionary<TKey, Student> ();
            return dict.Where(stud => stud.Value.Education == value);
            //return new Dictionary<TKey, Student>(dict.Where());
        }

        public IEnumerable<IGrouping<Education, KeyValuePair<TKey, Student>>> GroupedByEducation()
        {
            return dict.GroupBy(stud => stud.Value.Education);
        }

        public double MaxAvr
        {
            get
            {
                if (dict.Count == 0) { return 0; }
                return dict.Values.Max(stud => stud.AvrMark);
            }
        }

        override public string ToString()
        {
            string res = string.Empty;
            foreach (Student student in dict.Values) { res += student.ToString() + "\n"; }
            return res;
        }

        public string ToShortString()
        {
            string res = string.Empty;
            foreach (Student student in dict.Values) {
                res += student.ToShortString() + "\n";
            }
            return res;
        }
    }
}
