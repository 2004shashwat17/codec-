#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int>* l; // Adjacency list
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool hasPathBFS(int src, int dest) {
        if (src == dest) {
            return true;
        }

        vector<bool> vis(V, false); // To track visited nodes
        queue<int> q;

        // Start BFS from the source node
        q.push(src);
        vis[src] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Check all neighbors of the current node
            for (int v : l[u]) {
                if (v == dest) {
                    return true; // Path found
                }
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false; // No path found
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    cout << graph.hasPathBFS(0, 5) << endl; // Output: 1 (true)
    cout << graph.hasPathBFS(0, 6) << endl; // Output: 1 (true)
    cout << graph.hasPathBFS(0, 10) << endl; // Output: 0 (false - vertex 10 does not exist)
    return 0;
}
