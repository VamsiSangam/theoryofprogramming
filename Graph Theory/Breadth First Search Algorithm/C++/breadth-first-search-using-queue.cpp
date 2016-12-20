/* ===== ===== =====

Theory of Programming

Breadth First Search Algorithm using (STL) Queue
http://theoryofprogramming.com/2014/12/25/breadth-first-search-algorithm/
Code Contributor - Vamsi Sangam

===== ===== ===== */
 
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
 
using namespace std;
 
void breadthFirstSearch(vector<list<int> > adjacencyList, int parent[], int level[], int start)
{
    list<int>::iterator itr;
 
    level[start] = 0;
    // We start from node - 1
	// So, Node - 1 is at level 0
	// All immediate neighbours are at
	// level 1 and so on.
 
    list<int> VertexQueue;    // Queue of vertices to be processed
 
    VertexQueue.push_back(start);
    // Start processing with the
    // starting vertex
 
    while (!VertexQueue.empty())    // While there are vertices to be processed
    {
        int newVertex = VertexQueue.front();
        // The first vertex in queue
 
        itr = adjacencyList[newVertex].begin();
        // To explore all the vertices adjacent to it
 
        while (itr != adjacencyList[newVertex].end()) {
            if (level[*itr] == -1) {            // This is an unvisited vertex
                level[*itr] = level[newVertex] + 1;         // Set level
                parent[*itr] = newVertex;       // Set parent
                VertexQueue.push_back(*itr);    // Add it to the queue
            }
            ++itr;
        }
 
        VertexQueue.pop_front();    // Pop out the processed vertex
    }
}
 
int main()
{
    int vertices, edges, v1, v2, weight;
 
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
 
    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);
 
    // Adjacency List is a vector of lists.
    vector< list<int> > adjacencyList(vertices + 1);
 
    printf("Enter the Edges V1 -> V2\n");
 
    for (int i = 1; i <= edges; ++i) {
        scanf("%d%d", &v1, &v2);
 
        // Adding Edges
        adjacencyList[v1].push_back(v2);
    }
 
    printf("\nThe Adjacency List-\n");
    // Printing Adjacency List
    for (int i = 1; i < adjacencyList.size(); ++i) {
        printf("adjacencyList[%d] ", i);
 
        list<int>::iterator itr = adjacencyList[i].begin();
 
        while (itr != adjacencyList[i].end()) {
            printf(" -> %d", *itr);
            ++itr;
        }
        printf("\n");
    }
 
    int parent[vertices + 1];
    // Each element of Parent Array holds the Node value of its parent
    int level[vertices + 1];
    // Each element of Level Array holds the Level value of that node
 
    for (int i = 0; i <= vertices; ++i) {
        //Initialising our arrays
        parent[i] = 0;
        level[i] = -1;
    }
 
    printf("\nEnter the Starting Vertex -\n");
    scanf("%d", &v1);
 
    breadthFirstSearch(adjacencyList, parent, level, v1);
 
    // Level Array
    printf("\nLevel and Parent Arrays -\n");
    for (int i = 1; i <= vertices; ++i) {
        printf("Level of Node %d is %d, Parent is %d\n", i, level[i], parent[i]);
    }
 
    return 0;
}
