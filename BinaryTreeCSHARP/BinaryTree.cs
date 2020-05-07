using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTreeCSHARP
{
    public class BinaryTree<T> where T : IComparable<T>
    {
        class Node
        {
            public T value;
            public Node left; // pointer to node from the left subtree
            public Node right; // pointer to node from the right subtree
            public Node(T _value)
            {
                value = _value;
                left = null;
                right = null;
            }
        }
        Node root;

        public BinaryTree() //create binary tree
        {
            root = null; //the tree is empty
        }

        public void Add(T value)
        {
            if (root == null) //if the tree is empty
            {
                root = new Node(value); //add the value to the root
            }
            else
            {
                Add(value, ref root); //else add the value to it's place
            }
        }

        private void Add(T value, ref Node root) // add new node to it's place
        {
            if (root == null) //if the tree is empty
            {
                root = new Node(value); //add the value to the root
            }
            else if (value.CompareTo(root.value) < 0) Add(value, ref root.left); //if the value is less than root, add new to the left subtree
            else if (value.CompareTo(root.value) > 0) Add(value, ref root.right); //if the value is bigger than root, add new to the right subtree
            else throw new ArgumentException("The value is already in the tree!"); //there can't be two equal values in the tree
        }

        public void Remove(T value)
        {
            Remove(value, ref root);
        }

        private void Remove(T value, ref Node root) //removes the value from the tree
        {
            if (root == null) //there is no such value
            {
                throw new ArgumentException("Not found");
            }
            if (value.CompareTo(root.value) > 0) Remove(value, ref root.right); // looking for a value in the right subtree
            else if (value.CompareTo(root.value) < 0) Remove(value, ref root.left); // looking for a value in the left subtree
            else
            {
                Node temp = root;
                if (temp.right == null && temp.left == null) // if no children -> no root
                {
                    root = null;
                }
                else if (temp.right == null && temp.left != null) // no right child -> left child goes to the root
                {
                    root = temp.left;
                }
                else if (temp.left == null && temp.right != null) // no left child -> right child goes to the root
                {
                    root = temp.right;
                }
                else //if the root had either right, or left child
                {
                    Node maxNode = temp.left; //replace deleted item with the max value from the left subtree
                    while (maxNode.right != null) maxNode = maxNode.right;
                    temp.value = maxNode.value;
                    Remove(maxNode.value, ref temp.left);
                }
            }
        }


        private string BinaryTreeAsString(Node node)// output the tree
        {
            string leftStr = (node.left == null) ? "{}" : BinaryTreeAsString(node.left); //print left subtree 
            string rightStr = (node.right == null) ? "{}" : BinaryTreeAsString(node.right); //print right subtree
            string result = "{" + (node.value).ToString() + ", " + leftStr + ", " + rightStr + "}"; //firstly, print note, then left subtree, then right subtree
            return result;
        }
        public override string ToString()
        {
            if (root == null) return "{}"; //the tree is empty
            else return BinaryTreeAsString(root); //output the tree
        }

        public List<T> Traversal()
        {
            List<T> top = new List<T>();
            Traversal(top, ref root);
            return top;
        }

        private List<T> Traversal(List<T> top, ref Node root)
        {
            if (root != null)
            {
                Traversal(top, ref root.left); // go around left subtree
                top.Add(root.value); // add value to the end of vector top
                Traversal(top, ref root.right); // go around right subtree
            }
            return top;
        }

        public List<T> GetLeafList() //looking for leaves
        {
            List<T> leafList = new List<T>();
            getLeaf(ref root, leafList);
            return leafList;
        }

        private void getLeaf(ref Node root, List<T> leaf) // looking for leaves - leaves have no children
        {
            if (root.left == null && root.right == null) // no children
            {
                leaf.Add(root.value); // add to the vector leafList
            }
            else // node has a child
            {
                if (root.left != null) getLeaf(ref root.left, leaf); // go down to the left
                if (root.right != null) getLeaf(ref root.right, leaf); // go down to the right
            }
        }

        public bool Found(T value) //lookung for a value in the tree
        {
            return Found(value, ref root);
        }

        private bool Found(T value, ref Node root) // looking for a value in the tree
        {
            if (root == null) return false; // no root, no tree
            else if (value.CompareTo(root.value) == 0) return true; // root==value, value is found
            else if (value.CompareTo(root.value) > 0) return Found(value, ref root.right); // value>root, then we go to the right subtree
            else return Found(value, ref root.left); // value<root, then we go to the left subtree
        }
    }
}
