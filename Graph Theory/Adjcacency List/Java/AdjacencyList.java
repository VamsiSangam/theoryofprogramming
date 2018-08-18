/* ===== ===== =====

Theory of Programming

Adjacency List
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

import java.util.Scanner;

class Node
{
    /**
     * vertex - destination vertex of the edge
     * weight - weight of the edge
     * next - next node of the linked list
     */
    int vertex, weight;
    Node next;

    public Node(int vertex, int weight) {
        this.vertex = vertex;
        this.weight = weight;
    }
}

class AdjacencyListDemo
{
    public static void main(String[] args)
    {
        int vertices, edges, v1, v2, w;
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter the number of vertices - ");
        vertices = in.nextInt();
        System.out.print("Enter the number of edges - ");
        edges = in.nextInt();
        
        // Creating Adjacency List. Size is made |V| + 1 to
        // use the array by 1-indexing, for simplicity
        Node[] adjacencyList = new Node[vertices + 1];
        
        System.out.println("Enter " + edges + " edges. Three integers v1, v2, w -");
        
        for (int i = 0; i < edges; ++i) {
            // Scanning edge v1 -> v2 of weight 'w'
            v1 = in.nextInt();
            v2 = in.nextInt();
            w = in.nextInt();
            
            // Adding edge v1 -> v2
            adjacencyList[v1] = addEdge(adjacencyList[v1], new Node(v2, w));
            
            // To add edge v2 -> v1, uncomment line below
            // adjacencyList[v2] = addEdge(adjacencyList[v2], v1, w);
        }
        
        // Printing adjacency list
        print(adjacencyList);
        
        System.out.println("Input the edge to delete. Three integers v1, v2, w -");
        v1 = in.nextInt();
        v2 = in.nextInt();
        w = in.nextInt();
        
        adjacencyList[v1] = deleteEdge(adjacencyList[v1], new Node(v2, w));
        print(adjacencyList);
    }
    
    /**
     * Adds a new node in the linked list. Follows head insertion for O(1) performance.
     * 
     * @param oldHead head of the linked list to which new node is to be added
     * @param newEdge new edge to be added
     * @return new head of the linked list
     */
    public static Node addEdge(Node oldHead, Node newEdge)
    {
        // Add the new node to the start of linked list
        newEdge.next = oldHead;
        
        return newEdge;
    }
    
    public static Node deleteEdge(Node adjacencyList, Node edgeToBeRemoved)
    {
        Node head = adjacencyList;
        
        // Checking if head is edgeToBeRemoved
        if (head != null && head.vertex == edgeToBeRemoved.vertex && head.weight == edgeToBeRemoved.weight) {
            return head.next;
        }
        
        Node trav = head;
        
        while (trav != null) {
            Node travNext = trav.next;

            if (travNext != null) {
                // check of travNext is equal to edgeToBeRemoved

                if (travNext.vertex == edgeToBeRemoved.vertex && travNext.weight == edgeToBeRemoved.weight) {
                    // Remove travNext node
                    trav.next = travNext.next;
                    return head;
                }
            }
            
            trav = travNext;
        }
        
        return head;
    }
    
    public static void print(Node[] adjacencyList)
    {
        for (int i = 1; i < adjacencyList.length; ++i) {
            Node trav = adjacencyList[i];
            
            System.out.print("adjacencyList[" + i + "] -> ");
            
            while (trav != null) {
                System.out.print(trav.vertex + "(" + trav.weight + ") -> ");
                trav = trav.next;
            }
            
            System.out.println("NULL");
        }
    }
}