/* ===== ===== =====

Theory of Programming

Depth First Search Algorithm
http://theoryofprogramming.com/2014/12/26/depth-first-search-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node * next;
};

struct node * add(struct node * head, int num)
{
	// We use Head Insertion for inserting vertices
	// into Linked List for O(1) Insertion.
	
	struct node * newNode = (struct node *) malloc(sizeof(struct node));
	
	newNode->val = num;
	newNode->next = head;
	
	return newNode;
}

void DFSExplore(struct node * adjacencyList[], int parent[], int vertex)
{
	struct node * temp = adjacencyList[vertex];
	
	// recursively visit all vertices accessible from this Vertex
	while (temp != NULL) {
		if (parent[temp->val] == -1) {
			parent[temp->val] = vertex;
			// We started exploring from Vertex -'vertex',
			// so the Vertex - temp->val, it's
			// parent should be our initial vertex
			
			DFSExplore(adjacencyList, parent, temp->val);
			// Then we recursively visit everything from the child vertex
		}
		
		temp = temp->next;
		// After finishing, move on to next Vertex
		// adjacent to the vertex - 'vertex'
	}
}

void DFS(struct node * adjacencyList[], int length, int parent[])
{
	int i;
	
	for (i = 1; i <= length; ++i) {
		
		if (parent[i] == -1) {
			parent[i] = 0;
			// It is a completely un-visited vertex and we start
			// our DFS from here, so it has no parent, but just
			// to mark it that we visited this node, we assign 0
			
			DFSExplore(adjacencyList, parent, i);
			// By this we begin to explore all the
			//  vertices reachable from Vertex i
		}
	}
}

int main()
{
	int vertices, edges, i, j, v1, v2;
	
	printf("Enter the Number of Vertices -\n");
	scanf("%d", &vertices);
	
	printf("Enter the Number of Edges -\n");
	scanf("%d", &edges);
	
	struct node * adjacencyList[vertices + 1];
	int parent[vertices + 1];
	// Size is made (vertices + 1) to use the
	// array as 1-indexed, for simplicity
	
	// Must initialize your array
	for (i = 0; i <= vertices; ++i) {
		adjacencyList[i] = NULL;
		parent[i] = -1;
	}
	
	printf("\n");
	
	for (i = 1; i <= edges; ++i) {
		scanf("%d%d", &v1, &v2);
		adjacencyList[v1] = add(adjacencyList[v1], v2);		// Adding edge v1 ------> v2
	}
 
 	// Printing Adjacency List
	printf("\nAdjacency List -\n\n");
	for (i = 1; i <= vertices; ++i) {
		printf("adjacencyList[%d] -> ", i);
		
		struct node * temp = adjacencyList[i];
		
		while (temp != NULL) {
			printf("%d -> ", temp->val);
			temp = temp->next;
		}
		
		printf("NULL\n");
	}
	
	DFS(adjacencyList, vertices, parent);
	
	printf("\nParent Array -\n");
	for (i = 1; i <= vertices; ++i) {
		printf("Parent of Vertex %d = %d\n", i, parent[i]);
	}
	
	return 0;
}
