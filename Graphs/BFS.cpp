#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *l; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // BFS traversal
    void bfs(int start) {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int u = q.front(); // Current vertex
            q.pop();
            cout << u << " ";

            for (int v : l[u]) { // For all neighbors of u
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // Print adjacency list
    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << ":";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(7); // Adjusted for 7 vertices (0 to 6)

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    cout << "Adjacency List:" << endl;
    graph.print();

    cout << "\nBFS Traversal starting from vertex 0:" << endl;
    graph.bfs(0);

    return 0;
}
