using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StackCSHARP
{ 
    class Program
    {
        static void Main(string[] args)
        {
            Stack<string> stack = new Stack<string>(5);
            stack.Push("1");
            stack.Push("2");
            stack.Push("3");
            stack.Push("4");
            stack.Push("5");
            stack.Print();

            stack.Pop();
            stack.Pop();
            stack.Print();

            Stack<string> stack2 = new Stack<string>(5);
            stack2.Push("1");
            stack2.Push("2");
            stack2.Push("3");
            stack2.Push("4");
            stack2.Push("5");

            Console.WriteLine();
            Stack<string> res = Stack<string>.Merge(stack, stack2);
            res.Print();

            Console.ReadKey();
        }
    }

    
}
