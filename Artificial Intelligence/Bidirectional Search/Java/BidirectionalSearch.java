/* ===== ===== =====

Theory of Programming

- Bidirectional Search
Website - http://theoryofprogramming.com/2018/01/21/bidirectional-search/
Github - https://github.com/VamsiSangam/theoryofprogramming

===== ===== ===== */

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class BidirectionalSearch {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int vertices = in.nextInt();
        int edges = in.nextInt();
        LinkedList< Integer >[] adjacencyList = (LinkedList< Integer >[]) new LinkedList[vertices + 1];
        
        // Initialising Adjacency List
        for (int i = 1; i < adjacencyList.length; ++i) {
            adjacencyList[i] = new LinkedList<>();
        }
        
        // Add edges to Adjacency List
        for (int i = 0; i < edges; ++i) {
            // Take 1-indexed input
            int u = in.nextInt();
            int v = in.nextInt();
            
            adjacencyList[u].add(v);
            adjacencyList[v].add(u);
        }
        
        int source = in.nextInt();
        int goal = in.nextInt();
        LinkedList<Integer> path = bidirectionalSearch(adjacencyList, source, goal);
        
        if (path != null) {
            System.out.print("Path from " + source + " to " + goal + " => ");
            for (int vertex : path) {
                System.out.print(vertex + " ");
            }
        } else {
            System.out.println("Path not found.");
        }
    }
    
    // Method for BiDirectional Search which does Breadth First Search from source and goal vertices
    public static LinkedList<Integer> bidirectionalSearch(LinkedList< Integer >[] adjacencyList, int source, int goal) {
        // To keep a track of the paths from source and goal
        int[] sourceParent = new int[adjacencyList.length];
        int[] goalParent = new int[adjacencyList.length];
        
        // Queue for BFS at source and goal
        LinkedList<Integer> sourceQueue = new LinkedList<>();
        LinkedList<Integer> goalQueue = new LinkedList<>();
        
        // Initialise parent arrays to infinity
        Arrays.fill(sourceParent, Integer.MAX_VALUE);
        Arrays.fill(goalParent, Integer.MAX_VALUE);
        
        // set parent of source and goal as -1
        sourceParent[source] = -1;
        goalParent[goal] = -1;
        sourceQueue.add(source);
        goalQueue.add(goal);
        
        while (!sourceQueue.isEmpty() || !goalQueue.isEmpty()) {
            BFSExplore(adjacencyList, sourceQueue, sourceParent);
            BFSExplore(adjacencyList, goalQueue, goalParent);
            
            int intersectingVertex = getIntersectingVertex(sourceParent, goalParent);
            
            if (intersectingVertex != -1) {
                // Both BFS has intersected, contruct and return the path
                return getPath(sourceParent, goalParent, intersectingVertex);
            }
        }
        
        return null;
    }
    
    public static void BFSExplore(LinkedList< Integer >[] adjacencyList, LinkedList<Integer> queue, int[] parent) {
        if (queue.isEmpty()) {
            return;
        }
        
        int vertex = queue.pollFirst();
        System.out.println("vertex = " + vertex);
        
        for (int adjacentVertex : adjacencyList[vertex]) {
            if (parent[adjacentVertex] == Integer.MAX_VALUE) {  // if parent is not set, it is unvisited
                parent[adjacentVertex] = vertex;
                queue.add(adjacentVertex);
            }
        }
    }
    
    public static int getIntersectingVertex(int[] sourceParent, int[] goalParent) {
        for (int i = 1; i < sourceParent.length; ++i) {
            if (sourceParent[i] != Integer.MAX_VALUE && goalParent[i] != Integer.MAX_VALUE) {
                // If the parent has been set by both BFS from source
                // and goal, then this is our intersecting vertex
                return i;
            }
        }
        
        return -1;
    }
    
    public static LinkedList<Integer> getPath(int[] sourceParent, int[] goalParent, int intersectingVertex) {
        LinkedList<Integer> path = new LinkedList<>();
        int vertex = intersectingVertex;
        
        // Add vertices from source to intersecting vertex in a backward fashion
        while (vertex != -1) {
            path.addFirst(vertex);
            vertex = sourceParent[vertex];
        }
        
        // Add vertices from intersecting vertex to goal vertex. But the
        // intersecting vertex was already added. So start from it's parent instead.
        vertex = goalParent[intersectingVertex];
        
        while (vertex != -1) {
            path.add(vertex);
            vertex = goalParent[vertex];
        }
        
        return path;
    }

}
