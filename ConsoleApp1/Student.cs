﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace ConsoleApp1
{
    internal class Student
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
                    marksSum += exam[i].Mark;
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
            if (exam[0].Name == "Example")
            {
                Array.Resize(ref _exam, exams.Length);
            }
            else Array.Resize(ref _exam, _exam.Length + exams.Length);

            for (int i = 0; i < exams.Length;i++)
            {
                exam[i + (exam.Length - exams.Length)] = exams[i];
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

        public virtual string ToShortString()
        {
            return $"{person.ToString()}\n{education}\n{group}\n{avrMark}";
        }
    }
}
