#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    ~Graph() {
        delete[] l;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (isUndir)
            l[v].push_back(u);
    }

    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << " : ";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool dirCycleHelper(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                if (dirCycleHelper(v, vis, recPath)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true;
            }
        }

        recPath[src] = false; // Backtrack
        return false;
    }

    bool isCycleDir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dirCycleHelper(i, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // Directed graph
    Graph graph(4, false); // Initialize as directed graph (isUndir = false)
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout << "Graph Adjacency List:" << endl;
    graph.print();

    cout << "Cycle in directed graph: " << (graph.isCycleDir() ? "Yes" : "No") << endl;

    return 0;
}
