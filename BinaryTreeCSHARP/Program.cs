using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTreeCSHARP
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree<int> tree = new BinaryTree<int>();
            tree.Add(15);
            tree.Add(2);
            tree.Add(3);
            tree.Add(20);
            tree.Add(21);
            Console.WriteLine("Binary tree: \n" + tree);

            Console.WriteLine("Tree traversal:");
            List<int> traversal = tree.Traversal();
            foreach (var item in traversal)
                Console.Write(item + "  ");

            Console.WriteLine("\nLeaves:");
            List<int> leaves = tree.GetLeafList();
            foreach (var item in leaves)
                Console.Write(item + "  ");

            tree.Remove(3);
            Console.WriteLine("\nRemove 3\nBinary tree: \n" + tree);

            if (tree.Found(15)) Console.WriteLine("15 is found in the tree");
            if (!tree.Found(5)) Console.WriteLine("5 is not found in the tree");

            Console.ReadKey();
        }
    }
}
