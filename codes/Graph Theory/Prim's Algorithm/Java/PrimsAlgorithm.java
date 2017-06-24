/* ===== ===== =====

Theory of Programming

Prim's Algorithm in Java - O(V^2) implementation
http://theoryofprogramming.com/2015/03/27/prims-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Saurabh Rane (github.com/ranesr)

===== ===== ===== */

public class PrimsAlgorithm {

	// Number of vertices
	private int vertices;

	// Constructor
	public PrimsAlgorithm(int vertices) {
		this.vertices = vertices;
	}

	// A utility function to find the vertex with minimum key value,
	// from the set of vertices not yet included in MST
	public int minKey(int[] key, boolean[] mstSet) {

		// Initialize min value
		int min = Integer.MAX_VALUE;
		int minIndex = -1;

		for(int v = 0; v < vertices; v++) {
			if(!mstSet[v] && key[v] <= min) {
				min = key[v];
				minIndex = v;
			}
		}

		return minIndex;
	}
	
	// A utility function to print the constructed MST stored in parent[]
	public void printMST(int parent[], int n, int[][] graph) {
		System.out.println("Edge   Weight");
		
		for (int i = 1; i < vertices; i++) {
			System.out.println(parent[i] + " - " + i + "  " + graph[i][parent[i]]);
		}
	}
	
	// Function to construct and print MST for a graph represented
	// using adjacency matrix representation
	public void primMST(int[][] graph) {
		
		// Array to store constructed MST
		int parent[] = new int[vertices];
		
		// Key values used to pick minimum weight edge in cut
		int key[] = new int [vertices];
		
		// To represent set of vertices not yet included in MST
		boolean mstSet[] = new boolean[vertices];
		
		// Initialize all keys as INFINITE
		for(int i = 0; i < vertices; i++) {
			key[i] = Integer.MAX_VALUE;
			mstSet[i] = false;
		}
        
		// Always include first 1st vertex in MST.
		// Make key 0 so that this vertex is picked as first vertex
		key[0] = 0;
		
		// First node is always root of MST
		parent[0] = -1;
		
		// The MST will have vertices-1 edges
		for (int count = 0; count < vertices - 1; count++) {

			// Pick the minimum key vertex from the set of vertices not yet included in MST
			int u = minKey(key, mstSet);
			
			// Add the picked vertex to the MST Set
			mstSet[u] = true;
			
			// Update key value and parent index of the adjacent
			// vertices of the picked vertex. Consider only those
			// vertices which are not yet included in MST
			for (int v = 0; v < vertices; v++) {

				// graph[u][v] is non zero only for adjacent vertices of m
				// mstSet[v] is false for vertices not yet included in MST
				// Update the key only if graph[u][v] is smaller than key[v]
				if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] <  key[v]) {
					
					parent[v]  = u;
					key[v] = graph[u][v];
				}
			}
		}
		
		// Print the constructed MST
		printMST(parent, vertices, graph);
	}
		
	/*
	Input graph
	        8       7
	    1 ---- 2 ----- 3
	   /|      |\      |\
	4 / |     2| \4  14| \9
	 /  |      |  \    |  \
	0   |11    8   \   |   4
	 \  |    / |    \  |  /
	8 \ |  7/  |6    \ | /10
	   \|  /   |      \|/
	    7 ---- 6 ----- 5
	        1      2
	*/

	public static void main(String[] args) {
        
		int graph[][] = new int[][]{{0, 4, 0, 0, 0, 0, 0, 8, 0},
									{4, 0, 8, 0, 0, 0, 0, 11, 0},
									{0, 8, 0, 7, 0, 4, 0, 0, 2},
									{0, 0, 7, 0, 9, 14, 0, 0, 0},
									{0, 0, 0, 9, 0, 10, 0, 0, 0},
									{0, 0, 4, 14, 10, 0, 2, 0, 0},
									{0, 0, 0, 0, 0, 2, 0, 1, 6},
									{8, 11, 0, 0, 0, 0, 1, 0, 7},
									{0, 0, 2, 0, 0, 0, 6, 7, 0}};

		PrimsAlgorithm pa = new PrimsAlgorithm(9);
		
		// Print the edges and weights
		pa.primMST(graph);
	}
	
	/*
	MST
	
	   (4)    (4)     (7)
	    1      2 ----- 3
	   /       |\       \
	  /        | \       \
	 /         |  \       \
	0(0)    (2)8   \       4(9)
	 \              \
	  \              \
	   \              \
	    7 ---- 6 ----- 5
	   (8)    (1)     (2)
	*/
}
