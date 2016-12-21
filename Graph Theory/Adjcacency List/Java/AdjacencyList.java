/* ===== ===== =====

Theory of Programming

Adjacency List using Collections API
http://theoryofprogramming.com/2014/12/24/graph-theory-basics/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.LinkedList;
import java.util.Scanner;
import javafx.util.Pair;

public class AdjacencyList {
    private final LinkedList< Pair<Integer, Integer> >[] adjacencyList;
    
    // Constructor
    public AdjacencyList(int vertices) {
        adjacencyList = (LinkedList< Pair<Integer, Integer> >[]) new LinkedList[vertices];
        
        for (int i = 0; i < adjacencyList.length; ++i) {
            adjacencyList[i] = new LinkedList<>();
        }
    }
    
    // Appends a new Edge to the linked list
    public void addEdge(int startVertex, int endVertex, int weight) {
        adjacencyList[startVertex].add(new Pair<>(endVertex + 1, weight));
    }
    
    // Returns number of vertices
    // Does not change for an object
    public int getNumberOfVertices() {
        return adjacencyList.length;
    }
    
    // Returns number of outward edges from a vertex
    public int getNumberOfEdgesFromVertex(int startVertex) {
        return adjacencyList[startVertex].size();
    }
    
    // Returns a copy of the Linked List of outward edges from a vertex
    public LinkedList< Pair<Integer, Integer> > getEdgesFromVertex(int startVertex) {
        LinkedList< Pair<Integer, Integer> > edgeList
                            = (LinkedList< Pair<Integer, Integer> >) new LinkedList(adjacencyList[startVertex]);
        
        return edgeList;
    }
    
    // Prints the Adjaency List
    public void printAdjacencyList() {
        int i = 0;
        
        for (LinkedList< Pair<Integer, Integer> > list : adjacencyList) {
            System.out.print("adjacencyList[" + (i + 1) + "] -> ");
            
            for (Pair<Integer, Integer> edge : list) {
                System.out.print(edge.getKey() + "(" + edge.getValue() + ") ");
            }
            
            ++i;
            System.out.println();
        }
    }
    
    // Removes an edge and returns true if there
    // was any change in the collection, else false
    public boolean removeEdge(int startVertex, Pair<Integer, Integer> edge) {
        return adjacencyList[startVertex - 1].remove(edge);
    }
    
    public boolean hasEdge(int startVertex, int endVertex, int weight) {
        return adjacencyList[startVertex].contains(new Pair<>(endVertex, weight));
    }
}

class TestGraph
{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        int vertices = s.nextInt();
        int edges = s.nextInt();
        int u, v, weight;
        
        AdjacencyList adjacencyList = new AdjacencyList(vertices);
        
        int i = 0;
        
        while (i < edges) {
            u = s.nextInt() - 1;
            v = s.nextInt() - 1;
            weight = s.nextInt();
            
            adjacencyList.addEdge(u, v, weight);
            ++i;
        }
        
        System.out.println("The Adjacency List -");
        adjacencyList.printAdjacencyList();
        
        System.out.println("Remove - " + adjacencyList.removeEdge(2, new Pair<>(3, 2)));
        
        System.out.println("The Adjacency List -");
        adjacencyList.printAdjacencyList();
        
        System.out.println(adjacencyList.hasEdge(2, 3, 2));
    }
}