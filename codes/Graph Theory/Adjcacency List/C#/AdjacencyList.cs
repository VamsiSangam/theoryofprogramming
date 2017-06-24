/* ===== ===== =====

Theory of Programming

Adjacency List Data Structure
http://theoryofprogramming.com/2014/12/24/graph-theory-basics/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

using System;
using System.Collections.Generic;
  
namespace TheoryOfProgramming
{
    class AdjacencyList
    {
        private LinkedList<Tuple<int, int>>[] adjacencyList;
  
        // Constructor - creates an empty Adjacency List
        public AdjacencyList(int vertices)
        {
            adjacencyList = new LinkedList<Tuple<int, int>>[vertices];
  
            for (int i = 0; i < adjacencyList.Length; ++i)
            {
                adjacencyList[i] = new LinkedList<Tuple<int, int>>();
            }
        }
  
        // Appends a new Edge to the linked list
        public void addEdgeAtEnd(int startVertex, int endVertex, int weight)
        {
            adjacencyList[startVertex - 1].AddLast(new Tuple<int, int>(endVertex, weight));
        }
  
        // Adds a new Edge to the linked list from the front
        public void addEdgeAtBegin(int startVertex, int endVertex, int weight)
        {
            adjacencyList[startVertex - 1].AddFirst(new Tuple<int, int>(endVertex, weight));
        }
  
        // Returns number of vertices
        // Does not change for an object
        public int getNumberOfVertices()
        {
            return adjacencyList.Length;
        }
  
        // Returns a copy of the Linked List of outward edges from a vertex
        public LinkedList<Tuple<int, int>> this[int index]
        {
            get
            {
                LinkedList<Tuple<int, int>> edgeList
                               = new LinkedList<Tuple<int, int>>(adjacencyList[index - 1]);
  
                return edgeList;
            }
        }
  
        // Prints the Adjacency List
        public void printAdjacencyList()
        {
            int i = 0;
  
            foreach (LinkedList<Tuple<int, int>> list in adjacencyList)
            {
                Console.Write("adjacencyList[" + (i + 1) + "] -> ");
  
                foreach (Tuple<int, int> edge in list)
                {
                    Console.Write(edge.Item1 + "(" + edge.Item2 + ") ");
                }
  
                ++i;
                Console.WriteLine();
            }
        }
  
        // Removes the first occurence of an edge and returns true
        // if there was any change in the collection, else false
        public bool removeEdge(int startVertex, int endVertex, int weight)
        {
            Tuple<int, int> edge = new Tuple<int, int>(endVertex, weight);
  
            return adjacencyList[startVertex - 1].Remove(edge);
        }
    }
  
    class TestGraph
    {
        public static void Main()
        {
            Console.WriteLine("Enter the number of vertices -");
            int vertices = Int32.Parse(Console.ReadLine());
  
            AdjacencyList adjacencyList = new AdjacencyList(vertices);
  
            Console.WriteLine("Enter the number of edges -");
            int edges = Int32.Parse(Console.ReadLine());
  
            Console.WriteLine("Enter the edges with weights -");
            int startVertex, endVertex, weight;
  
            for (int i = 0; i < edges; ++i)
            {
                startVertex = Int32.Parse(Console.ReadLine());
                endVertex = Int32.Parse(Console.ReadLine());
                weight = Int32.Parse(Console.ReadLine());
  
                adjacencyList.addEdgeAtEnd(startVertex, endVertex, weight);
            }
  
            adjacencyList.printAdjacencyList();
            Console.WriteLine("Remove edge - " + adjacencyList.removeEdge(1, 2, 1));
            adjacencyList.printAdjacencyList();
        }
    }
}