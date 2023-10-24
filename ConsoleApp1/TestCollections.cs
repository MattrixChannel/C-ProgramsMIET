using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class TestCollections<TKey, TValue>
    {
        private List<TKey> keys;
        private List<string> strings;
        private Dictionary<TKey, TValue> keyVal;
        private Dictionary<string, TValue> strVal;
        private GenerateElement<TKey, TValue> element;
    }
}
