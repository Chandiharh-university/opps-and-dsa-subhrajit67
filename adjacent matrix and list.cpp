#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

    void createAdjList() {
        adjList.clear();
        adjList.resize(vertices);
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (adjMatrix[i][j] == 1) {
                    adjList[i].push_back(j);
                }
            }
        }
    }

public:
    Graph(int v) : vertices(v) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        } else {
            cout << "Invalid edge!" << endl;
        }
    }

    void displayAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void displayAdjList() {
        createAdjList();
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < adjList.size(); ++i) {
            cout << i << ": ";
            for (int val : adjList[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    graph.displayAdjMatrix();
    graph.displayAdjList();

    return 0;
}
