#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS function to check for odd-length cycles
    bool dfs(int node, vector<int>& visited, int parent, int depth) {
        visited[node] = depth; // Mark visited with depth

        for (int neighbor : adj[node]) {
            if (visited[neighbor] == -1) {
                if (!dfs(neighbor, visited, node, depth + 1))
                    return false;
            } else if (neighbor != parent) {
                // If back edge found, check cycle length
                if ((depth - visited[neighbor]) % 2 == 0)
                    return false; // Odd-length cycle found
            }
        }
        return true;
    }

    bool isBipartite() {
        vector<int> visited(V, -1); // -1 means unvisited

        for (int i = 0; i < V; i++) {
            if (visited[i] == -1) {
                if (!dfs(i, visited, -1, 0))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    cout << (graph.isBipartite() ? "Yes, the graph is Bipartite" : "No, the graph is not Bipartite") << endl;

    return 0;
}
