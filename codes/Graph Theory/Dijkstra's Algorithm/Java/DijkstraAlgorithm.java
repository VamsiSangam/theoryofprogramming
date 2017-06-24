/* ===== ===== =====

Theory of Programming

Dijkstra's Algorithm - O(V^2) implementation
http://theoryofprogramming.com/2015/01/11/dijkstras-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Saurabh Rane (github.com/ranesr)

===== ===== ===== */

public class DijkstraAlgorithm {

	// Number of vertices
	private int vertices;

	// Constructor
	public DijkstraAlgorithm(int vertices) {
		this.vertices = vertices;
	}

	// A utility function to find the vertex with minimum distance value,
	// from the set of vertices not yet included in shortest path tree
	public int minDistance(int[] dist, boolean[] sptSet) {

		// Initialize min value
		int min = Integer.MAX_VALUE;
		int minIndex = -1;

		for(int v = 0; v < vertices; v++) {
			if(!sptSet[v] && dist[v] <= min) {
				min = dist[v];
				minIndex = v;
			}
		}

		return minIndex;
	}

	// A utility function to print the constructed distance array
	public void printSolution(int[] dist, int n) {
		System.out.println("Vertex \t\t Distance");
		
		for (int i = 0; i < vertices; i++) {
			System.out.println(i + "     \t\t " + dist[i]);
		}
	}

	// Funtion that implements Dijkstra's single source shortest path
	// algorithm for a graph represented using adjacency matrix
	// representation
	public void dijkstra(int[][] graph, int src) {
		
		// The output array. dist[i] will hold the shortest distance from src to i
		int[] dist = new int[vertices];

		// Shortest path tree set
		boolean[] sptSet = new boolean[vertices];

		// Initialize all distances as INFINITE and stpSet[] as false
		for(int i = 0; i < vertices; i++) {
			dist[i] = Integer.MAX_VALUE;
			sptSet[i] = false;
		}

		// Distance of source vertex from itself is always 0
		dist[src] = 0;

		// Find shortest path for all vertices
		for (int count = 0; count < vertices-1; count++) {

			// Pick the minimum distance vertex from the set of vertices
			// not yet processed. u is always equal to src in first
			// iteration.
			int u = minDistance(dist, sptSet);

			// Mark the picked vertex as processed
			sptSet[u] = true;

			// Update dist value of the adjacent vertices of the
			// picked vertex.
			for (int v = 0; v < vertices; v++) {

				// Update dist[v] only if is not in sptSet, there is an
				// edge from u to v, and total weight of path from src to
				// v through u is smaller than current value of dist[v]
				
				if (!sptSet[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && (dist[u] + graph[u][v]) < dist[v]) {
					dist[v] = dist[u] + graph[u][v];
				}
			}
		}

		// Print the constructed distance array
		printSolution(dist, vertices);
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

		DijkstraAlgorithm da = new DijkstraAlgorithm(9);
		da.dijkstra(graph, 0);
	}
	
	/*
	Shortest Path
	
	   (4)    (12)    (19)
	    1 ---- 2 ----- 3
	   /       |
	  /        |
	 /         |
	0(0)       8(14)       4(21)
	 \                    /
	  \                  /
	   \                /
	    7 ---- 6 ----- 5
	   (8)    (9)     (11)
	
	
	*/
}
