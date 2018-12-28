/* ===== ===== =====

Theory of Programming

Breadth First Search Algorithm using (STL) Queue
http://theoryofprogramming.com/2014/12/25/breadth-first-search-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <cstdio>
#include <vector>
#include <list>
#include <utility>

using namespace std;

void printPathFromSourceToDestination(int parent[], int destination)
{
    if (parent[destination] == -1) {
        // We have reached the source vertex
        printf("%d -> ", destination);
    } else {
        printPathFromSourceToDestination(parent, parent[destination]);
        printf("%d -> ", destination);
    }
}

void breadthFirstSearch(vector<list<int> > adjacencyList, int parent[], int level[], int start)
{
    list<int>::iterator itr;

    // Level of start vertex will be 0, the level of all its adjcent
    // vertices will be 1, their adjacent vertices will be 2, and so on
    level[start] = 0;

    list<int> queue; // Queue of vertices to be processed

    queue.push_back(start); // Add start vertex to the queue

    while (!queue.empty()) // While there are vertices to be processed
    {
        // Get the first vertex in the queue.
        // Note - .front() does not remove the front element.
        int newVertex = queue.front();
 
        // Iterator to explore all the vertices adjacent to it
        itr = adjacencyList[newVertex].begin();
 
        while (itr != adjacencyList[newVertex].end()) {
            if (level[*itr] == -1) {                // Check if it is an unvisited vertex
                level[*itr] = level[newVertex] + 1; // Set level of adjacent vertex
                parent[*itr] = newVertex;           // Set parent of adjacent vertex
                queue.push_back(*itr);              // Add the adjacent vertex to queue
            }

            ++itr;
        }

        queue.pop_front(); // Pop out the processed vertex
    }
}
 
int main()
{
    int vertices, edges, v1, v2, weight, source, destination;

    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);

    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);

    // Creating an Adjacency List which is a vector of list of ints
    vector< list<int> > adjacencyList(vertices + 1);

    printf("Enter the Edges V1 <-> V2\n");

    for (int i = 1; i <= edges; ++i) {
        scanf("%d%d", &v1, &v2);

        // Adding Edges (this will be an undirected graph)
        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1);
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
    int level[vertices + 1];

    // Initialising our arrays
    for (int i = 0; i <= vertices; ++i) {
        parent[i] = -1;
        level[i] = -1;
    }

    printf("\nEnter the Starting Vertex -\n");
    scanf("%d", &source);

    breadthFirstSearch(adjacencyList, parent, level, source); // Main BFS method

    // Print level and parent arrays
    printf("\nLevel and Parent Arrays -\n");
    for (int i = 1; i <= vertices; ++i) {
        printf("Level of Vertex %d is %d, Parent is %d\n", i, level[i], parent[i]);
    }

    printf("\nEnter any destination vertex to print the shortest path from Vertex %d-\n", source);
    scanf("%d", &destination);

    printPathFromSourceToDestination(parent, destination);
    printf("\n");

    return 0;
}