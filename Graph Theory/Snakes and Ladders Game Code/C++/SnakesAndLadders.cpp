/* ===== ===== =====

Theory of Programming

Solving Snakes and Ladders game using BFS
http://theoryofprogramming.com/2014/12/25/snakes-and-ladders-game-code/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <algorithm>
#include <cstdio>
#include <vector>
#include <list>
#include <utility>

using namespace std;

void replaceEdgeFor6PreceedingVertices(vector< list<int> >& adjacencyList, int startVertex, int oldEdge, int newEdge)
{
    // For the 6 vertices preceeding 'startVertex' do the edge replacement
    for (int i = startVertex - 1; i >= startVertex - 6 && i > 0; --i) {
        std::replace(adjacencyList[i].begin(), adjacencyList[i].end(), oldEdge, newEdge);
    }
}

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

void breadthFirstSearch(vector< list<int> > adjacencyList, int parent[], int level[], int start)
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
    int vertices = 100;

    // Creating an Adjacency List of size 100
    vector< list<int> > adjacencyList(vertices + 1);

    // Populate the Adjacency List with edges representing
    // the 6 possible moves from each vertex.
    for (int i = 1; i <= vertices; ++i) {
        for (int j = i + 1; j <= i + 6 && j <= vertices; ++j) {
            adjacencyList[i].push_back(j);
        }
    }

    char temp; // To scan space between integers
    int numOfLadders, numOfSnakes;

    printf("Enter number of ladders -\n");
    scanf("%d", &numOfLadders);
    printf("Enter the ladder which goes from V1 -> V2\n");

    for (int i = 1; i <= numOfLadders; ++i) {
        int v1, v2;

        scanf("%d%c%d", &v1, &temp, &v2);
        replaceEdgeFor6PreceedingVertices(adjacencyList, v1 /* startVertex */, v1 /* oldEdge */, v2 /* newEdge */);

        // Edges associated with v1 can be removed
        adjacencyList[v1].clear();
    }

    printf("Enter number of snakes -\n");
    scanf("%d", &numOfSnakes);
    printf("Enter the snake which goes from V1 -> V2\n");

    for (int i = 1; i <= numOfSnakes; ++i) {
        int v1, v2;

        scanf("%d%c%d", &v1, &temp, &v2);
        replaceEdgeFor6PreceedingVertices(adjacencyList, v1 /* startVertex */, v1 /* oldEdge */, v2 /* newEdge */);

        // Edges associated with v1 can be removed
        adjacencyList[v1].clear();
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

    // The regular BFS stuff below
    int parent[vertices + 1];
    int level[vertices + 1];

    // Initialising our arrays
    for (int i = 0; i <= vertices; ++i) {
        parent[i] = -1;
        level[i] = -1;
    }

    breadthFirstSearch(adjacencyList, parent, level, 1); // Main BFS method

    // Level of the 100th vertex would be the minimum number
    // of moves requried to finish the game.
    printf("\nMinimum number of moves required to finish the game = %d\n", level[100]);

    // Print path from Vertex 1 to Vertex 100
    printf("Shortest path to finish the game = ");
    printPathFromSourceToDestination(parent, 100);
    printf("\n");

    return 0;
}
