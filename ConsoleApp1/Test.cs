using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Test
    {
        public string name { get; set; }
        public bool pass { get; set; }

        internal Test()
        {
            this.name = "Sample Name";
            this.pass = true;
        }
        internal Test(string name, bool pass)
        {
            this.name = name;
            this.pass = pass;
        }

        public override string ToString()
        {
            return name + " " + pass;
        }
    }
}
