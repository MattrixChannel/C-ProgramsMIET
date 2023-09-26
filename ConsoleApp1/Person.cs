using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Person
    {
        private string _name;
        private string _surName;
        private System.DateTime _birthday;

        internal Person(string name, string surName, DateTime birthday)
        {
            _name = name;
            _surName = surName;
            _birthday = birthday;
        }

        internal Person()
        {
            _name = "Ivan";
            _surName = "Ivanov";
            _birthday = System.DateTime.Today;
        }

        public string name
        {
            get => _name;
            set => _name = value;
        }

        public string surname
        {
            get { return _surName; }
            set
            {
                _surName = value;
            }
        }

        public System.DateTime birthday
        {
            get => _birthday;
            set => _birthday = value;
        }

        public int birthdayYear
        {
            get => _birthday.Year;
            set
            {
                _birthday = new System.DateTime(value, _birthday.Month, _birthday.Day);
            }
        }

        public virtual string ToShortString()
        {
            return $"{_name} {_surName}";
        }

        public override string ToString()
        {
            return $"{_name} {_surName} {_birthday}";
        }
        
        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }

        public static bool operator ==(Person pers1, Person pers2)
        {
            return true;
        }

        public static bool operator !=(Person pers1, Person pers2)
        {
            return true;
        }
    }
}
