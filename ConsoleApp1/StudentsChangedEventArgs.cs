using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class StudentsChangedEventArgs<TKey> : EventArgs
    {
        public string Name { get; set; }
        public Action Act { get; set; }
        public string PropertyName { get; set; }
        public TKey Key { get; set; }

        internal StudentsChangedEventArgs(string name, Action act, string propertyName, TKey key)
        {
            Name = name;
            Act = act;
            PropertyName = propertyName;
            Key = key;
        }
        
        public override string ToString()
        {
            return $"{Name} {PropertyName} {Act} {Key}";
        }
    }
}
