/* ===== ===== =====

Theory of Programming

Prim's Algorithm using C++ STL
http://theoryofprogramming.com/2015/03/27/prims-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <cstdio>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// Used for enqueing edges into priority queue
class Edge
{
	public:
		int u, v, weight;
};

// Custom comparator for priority queue
class Compare
{
	public:
	    bool operator() (Edge a, Edge b) {
	    	return b.weight < a.weight;
	    }
};

// Prim's Algorithm function
void prim(list< pair<int, int> > adjacencyList[], int vertices, int startVertex, list< pair<int, int> > MST[])
{
    int current = startVertex, newVertex, i;
    bool visited[vertices + 1];
    priority_queue<Edge, vector<Edge>, Compare> priorityQueue;
	
    for (i = 0; i <= vertices; ++i) {        // Initializing
        visited[i] = false;
    }
 
    i = 0;
 
    while (i < vertices) {
        if (!visited[current]) {            // If current node is not visited
            visited[current] = true;        // Mark it visited
            
            list< pair<int, int> >::iterator itr = adjacencyList[current].begin();
            
            while (itr != adjacencyList[current].end()) {                
				if (!visited[(*itr).first]) {
                    // If the edge leads to an un-visited
                    // vertex only then enqueue it
                    Edge outgoingEdge;
					
					outgoingEdge.u = current;
                	outgoingEdge.v = (*itr).first;
                	outgoingEdge.weight = (*itr).second;
                    priorityQueue.push(outgoingEdge);
                }
                
                ++itr;
			}
 			
 			Edge min = priorityQueue.top();
 			
			priorityQueue.pop();
            ///newVertex = min.v;
            //current = min.u;
 
            if (!visited[min.v]) {
                MST[min.u].push_back(make_pair(min.v, min.weight));
                MST[min.v].push_back(make_pair(min.u, min.weight));
            }
 
            current = min.v;
            ++i;
        } else {
 			Edge min = priorityQueue.top();
 			
			priorityQueue.pop();
            //newVertex = min.v;
            //current = min.u;
 
            if (!visited[min.v]) {
                MST[min.u].push_back(make_pair(min.v, min.weight));
                MST[min.v].push_back(make_pair(min.u, min.weight));
            }
 
            current = min.v;
        }
    }
}

int main()
{
	int vertices, edges, v1, v2, weight, startVertex;
	
	printf("Enter the Number of Vertices -\n");
	scanf("%d", &vertices);
	printf("Enter the Number of Edges -\n");
	scanf("%d", &edges);
	
	// Adjacency List is a vector of list.
	// Where each element is a pair<int, int>
	// pair.first -> the edge's destination
	// pair.second -> edge's weight
	list< pair<int, int> > adjacencyList[vertices + 1];
	list< pair<int, int> > MST[vertices + 1];
	
	printf("Enter the Edges V1 -> V2, of weight W\n");
	
	for (int i = 1; i <= edges; ++i) {
		scanf("%d%d%d", &v1, &v2, &weight);
		
		// Adding edges to the Directed Graph
		adjacencyList[v1].push_back(make_pair(v2, weight));
		adjacencyList[v2].push_back(make_pair(v1, weight));
	}
	
	printf("\nThe Adjacency List-\n");
	for (int i = 1; i <= vertices; ++i) {	// Printing Adjacency List
		printf("adjacencyList[%d] ", i);
		
		list< pair<int, int> >::iterator itr = adjacencyList[i].begin();
		
		while (itr != adjacencyList[i].end()) {
			printf(" -> %d(%d)", (*itr).first, (*itr).second);
			++itr;
		}
		printf("\n");
	}
 
    printf("\nEnter a Start Vertex - ");
    scanf("%d", &startVertex);
    prim(adjacencyList, vertices, startVertex, MST);
 
    printf("\nThe Minimum Spanning Tree-\n");
	for (int i = 1; i <= vertices; ++i) {	// Printing MST adjacency list
		printf("MST[%d] ", i);
		
		list< pair<int, int> >::iterator itr = MST[i].begin();
		
		while (itr != MST[i].end()) {
			printf(" -> %d(%d)", (*itr).first, (*itr).second);
			++itr;
		}
		printf("\n");
	}
	
	return 0;
}
