/* ===== ===== =====

Theory of Programming

Breadth First Search Algorithm
http://theoryofprogramming.com/2014/12/25/breadth-first-search-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node * next;
};

struct node * insert(struct node * head, int num)
{
	// This is exactly as Head Insertion of a Linked List.
	// We choose Head Insertion to get an O(1) Insertion
	// into an Adjacency List, Tail Insertion can also be used
	
	struct node * p = (struct node *) malloc(sizeof(struct node));
	
	p->val = num;
	p->next = head;

	return p;
}

void breadth_first_search(struct node * list[], int vertices, int parent[], int level[])
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

int main()
{
	int vertices, edges, i, j, v1, v2;
	
	printf("Enter the number of Vertices -\n");
	scanf("%d", &vertices);
	
	printf("Enter the number of Edges -\n");
	scanf("%d", &edges);

	struct node * adjacency_list[vertices + 1];
	// This is the table of our Adjacency List
	// Each element holds a Linked List
	// In C++ it can be made to hold a vector too
	// in that case, the declaration would be -
	// vector< vector<int> > adjacency_list;
	
	int parent[vertices + 1];
	// Each element of Parent Array holds the Node value of its parent
	int level[vertices + 1];	
	// Each element of Level Array holds the Level value of that node
	
	for (i = 0; i <= vertices; ++i) {
		//Initialising our arrays
		adjacency_list[i] = NULL;
		parent[i] = 0;
		level[i] = -1;
	}

	for (i = 1; i <= edges; ++i) {
		scanf("%d%d", &v1, &v2);
		adjacency_list[v1] = insert(adjacency_list[v1], v2);
		adjacency_list[v2] = insert(adjacency_list[v2], v1);
		// For edge {v1, v2} = {2, 3},
		// Adjacency List holds 2----3
		// and 3-----2 as edges
	}
	
	// Printing Adjacency List
	printf("\nAdjacency List -\n");
	for (i = 1; i <= vertices; ++i) {
		printf("%d -> ", i);
		
		struct node * temp = adjacency_list[i];
		
		while (temp != NULL) {
			printf("%d -> ", temp->val);
			temp = temp->next;
		}
		
		printf("NULL\n");
	}

	breadth_first_search(adjacency_list, vertices, parent, level);
	
	// Level Array
	printf("\nLevel and Parent Arrays -\n");
	for (i = 1; i <= vertices; ++i) {
		printf("Level of Node %d is %d, Parent is %d\n", i, level[i], parent[i]);
	}
	
	return 0;
}
