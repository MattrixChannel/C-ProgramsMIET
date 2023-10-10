using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class StudentEnum : IEnumerator
    {
        public List<Exam> _exam;
        public List<Test> _test;

        private int Size { get { return _exam.Count + _test.Count; } }
        private int examSize { get { return _exam.Count; } }
        private int testSize { get { return _test.Count; } }

        private bool inExam { get { if(position >= examSize) return false; return true; } }
        private bool inTest { get { if(position >= examSize) return true; return false; } }

        int position = -1;

        public StudentEnum(List<Exam> exam, List<Test> test)
        {
            _exam = exam;
            _test = test;
        }

        public bool MoveNext()
        {
            position++;
            return (position < Size);
        }

        public void Reset()
        {
            position = -1;
        }

        object IEnumerator.Current
        {
            get
            {
                return Current;
            }
        }

        public object Current
        {
            get
            {
                try
                {
                    if(position < examSize) return _exam[position];
                    else return _test[position - examSize];
                }
                catch (IndexOutOfRangeException)
                {
                    throw new InvalidOperationException();
                }
            }
        }

    }
}
