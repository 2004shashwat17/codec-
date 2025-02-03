#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int>* adj; // Adjacency List

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V]; // Initialize adjacency list
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Directed edge
    }

    bool isCycle(int src, vector<bool>& vis, vector<bool>& rec) {
        vis[src] = true;
        rec[src] = true;

        for (int v : adj[src]) { // Traverse neighbors
            if (!vis[v]) {
                if (isCycle(v, vis, rec)) {
                    return true;
                }
            } else if (rec[v]) { // If it's in the recursion stack, cycle detected
                return true;
            }
        }

        rec[src] = false; // Backtrack
        return false;
    }

    bool canFinish() {
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, rec)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Graph graph(2);
    graph.addEdge(1, 0);
    graph.addEdge(0, 1);

    if (graph.canFinish()) {
        cout << "No cycle detected. All courses can be finished.\n";
    } else {
        cout << "Cycle detected! Courses cannot be finished.\n";
    }
    return 0;
}
