#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v) : vertices(v) {
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // For undirected graph
    }

    void primsAlgorithm() {
        vector<int> key(vertices, INT_MAX);
        vector<bool> inMST(vertices, false);
        vector<int> parent(vertices, -1);

        key[0] = 0;

        for (int count = 0; count < vertices - 1; ++count) {
            int u = -1;
            for (int i = 0; i < vertices; ++i) {
                if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }

            inMST[u] = true;
            for (int v = 0; v < vertices; ++v) {
                if (adjMatrix[u][v] != 0 && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }
        cout << "Edge \tWeight\n";
        for (int i = 1; i < vertices; ++i) {
            cout << parent[i] << " - " << i << " \t" << adjMatrix[parent[i]][i] << "\n";
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g(vertices);
    cout << "Enter the edges in the format (u v weight):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
    g.primsAlgorithm();

    return 0;
}
