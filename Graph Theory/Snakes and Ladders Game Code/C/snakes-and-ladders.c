/* ===== ===== =====

Theory of Programming

Snakes and Ladders Game - Steps for quickest way to finish
http://theoryofprogramming.com/2014/12/25/snakes-and-ladders-game-code/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node * next;
};

// Adds a new edge, u --> v, to adjacencyList[u]
struct node * addEdge(struct node * head, int num)
{
	struct node * newNode = (struct node *) malloc(sizeof(struct node));
     
    newNode->val = num;
    newNode->next = head;
     
    return newNode;
}

void breadthFirstSearch(struct node * list[], int vertices, int parent[], int level[])
{
	struct node * temp;
	int i, par, lev, flag = 1;
	// 'lev' represents the level to be assigned
	// 'par' represents the parent to be assigned
	// 'flag' used to indicate if graph is exhausted
	
	lev = 0;
	level[1] = lev;
	// We start from node - 1
	// So, Node - 1 is at level 0
	// All immediate neighbours are at
	// level 1 and so on.
	
	while (flag) {
		flag = 0;
		for (i = 1; i <= vertices; ++i) {
			if (level[i] == lev) {
				flag = 1;
				temp = list[i];
				par = i;
				
				while (temp != NULL) {
					if (level[temp->val] != -1) {
						temp = temp->next;
						continue;
					}
					
					level[temp->val] = lev + 1;
					parent[temp->val] = par;
					temp = temp->next;
				}
			}
		}
		
		++lev;
	}
}

// Replaces the value of an edge (u -->) v to (u --> v')
// newNodes the entire list of adjacencyList[u] => O(|E|) operation
// Here, "v" is stored as "oldVertex" and "v'" is stored as "newVertex"
void replace(struct node * head, int num, int replacedNum)
{
	struct node * p = head;
	
	while (p->next != NULL) {
		if (p->val == num) {
			break;
		}
		
		p = p->next;
	}
	
	p->val = replacedNum;
}

// A recursive procedure to print the shortest path. Recursively
// looks at the parent of a vertex till the 'startVertex' is reached
// Not used in main(), just for reference
void printShortestPath(int parent[], int currentVertex, int startVertex)
{
    if (currentVertex == startVertex) {
        printf("%d ", currentVertex);
    } else if (parent[currentVertex] == 0) {
        printShortestPath(parent, startVertex, startVertex);
        printf("%d ", currentVertex);
    } else {
        printShortestPath(parent, parent[currentVertex], startVertex);
        printf("%d ", currentVertex);
    }
}

int main()
{
	int t;	// Test cases
	
	scanf("%d", &t);
	
	while (t--) {
		int vertices, edges, i, j, v1, v2;
		
		vertices = 100;		// Assume it is a 100 checks board
		edges = 0;
		
		struct node * list[vertices + 1];
		// This is the table of our Adjacency List
		// Each element holds a Linked List
		// In C++ it can be made to hold a vector too
		// in that case, the declaration would be -
		// vector< vector<int> > adjacency_list;
		
		int parent[vertices + 1];
		// Each element of Parent Array holds the Node value of its parent
		int level[vertices + 1];	
		// Each element of Level Array holds the Level value of that node
		
		// Initialising our arrays
		for (i = 0; i <= vertices; ++i) {
			list[i] = NULL;
			parent[i] = 0;
			level[i] = -1;
		}
		
		// Add normal edges representing movements by dice
		for (i = 1; i <= vertices; ++i) {
			for (j = 1; j <= 6 && j + i <= 100; ++j) {
				list[i] = addEdge(list[i], i + j);
				++edges;
			}
		}
		
		int numLadders, numSnakes;
		char temp;
		
		scanf("%d", &numLadders);
		
		// Ladder Edges
		int ladders[numLadders][2];
		
		for (i = 0; i < numLadders; ++i) {
			scanf("%d%c%d", &ladders[i][0], &temp, &ladders[i][1]);
			
			j = ladders[i][0] - 6;
			
			if (j < 1) {
				j = 1;
			}
			
			for (; j < ladders[i][0]; ++j) {
				replace(list[j], ladders[i][0], ladders[i][1]);
			}
		}
		
		scanf("%d", &numSnakes);
		
		// Snakes Edges
		int snakes[numSnakes][2];
		
		for (i = 0; i < numSnakes; ++i) {
			scanf("%d%c%d", &snakes[i][0], &temp, &snakes[i][1]);
			
			j = snakes[i][0] - 6;
			
			if (j < 0) {
				j = 0;
			}
			
			for (; j < snakes[i][0]; ++j) {
				replace(list[j], snakes[i][0], snakes[i][1]);
			}
		}
		
		breadthFirstSearch(list, vertices, parent, level);
		printf("%d\n", level[vertices]);
	}
	
	return 0;
}
