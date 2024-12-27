#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
private:
    int vertices;
    vector<Edge> edges;

    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }

    void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

public:
    Graph(int v) : vertices(v) {}

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    void kruskalMinimalSpanningTree() {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });

        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);

        for (int i = 0; i < vertices; ++i) {
            parent[i] = i;
        }

        vector<Edge> mst;
        int mstWeight = 0;

        for (const auto& edge : edges) {
            if (findParent(edge.src, parent) != findParent(edge.dest, parent)) {
                mst.push_back(edge);
                mstWeight += edge.weight;
                unionNodes(edge.src, edge.dest, parent, rank);
            }
        }

        cout << "Edges in the Minimal Spanning Tree:\n";
        for (const auto& edge : mst) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }
        cout << "Total weight of MST: " << mstWeight << endl;
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

    cout << "\nMinimal Spanning Tree (Kruskal's Algorithm):\n";
    g.kruskalMinimalSpanningTree();

    return 0;
}
