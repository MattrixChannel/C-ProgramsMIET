using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Person : IDateAndCopy
    {
        protected string _name;
        protected string _surName;
        protected DateTime _birthday;

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
            _birthday = DateTime.Today;
        }

        public string Name
        {
            get => _name;
            set => _name = value;
        }

        public string Surname
        {
            get { return _surName; }
            set
            {
                _surName = value;
            }
        }
        
        public System.DateTime Birthday
        {
            get => _birthday;
            set => _birthday = value;
        }

        public int BirthdayYear
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
            return Equal(obj as Person);
        }

        private bool Equal(Person pers)
        {
            if (Name == pers.Name && Surname == pers.Surname && Birthday == pers.Birthday) { return true; }
            return false;
        }

        public static bool operator ==(Person pers1, Person pers2)
        {
            return pers1.Equal(pers2);
        }

        public static bool operator !=(Person pers1, Person pers2)
        {
            return !pers1.Equal(pers2);
        }

        public override int GetHashCode()
        {
            return Name.GetHashCode() + Surname.GetHashCode() + Birthday.GetHashCode();
        }

        public virtual object DeepCopy()
        {
            return new Person(Name, Surname, Birthday);
        }

        public DateTime Date { get { return Birthday; } set { Birthday = value; } }
    }
}
