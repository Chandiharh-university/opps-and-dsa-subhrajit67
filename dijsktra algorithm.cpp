#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList; 
public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    void dijkstra(int start) {
        vector<int> distance(vertices, INT_MAX);
        distance[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start); 
        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentDist > distance[currentNode]) {
                continue;
            }

            for (auto& neighbor : adjList[currentNode]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (distance[currentNode] + edgeWeight < distance[nextNode]) {
                    distance[nextNode] = distance[currentNode] + edgeWeight;
                    pq.emplace(distance[nextNode], nextNode);
                }
            }
        }

        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "Node " << i << " : " << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << endl;
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

    int start;
    cout << "Enter the starting node for Dijkstra's algorithm: ";
    cin >> start;

    g.dijkstra(start);

    return 0;
}
