/* ===== ===== =====

Theory of Programming

Bellman Ford Algorithm
http://theoryofprogramming.com/2015/01/19/bellman-ford-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */
  
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// This has the vertex number of a vertex
// in the negative cycle if it exists
int negativeVertex = -1;
  
// This is used to construct
// the Adjacency List
struct node {
    int vertex, weight;
    struct node * next;
};
  
// This is used to construct the Shortest Paths to all
// vertices, as we cannot return multiple values,
// we use a struct
struct pathInfo {
    int distance, parent;
};
  
// Adds a new edge into the Adjacency List
// Follows Head Insertion for O(1) Insertion
struct node * add(struct node * head, int vertex, int weight)
{
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
  
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = head;
  
    return newNode;
}
  
// Bellman-Ford Algorithm which takes the Graph (adjacencyList[]), starting vertex (startVertex),
// and an empty array shortestDistances[] as input. It applies the algorithm and keeps filling values
// into shortestDistances[]. It returns 1 if there are no negative edges, and vice-versa.
int bellmanFord(struct node * adjacencyList[], int vertices, int startVertex, struct pathInfo shortestDistances[])
{
    struct node * traverse;
    int i, j, k;
  
    // Initialisation
    for (i = 0; i <= vertices; ++i) {
        shortestDistances[i].distance = INT_MAX;
        shortestDistances[i].parent = -1;
    }
  
    // Setting distance to source = 0
    shortestDistances[startVertex].parent = 0;
    shortestDistances[startVertex].distance = 0;
  
    // The Algorithm that computes Shortest Distances
    for (i = 1; i <= vertices - 1; ++i) {        // Runs 'vertices - 1' times = O(|V|)
        for (j = 1; j <= vertices; ++j) {        // Runs as many times as the edges = O(|E|)
            // The code ahead basically explores the whole of Adjcency List,
            // covering one edge once, so the runtime of the code in this
            // block is O(|E|)
  
            traverse = adjacencyList[j];
  
            while (traverse != NULL) {
                if (shortestDistances[j].distance == INT_MAX) {
                    // Important...!
                    traverse = traverse->next;
                    continue;
                }
  
                // Checking for Relaxation
                if (traverse->weight + shortestDistances[j].distance < shortestDistances[traverse->vertex].distance) {
                    // Relaxation
                    shortestDistances[traverse->vertex].distance = traverse->weight + shortestDistances[j].distance;
                    shortestDistances[traverse->vertex].parent = j;
                }
  
                traverse = traverse->next;
            }
        }
    }
  
    // Checking for Negative Cycles
    for (j = 1; j <= vertices; ++j) {
        traverse = adjacencyList[j];
  
        while (traverse != NULL) {
            // Checking for further relaxation
            if (traverse->weight + shortestDistances[j].distance < shortestDistances[traverse->vertex].distance) {
                // Negative Cycle found as further realxation is possible
                negativeVertex = j;
				return 0;
            }
  
            traverse = traverse->next;
        }
    }
  
    return 1;
}

void printNegativeCycle(struct pathInfo shortestDistances[], int vertex, int startVertex)
{
    if (vertex == startVertex) {
        printf("%d ", vertex);
    } else if (shortestDistances[vertex].parent == 0) {
        printNegativeCycle(shortestDistances, startVertex, startVertex);
        printf("%d ", vertex);
    } else {
        printNegativeCycle(shortestDistances, shortestDistances[vertex].parent, startVertex);
        printf("%d ", vertex);
    }
}
  
int main()
{
    int vertices, edges, i, j, v1, v2, weight;
  
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
  
    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);
  
    struct node * adjacency_list[vertices + 1];
    // Size is made (vertices + 1) to use the
    // array as 1-indexed, for simplicity
  
    // Must initialize your array
    for (i = 0; i <= vertices; ++i) {
        adjacency_list[i] = NULL;
    }
    printf("Enter the edges -\n\n");
  
    for (i = 1; i <= edges; ++i) {
        scanf("%d%d%d", &v1, &v2, &weight);
        adjacency_list[v1] = add(adjacency_list[v1], v2, weight);
    }
  
    // Printing Adjacency List
    printf("\nAdjacency List -\n\n");
    for (i = 1; i <= vertices; ++i) {
        printf("adjacency_list[%d] -> ", i);
  
        struct node * temp = adjacency_list[i];
  
        while (temp != NULL) {
            printf("(%d, %d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }
  
        printf("NULL\n");
    }
  
    struct pathInfo shortestDistances[vertices + 1];
    int startVertex;
  
    printf("\nEnter a Start Vertex -\n");
    scanf("%d", &startVertex);
  
    if (bellmanFord(adjacency_list, vertices, startVertex, shortestDistances) == 1) {
        printf("No Negative Cycles exist in the Graph -\n");
    } else {
        printf("Negative Cycles exists\nNegative Cycle vertices - ");
        printNegativeCycle(shortestDistances, shortestDistances[negativeVertex].parent, negativeVertex);
        // The Bellman-Ford Algorithm does not work with negative cycles,
        // all it can do is merely detect them, so when a negative cycle
        // is detected, the shortestDistances array has wrong values
        return 0;
    }
  
    printf("\n\nVertex\tShortest Distance to Vertex %d\tParent Vertex -\n", startVertex);
    for (i = 1; i <= vertices; ++i) {
        printf("%d\t%d\t\t\t\t%d\n", i, shortestDistances[i].distance, shortestDistances[i].parent);
    }
  
    return 0;
}
