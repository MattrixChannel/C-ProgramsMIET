using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Test
    {
        public string Name { get; set; }
        public bool Pass { get; set; }

        internal Test()
        {
            this.Name = "Sample Name";
            this.Pass = true;
        }
        internal Test(string name, bool pass)
        {
            this.Name = name;
            this.Pass = pass;
        }

        public override string ToString()
        {
            return Name + " " + Pass;
        }

        public object DeepCopy()
        {
            return new Test(Name, Pass);
        }

        public override int GetHashCode()
        {
            return Name.GetHashCode() + Pass.GetHashCode();
        }
    }
}
