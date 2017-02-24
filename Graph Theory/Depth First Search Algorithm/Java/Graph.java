/* ===== ===== =====

Theory of Programming

Depth First Search Algorithm
http://theoryofprogramming.com/2014/12/26/depth-first-search-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Saurabh Rane (https://github.com/ranesr)

===== ===== ===== */

import java.util.Iterator;
import java.util.LinkedList;

public class Graph {

	// No. of vertices
	private int v;

	// Adjacency Lists
	private LinkedList<Integer> adj[];

	// Constructor for Graph
	@SuppressWarnings("unchecked")
	public Graph(int v) {
		this.v = v;
		adj = new LinkedList[v];
		for (int i = 0; i < v; ++i) {
			adj[i] = new LinkedList<Integer>();
		}
	}

	// Function to add an edge into the undirectional graph
	public void addEdge(int v, int w) {
		adj[v].add(w);
		adj[w].add(v);
	}
	
	// The function to do DFS traversal. It uses recursive DFSUtil()
	public void dfs() {
		
		// Mark all the vertices as not visited (by default set as false)
		boolean visited[] = new boolean[v];
		
		// Call the recursive helper function to print DFS traversal
		for (int i = 0; i < v; ++i) {
			if (!visited[i]) {
				dfsUtil(i, visited);
			}
		}
	}
	
	private void dfsUtil(int v, boolean visited[]) {
		
		// Mark the current node as visited and print it
		visited[v] = true;
		System.out.print(v + " ");
		
		// Recur for all the vertices adjacent to this vertex
		Iterator<Integer> iterator = adj[v].listIterator();
		while (iterator.hasNext()) {				
			int n = iterator.next();

			if (!visited[n]) {
				dfsUtil(n, visited);
			}
		}
	}

	/*
	Graph
	  1 -- 2 -- 3
	 /    / \    \
	0 -- 7   8 -- 4
	 \       |    /
	  5 ____ 6 __/
	*/

	public static void main(String args[]) {
		Graph g = new Graph(9);

		g.addEdge(0, 1);
		g.addEdge(0, 5);
		g.addEdge(0, 7);
		g.addEdge(1, 2);
		g.addEdge(5, 6);
		g.addEdge(2, 8);
		g.addEdge(6, 8);
		g.addEdge(2, 3);
		g.addEdge(2, 7);
		g.addEdge(4, 3);
		g.addEdge(4, 6);
		g.addEdge(4, 8);

		System.out.println("Following is Depth First Traversal: ");
		g.dfs();
	}
}