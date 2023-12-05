using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    delegate KeyValuePair<TKey, TValue> GenerateElement<TKey, TValue>(int number);
    internal class TestCollections<TKey, TValue>
    {
        private List<TKey> keys;
        private List<string> strings;
        private Dictionary<TKey, TValue> keyVal;
        private Dictionary<string, TValue> strVal;
        private GenerateElement<TKey, TValue> genElem;
        internal TestCollections(int size, GenerateElement<TKey, TValue> func) {
            genElem = func;

            keys = new List<TKey>(size);
            for (int i = 0; i < size; i++)
            {
                keys.Add(genElem(i).Key);
            }

            strings = new List<string> (size);
            for (int i = 0; i < size; i++)
            {
                strings.Add($"{genElem(i).Key}");
            }

            keyVal = new Dictionary<TKey, TValue>(size);
            for (int i = 0; i < size; i++)
            {
                keyVal.Add(keys[i], genElem(i).Value);
            }

            strVal = new Dictionary<string, TValue>(size);
            for (int i = 0; i < size; i++)
            {
                strVal.Add(strings[i], genElem(i).Value);
            }
        }
        public void Search()
        {
            //Console.WriteLine(keys[10]);
            //Console.WriteLine(genElem(10).Key);
            Stopwatch stopwatch = new Stopwatch();

            int size = keys.Count();
            bool result;
            stopwatch.Start();

            result = keys.Contains(keys[size - 1]);

            stopwatch.Stop();
            Console.WriteLine($"\nKeys first: {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = keys.Contains(keys[0]);

            stopwatch.Stop();
            Console.WriteLine($"\nKeys last {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = keys.Contains(keys[size/2]);

            stopwatch.Stop();
            Console.WriteLine($"\nKeys middle {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = keys.Contains(genElem(-1).Key);

            stopwatch.Stop();
            Console.WriteLine($"\nKeys out of range {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = strings.Contains(strings[0]);

            stopwatch.Stop();
            Console.WriteLine($"\nStringList first {result} {stopwatch.Elapsed}\n");
            stopwatch.Restart();
            stopwatch.Start();

            result = strings.Contains(strings[size-1]);

            stopwatch.Stop();
            Console.WriteLine($"\nStringList last {result} {stopwatch.Elapsed}\n");
            stopwatch.Restart();
            stopwatch.Start();

            result = strings.Contains(strings[size/2]);

            stopwatch.Stop();
            Console.WriteLine($"\nStringList middle {result} {stopwatch.Elapsed}\n");
            stopwatch.Restart();
            stopwatch.Start();

            result = strings.Contains("");

            stopwatch.Stop();
            Console.WriteLine($"\nStringList out of range {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = keyVal.ContainsKey(keys[0]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict TKey first {result} {stopwatch.Elapsed}\n");
            stopwatch.Restart();
            stopwatch.Start();

            result = keyVal.ContainsKey(keys[size-1]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict TKey last {result} {stopwatch.Elapsed}\n");
            stopwatch.Restart();
            stopwatch.Start();

            result = keyVal.ContainsKey(keys[size/2]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict TKey middle {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = keyVal.ContainsKey(genElem(-1).Key);

            stopwatch.Stop();
            Console.WriteLine($"\nDict TKey out of r {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = strVal.ContainsKey(strings[0]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict Strings first {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = strVal.ContainsKey(strings[size-1]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict Strings last {result} {stopwatch.Elapsed}\n");


            stopwatch.Restart();
            stopwatch.Start();

            result = strVal.ContainsKey(strings[size/2]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict Strings middle {result} {stopwatch.Elapsed}\n");

            stopwatch.Restart();
            stopwatch.Start();

            result = strVal.ContainsKey("");

            stopwatch.Stop();
            Console.WriteLine($"\nDict Strings out of {result} {stopwatch.Elapsed}\n");


            stopwatch.Restart();
            stopwatch.Start();

            result = keyVal.ContainsValue(keyVal[keys[0]]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict TVal first {result} {stopwatch.Elapsed}\n");
            stopwatch.Restart();
            stopwatch.Start();

            result = keyVal.ContainsValue(keyVal[keys[size-1]]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict TVal last {result} {stopwatch.Elapsed}\n");
            stopwatch.Restart();
            stopwatch.Start();

            result = keyVal.ContainsValue(keyVal[keys[size/2]]);

            stopwatch.Stop();
            Console.WriteLine($"\nDict TVal middle {result} {stopwatch.Elapsed}\n");
         
        }
    }
}
