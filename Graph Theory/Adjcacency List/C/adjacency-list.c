/* ===== ===== =====

Theory of Programming

Adjacency List Data Structure
http://theoryofprogramming.com/2014/12/24/graph-theory-basics/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */
 
#include <stdio.h>
#include <stdlib.h>
 
struct Edge {
    int vertex;
    struct Edge * next;
};

// Inserts Node to the Linked List by Head Insertion - O(1)
// Returns address of head which is the newly created node.
struct Edge * addEdge(struct Edge * currentHead, int newVertex)
{
    struct Edge * newHead = (struct Edge *) malloc(sizeof(struct Edge));
 
    newHead->vertex = newVertex;
    newHead->next = currentHead;
 
    return newHead;
}

int main()
{
    int vertices, edges, i, v1, v2;
 
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
 
    printf("\nEnter the Number of Edges -\n");
    scanf("%d", &edges);
 
    struct Edge * adjacencyList[vertices + 1];
    // Size is made (vertices + 1) to use the
    // array as 1-indexed, for simplicity
 
    // Must initialize your array
    for (i = 0; i <= vertices; ++i) {
        adjacencyList[i] = NULL;
    }
 
    for (i = 1; i <= edges; ++i) {
        scanf("%d%d", &v1, &v2);
        
        // Adding edge v1 --> v2
        adjacencyList[v1] = addEdge(adjacencyList[v1], v2);
		
        // Adding edge v2 --> v1
        // Remove this if you want a Directed Graph
        adjacencyList[v2] = addEdge(adjacencyList[v2], v1);
    }
 
    // Printing Adjacency List
    printf("\nAdjacency List -\n\n");
    for (i = 1; i <= vertices; ++i) {
        printf("adjacencyList[%d] -> ", i);
 
        struct Edge * traverse = adjacencyList[i];
 
        while (traverse != NULL) {
            printf("%d -> ", traverse->vertex);
            traverse = traverse->next;
        }
 
        printf("NULL\n");
    }
 
    return 0;
}
