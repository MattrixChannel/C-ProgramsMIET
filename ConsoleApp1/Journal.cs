using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{    
    internal class Journal
    {
        internal class JournalEntry
        {
            public string CollectionName { get; set; }
            public Action Act { get; set; }
            public string PropertyName { get; set; }
            public string Key { get; set; }

            internal JournalEntry (string collectionName, Action act, string propertyName, string key)
            {
                CollectionName = collectionName;
                Act = act;
                PropertyName = propertyName;
                Key = key;
            }

            public override string ToString()
            {
                return $"{CollectionName} {Act} {PropertyName} {Key}";
            }
        }

        private static List<JournalEntry> entries;
        internal Journal()
        {
            entries = new List<JournalEntry>();
        }


        public static void c_NewEntry(object source, StudentsChangedEventArgs<string> args)
        {
            entries.Add(new JournalEntry(args.Name, args.Act, args.PropertyName, args.Key.ToString()));
        }

        public static void c_NewEntry(object sender, PropertyChangedEventArgs e)
        {
            entries.Add(new JournalEntry("Student", Action.Property, e.PropertyName, e.GetHashCode().ToString()));
        }

        public static string ToString()
        {
            string res = "";
            foreach (var entry in entries) { res += entry.ToString() + "\n"; }
            return res;
        }

    }
}
