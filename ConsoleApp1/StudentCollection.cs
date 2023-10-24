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

        override public string ToString()
        {
            string res = string.Empty;
            foreach (Student student in dict.Values) { res += student.ToString(); }
            return res;
        }
    }
}
