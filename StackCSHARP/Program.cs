using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StackCSHARP
{
    public class Stack<T>
    {
        T[] elements; // elements of the stack
        public int size; // current number of elements
        const int n = 10; // number of elements by default

        public Stack() //constructor
        {
            elements = new T[n]; //allocate memory
        }

        public Stack(int length) //constructor with a parameter
        {
            elements = new T[length]; //allocate memory
        }

        public void Push(T element) //add element
        {
            if (size == elements.Length) //stack is full
                throw new InvalidOperationException("Stack overflow!");
            elements[size++] = element; //puts the element to the stack
        }

        public bool IsEmpty //emptiness check
        {
            get { return size == 0; }
        }

        //public object get { get; private set; }

        public T Pop() //remove the element
        {
            if (IsEmpty) //stack is empty
                throw new InvalidOperationException("Stack is empty!");
            T element = elements[--size];
            elements[size] = default(T); // reset the link
            return element;
        }

        public T Peek()
        {
            return elements[this.size - 1]; //get peek of the stack
        }

        public void Print() //output the stack
        {
            foreach (var item in elements) Console.Write(item + "\t");
            Console.WriteLine();
        }
        
        public void Merge(ref Stack<T> res, ref Stack<T> s1, ref Stack<T> s2) //merge two stacks
        {
            int size1 = s1.size; //size of the 1st stack
            int size2 = s2.size; //size of the 2nd stack
            for (int i = 0; i < size1; i++)
            {
                res.Push(s1.Peek()); //push the last element from the 1st stack to result stack
                s1.Pop(); //remove the last element from the 1st stack
            }
            for (int i = 0; i < size2; i++)
            {
                res.Push(s2.Peek()); //push the last element from the 2nd stack to result stack
                s2.Pop(); //remove the last element from the 2nd stack
            }
        }
    }

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
            Stack<string> res = new Stack<string>();
            res.Merge(ref res, ref stack, ref stack2);
            res.Print();

            Console.ReadKey();
        }
    }

    
}
