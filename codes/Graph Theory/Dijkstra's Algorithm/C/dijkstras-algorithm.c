/* ===== ===== =====

Theory of Programming

Dijkstra's Algorithm - O(V^2) implementation
http://theoryofprogramming.com/2015/01/11/dijkstras-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node of the adjacency list
struct node {
    int vertex, weight;
    struct node * next;
};

// Follows head insertion to give O(1) insertion
struct node * addEdge(struct node * head, int vertex, int weight)
{    
    struct node * newNode = (struct node *) calloc(1, sizeof(struct node));
     
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = head;
     
    return newNode;
}

// Retuns the vertex which is not visited and has least distance
int getMinVertex(int distances[], int visited[], int vertices) 
{
	int min = INT_MAX, index = -1, i;
	
	for (i = 1; i <= vertices; ++i) {
		if (visited[i] == 0 && min > distances[i]) {
			min = distances[i];
			index = i;
		}
	}
	
	return index;
}

// Dijkstra's Algorithm function
void dijkstra(struct node * adjacencyList[], int vertices, int startVertex, int distances[], int parent[])
{
    int i, visited[vertices + 1];
    
    // Initially no routes to vertices are know, so all are infinity
    for (i = 1; i <= vertices; ++i) {
        distances[i] = INT_MAX;
        parent[i] = 0;
        visited[i] = 0;    
    }
     
    // Setting distance to source to zero
    distances[startVertex] = 0;
    
    for (i = 1; i <= vertices; ++i) {     // Untill there are vertices to be processed
        int minVertex = getMinVertex(distances, visited, vertices);	// Greedily process the nearest vertex
		struct node * trav = adjacencyList[minVertex];    // Checking all the vertices adjacent to 'min'
		visited[minVertex] = 1;
		
        while (trav != NULL) {
        	int u = minVertex;
        	int v = trav->vertex;
        	int w = trav->weight;
        	
            if (distances[u] != INT_MAX && distances[v] > distances[u] + w) {
                // We have discovered a new shortest route, make the neccesary adjustments in data
                distances[v] = distances[u] + w;
                parent[v] = u;
            }
            
            trav = trav->next;
        }
    }
}

// Recursively looks at a vertex's parent to print the path
void printPath(int parent[], int vertex, int startVertex)
{
    if (vertex == startVertex) {	// reached the source vertex
        printf("%d ", startVertex);
        return;
    } else if (parent[vertex] == 0) {	// current vertex has no parent
    	printf("%d ", vertex);
    	return;
	} else {	// go for the current vertex's parent
        printPath(parent, parent[vertex], startVertex);
        printf("%d ", vertex);
    }
}

int main()
{
    int vertices, edges, i, j, v1, v2, w, startVertex;
    
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);
    
    struct node * adjacencyList[vertices + 1];	// to use the array as 1-indexed for simplicity
    int distances[vertices + 1];
    int parent[vertices + 1];
    
    for (i = 0; i <= vertices; ++i) {	// Must initialize your array
        adjacencyList[i] = NULL;
    }
    
    for (i = 1; i <= edges; ++i) {
        scanf("%d%d%d", &v1, &v2, &w);
        adjacencyList[v1] = addEdge(adjacencyList[v1], v2, w);
    }
    
    printf("Enter start vertex -\n");
    scanf("%d", &startVertex);
    dijkstra(adjacencyList, vertices, startVertex, distances, parent);
	printf("Shortest distances -\n");
	
    for (i = 1; i <= vertices; ++i) {
    	printf("Vertex %d, Distance = %d, Parent = %d, ", i, distances[i], parent[i]);
    	printf("Path = ");
    	printPath(parent, i, startVertex);
    	printf("\n");
	}
    
    return 0;
}
