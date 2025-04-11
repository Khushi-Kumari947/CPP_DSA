#include <iostream>
#include <limits> // For numeric_limits
using namespace std;

// Define INF globally
const int INF = numeric_limits<int>::max(); // This is the largest value for int

class Graph {
public:
    int** memo;
    int numVertices;

    Graph(int vertices) {
        numVertices = vertices;
        memo = new int*[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            memo[i] = new int[numVertices];
            for (int j = 0; j < numVertices; ++j) {
                if (i == j) {
                    memo[i][j] = 0; // Distance from a vertex to itself is 0
                } else {
                    memo[i][j] = INF; // No direct edge, so set to INF
                }
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        memo[u][v] = weight;
    }
};

class AllPairsShortestPath {
public:
    int** memo;
    int numVertices;

    AllPairsShortestPath(Graph& graph) {
        numVertices = graph.numVertices;
        memo = new int*[numVertices];

        // Copy the graph's adjacency matrix to the memo matrix
        for (int i = 0; i < numVertices; ++i) {
            memo[i] = new int[numVertices];
            for (int j = 0; j < numVertices; ++j) {
                memo[i][j] = graph.memo[i][j];
            }
        }

        // Apply the Floyd-Warshall algorithm
        for (int k = 0; k < numVertices; ++k) {
            for (int i = 0; i < numVertices; ++i) {
                for (int j = 0; j < numVertices; ++j) {
                    if (memo[i][k] != INF && memo[k][j] != INF) {
                        memo[i][j] = min(memo[i][j], memo[i][k] + memo[k][j]);
                    }
                }
            }
        }
    }

    void printShortestPaths() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (memo[i][j] == INF) {
                    cout << "INF "; // Print INF for unreachable vertices
                } else {
                    cout << memo[i][j] << " "; // Print the shortest path weight
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 4;
    Graph graph(vertices);
    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 1, 6);

    AllPairsShortestPath apsp(graph);

    cout << "All Pairs Shortest Paths:\n";
    apsp.printShortestPaths();

    return 0;
}
